/*
 * Copyright (c) 2012-2021 Belledonne Communications SARL.
 *
 * This file is part of belle-sip.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <regex>

#include "bctoolbox/utils.hh"

#include "belle-sip/potential_config_graph.hh"
#include "belle-sip/object.h"
#include "belle-sip/types.h"

bellesip::SDP::SDPPotentialCfgGraph::SDPPotentialCfgGraph () {

}

bellesip::SDP::SDPPotentialCfgGraph::SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc) : SDPPotentialCfgGraph() {
	processSessionDescription(session_desc);
}

std::string bellesip::SDP::capabilityToAttributeName(const bellesip::SDP::capability_type_t cap) {
	std::string cap_name;
	switch (cap) {
		case bellesip::SDP::capability_type_t::ATTRIBUTE:
			cap_name = "acap";
			break;
		case bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL:
			cap_name = "tcap";
			break;
		case bellesip::SDP::capability_type_t::EXTENDED:
			cap_name = "ecap";
			break;
	}
	return cap_name;
}

/*
 * Session
 */
void bellesip::SDP::SDPPotentialCfgGraph::processSessionDescription (const belle_sdp_session_description_t* session_desc) {
	globalAcap = getSessionDescriptionACapabilities(session_desc);
	globalTcap = getSessionDescriptionTCapabilities(session_desc);
	int mediaIdx = 0;
	for ( auto media_desc_it=belle_sdp_session_description_get_media_descriptions ( session_desc ); media_desc_it!=NULL; media_desc_it=media_desc_it->next ) {
		const belle_sdp_media_description_t* media_desc=BELLE_SDP_MEDIA_DESCRIPTION ( media_desc_it->data );
		processMediaDescription(mediaIdx, media_desc);
		mediaIdx++;
	}


	if (!acfg.empty() && !pcfg.empty()) {
		belle_sip_error("The provided sdp is not valid because it defines %0u attribute configurations and %0u potential configurations - pcfg attrbutes are allowed in offers and acfg attributes in answers ", static_cast<unsigned int>(acfg.size()), static_cast<unsigned int>(pcfg.size()));
	}
}

const belle_sip_list_t * bellesip::SDP::SDPPotentialCfgGraph::getSessionCapabilityAttributes(const belle_sdp_session_description_t* session_desc, const bellesip::SDP::capability_type_t cap) {
	const std::string cap_name(bellesip::SDP::capabilityToAttributeName(cap));
	return belle_sdp_session_description_find_attributes_with_name(session_desc, cap_name.c_str());
}

/*
 * Media
 */
void bellesip::SDP::SDPPotentialCfgGraph::processMediaDescription(const unsigned int & idx, const belle_sdp_media_description_t* media_desc) {
	// ACAP
	// Get capabilities specific to the media description
	auto mediaAcap = getMediaDescriptionACapabilities(media_desc);
	// add media capabilities defined in the media lines to acap vector
	if (!mediaAcap.empty()) {
		acap[idx] = mediaAcap;
	}

	// TCAP
	// Get capabilities specific to the media description
	auto mediaTcap = getMediaDescriptionTCapabilities(media_desc);
	// add media capabilities to tcap vector
	// add media capabilities defined in the media lines to tcap vector
	if (!mediaTcap.empty()) {
		tcap[idx] = mediaTcap;
	}

	// ACFG
	processMediaCfg(idx, media_desc, bellesip::SDP::config_type::ACFG);

	// PCFG
	processMediaCfg(idx, media_desc, bellesip::SDP::config_type::PCFG);
}

const belle_sip_list_t * bellesip::SDP::SDPPotentialCfgGraph::getMediaCapabilityAttributes(const belle_sdp_media_description_t* media_desc, const bellesip::SDP::capability_type_t cap) {
	const std::string cap_name(bellesip::SDP::capabilityToAttributeName(cap));
	return belle_sdp_media_description_find_attributes_with_name(media_desc, cap_name.c_str());
}

/*
 * Attribute capabilities
 */
bellesip::SDP::SDPPotentialCfgGraph::media_description_acap bellesip::SDP::SDPPotentialCfgGraph::getSessionDescriptionACapabilities (const belle_sdp_session_description_t* session_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::ATTRIBUTE;
	const belle_sip_list_t * caps_attr = getSessionCapabilityAttributes(session_desc, cap);
	return createACapabilitiesList(caps_attr, cap);
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_acap bellesip::SDP::SDPPotentialCfgGraph::createACapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap) {
	bellesip::SDP::SDPPotentialCfgGraph::media_description_acap caps;
	for(;caps_attr!=NULL;caps_attr=caps_attr->next){
		belle_sdp_acap_attribute_t* lAttribute = static_cast<belle_sdp_acap_attribute_t*>(caps_attr->data);
		std::shared_ptr<acapability> elem = std::make_shared<acapability>();
		elem->index = belle_sdp_acap_attribute_get_id(lAttribute);
		elem->name = static_cast<const char *>(belle_sdp_acap_attribute_get_name(lAttribute));
		elem->value = static_cast<const char *>(belle_sdp_acap_attribute_get_value(lAttribute));
		elem->type = cap;
		caps.push_back(elem);
	}
	return caps;
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_acap bellesip::SDP::SDPPotentialCfgGraph::getMediaDescriptionACapabilities (const belle_sdp_media_description_t* media_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::ATTRIBUTE;
	const belle_sip_list_t * caps_attr = getMediaCapabilityAttributes(media_desc, cap);
	return createACapabilitiesList(caps_attr, cap);
}

/*
 * Transport capabilities
 */
bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getSessionDescriptionTCapabilities (const belle_sdp_session_description_t* session_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	const belle_sip_list_t * caps_attr = getSessionCapabilityAttributes(session_desc, cap);
	return createTCapabilitiesList(caps_attr, cap);
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::createTCapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap) {
	bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap caps;
	for(;caps_attr!=NULL;caps_attr=caps_attr->next){
		belle_sdp_tcap_attribute_t* lAttribute = static_cast<belle_sdp_tcap_attribute_t*>(caps_attr->data);
		int id = belle_sdp_tcap_attribute_get_id(lAttribute);
		const belle_sip_list_t *list = belle_sdp_tcap_attribute_get_protos(lAttribute);
		for(; list!=NULL; list=list->next){
			std::shared_ptr<capability> elem = std::make_shared<capability>();
			elem->index = id;
			elem->value = static_cast<const char *>(list->data);
			elem->type = cap;
			id++;
			caps.push_back(elem);
		}
	}
	return caps;
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getMediaDescriptionTCapabilities (const belle_sdp_media_description_t* media_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	const belle_sip_list_t * caps_attr = getMediaCapabilityAttributes(media_desc, cap);
	return createTCapabilitiesList(caps_attr, cap);
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaCfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc, const bellesip::SDP::config_type_t cfgType) {
	switch (cfgType) {
		case bellesip::SDP::config_type_t::ACFG:
			processMediaACfg(idx, media_desc);
			break;
		case bellesip::SDP::config_type_t::PCFG:
			processMediaPCfg(idx, media_desc);
			break;
	}
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaACfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc) {
	belle_sip_list_t * attrs = belle_sdp_media_description_find_attributes_with_name(media_desc, "acfg");
	media_description_config config;
	for(;attrs!=NULL;attrs=attrs->next){
		belle_sdp_acfg_attribute_t* lAttribute = static_cast<belle_sdp_acfg_attribute_t*>(attrs->data);
		auto id = belle_sdp_acfg_attribute_get_id(lAttribute);

		const auto mediaAcap = getAllAcapForStream(idx);
		const auto mediaTcap = getAllTcapForStream(idx);
		auto attr_configs = createAConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
		if (attr_configs.empty()) {
			belle_sip_error("Unable to build a potential config for id %0d", id);
		} else {
			config[id] = attr_configs;
		}
	}

	if (!config.empty()) {
		acfg[idx] = config;
	}
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaPCfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc) {
	belle_sip_list_t * attrs = belle_sdp_media_description_find_attributes_with_name(media_desc, "pcfg");
	media_description_config config;
	for(;attrs!=NULL;attrs=attrs->next){
		belle_sdp_pcfg_attribute_t* lAttribute = static_cast<belle_sdp_pcfg_attribute_t*>(attrs->data);
		auto id = belle_sdp_pcfg_attribute_get_id(lAttribute);

		const auto mediaAcap = getAllAcapForStream(idx);
		const auto mediaTcap = getAllTcapForStream(idx);
		auto attr_configs = createPConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
		if (attr_configs.empty()) {
			belle_sip_error("Unable to build a potential config for id %0d", id);
		} else {
			config[id] = attr_configs;
		}
	}

	if (!config.empty()) {
		pcfg[idx] = config;
	}
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_config::mapped_type bellesip::SDP::SDPPotentialCfgGraph::createPConfigFromAttribute(belle_sdp_pcfg_attribute_t* attribute, const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap & mediaAcap, const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & mediaTcap) {
	const belle_sip_list_t* configList = belle_sdp_pcfg_attribute_get_configs(attribute);
	return processConfig(configList, mediaAcap, mediaTcap);
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_config::mapped_type bellesip::SDP::SDPPotentialCfgGraph::createAConfigFromAttribute(belle_sdp_acfg_attribute_t* attribute, const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap & mediaAcap, const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & mediaTcap) {
	const belle_sip_list_t* configList = belle_sdp_acfg_attribute_get_configs(attribute);
	return processConfig(configList, mediaAcap, mediaTcap);
}

bellesip::SDP::SDPPotentialCfgGraph::media_description_config::mapped_type bellesip::SDP::SDPPotentialCfgGraph::processConfig(const belle_sip_list_t* configList, const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap & mediaAcap, const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & mediaTcap) const {
	const belle_sip_list_t* list = configList;
	bellesip::SDP::SDPPotentialCfgGraph::media_description_config::mapped_type attr_configs;

	bool delete_media_attributes = false;
	bool delete_session_attributes = false;

	std::list<std::list<bellesip::SDP::config_capability<acapability>>> acapCfgList;
	std::list<std::list<bellesip::SDP::config_capability<capability>>> tcapCfgList;

	// Collects all the capacity configuration sets (acap and tcap indexes) and store them in lists.
	// After all possible configs are created by creating a configuration attribute with each pair of <acap,tcap> lists with their delete attributes
	// For example:
	// a=pcfg:1 t=1|4 a=1,5|3
	// acap list will have 2 elements: 1,5 and 3
	// tcap list will have 2 elements: 1 and 4
	// The configuration has therefore 4 possible pairs:
	// a=1,5 ad t=1
	// a=1,5 ad t=4
	// a=3 ad t=1
	// a=3 ad t=4
	for(;list!=NULL;list=list->next){
		std::string cfg = static_cast<const char*>(list->data);
		belle_sip_message("configuration is %s", cfg.c_str());
		// Valid formats for the configuration string:
		// - <char>=-<char>:<pipe separated list of configs>
		// - <char>=-<char><char>:<pipe separated list of configs>
		// - <char>=<pipe separated list of configs>

		// Split at the = sign
		const char bodyDelim = '=';
		const auto bodySplit = bctoolbox::Utils::split(cfg, bodyDelim);

		if (bodySplit.size() < 2) {
			belle_sip_error("size of the vector after splitting using delimiter %c is %lu", bodyDelim, bodySplit.size());
			return attr_configs;
		}

		// First element is the type of capability
		auto capType = bodySplit.front();
		const bellesip::SDP::capability_type_t cap = capabilityTypeFromAttrParam(capType);

		// last element is the body of the attribute
		auto attrBody = bodySplit.back();
		belle_sip_message("configuration type is %s and body is %s", capType.c_str(), attrBody.c_str());

		const char deleteAttrDelim = ':';
		const auto deleteAttrSplit = bctoolbox::Utils::split(attrBody, deleteAttrDelim);

		// last element is the list of configs
		auto idxList = deleteAttrSplit.back();
		belle_sip_message("configuration list is %s", idxList.c_str());

		// Only one attribute and one transport capacity is allowed in the config line - hence if acap or tcap has been parsed and trying to add another one, print an error
		if (cap == bellesip::SDP::capability_type_t::ATTRIBUTE) {
			if (acapCfgList.empty()) {
				auto parsedList = parseIdxList(idxList, mediaAcap);
				// Add only if list is not empty
				if (!parsedList.empty()) {
					acapCfgList = parsedList;
				}

				// Delete attribute is only in the acfg attribute
				if (bodySplit.size() > 1) {
					// First element is the delete attribute
					auto deleteAttr = deleteAttrSplit.front();
					delete_media_attributes = (deleteAttr.find('m') != std::string::npos);
					delete_session_attributes = (deleteAttr.find('s') != std::string::npos);
				} else {
					delete_media_attributes = false;
					delete_session_attributes = false;
				}
			} else {
				belle_sip_error("Ignoring second attribute configuration list %s has been found in the configuration because already %0ld elements have been collected", cfg.c_str(), acapCfgList.size());
			}
		} else if (cap == bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL) {
			if (tcapCfgList.empty()) {
				auto parsedList = parseIdxList(idxList, mediaTcap);
				// Add only if list is not empty
				if (!parsedList.empty()) {
					tcapCfgList = parsedList;
				}
			} else {
				belle_sip_error("Ignoring second transport configuration list %s has been found in the configuration because already %0ld elements have been collected", cfg.c_str(), tcapCfgList.size());
			}
		}
	}

	// Create configs by creating all possible pairs of <acap,tcap> lists
	if ((tcapCfgList.empty()) || (acapCfgList.empty())) {
		belle_sip_error("Unable to build a valid config because no valid list of capacities has been found - acap list is %s tcap list is %s", (acapCfgList.empty() ? "empty " : "not empty "), (tcapCfgList.empty() ? "empty " : "not empty "));
	} else {
		for (const auto & acapCfg : acapCfgList) {
			for (const auto & tcapCfg : tcapCfgList) {
				bellesip::SDP::config_attribute cfg;
				cfg.acap = acapCfg;
				cfg.tcap = tcapCfg;
				cfg.delete_media_attributes = delete_media_attributes;
				cfg.delete_session_attributes = delete_session_attributes;
				attr_configs.push_back(cfg);
			}
		}
	}
	return attr_configs;
}

bellesip::SDP::capability_type_t bellesip::SDP::SDPPotentialCfgGraph::capabilityTypeFromAttrParam(const std::string & attrParam) const {
	if (attrParam.compare("a") == 0) {
		return bellesip::SDP::capability_type_t::ATTRIBUTE;
	} else if (attrParam.compare("t") == 0) {
		return bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	}
	return bellesip::SDP::capability_type_t::EXTENDED;
}

int bellesip::SDP::SDPPotentialCfgGraph::getElementIdx(const std::string & index) const {
	std::regex indexRegex("(\\d+)");
	auto indexBegin = std::sregex_iterator(index.begin(), index.end(), indexRegex);
	auto indexEnd = std::sregex_iterator();

	if (indexBegin == indexEnd) {
		belle_sip_message("Unable to find index in string %s ", index.c_str());
	}

	auto noMatches = std::distance(indexBegin, indexEnd);
	if (noMatches > 1) {
		belle_sip_error("Expected one match but found %0ld instead - only first match will be honored", noMatches);
	}

	std::smatch match = *indexBegin;
	return std::stoi(match.str());
}

const bellesip::SDP::SDPPotentialCfgGraph::session_description_config & bellesip::SDP::SDPPotentialCfgGraph::getAllAcfg() const {
	return acfg;
}
const bellesip::SDP::SDPPotentialCfgGraph::session_description_config & bellesip::SDP::SDPPotentialCfgGraph::getAllPcfg() const {
	return pcfg;
}
const bellesip::SDP::SDPPotentialCfgGraph::session_description_acap & bellesip::SDP::SDPPotentialCfgGraph::getAllAcap() const {
	return acap;
}
const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap & bellesip::SDP::SDPPotentialCfgGraph::getAllTcap() const {
	return tcap;
}

const bellesip::SDP::SDPPotentialCfgGraph::media_description_config & bellesip::SDP::SDPPotentialCfgGraph::getAcfgForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & idx) const {
	try {
		const auto & cfg = acfg.at(idx);
		return cfg;
	} catch (const std::out_of_range& e) {
		belle_sip_error("Unable to find attribute configuration at index %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_config>();
	}
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_config & bellesip::SDP::SDPPotentialCfgGraph::getPcfgForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & idx) const {
	try {
		const auto & cfg = pcfg.at(idx);
		return cfg;
	} catch (const std::out_of_range& e) {
		belle_sip_error("Unable to find potential configuration at index %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_config>();
	}
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap & bellesip::SDP::SDPPotentialCfgGraph::getGlobalAcap() const {
	return globalAcap;
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & bellesip::SDP::SDPPotentialCfgGraph::getGlobalTcap() const {
	return globalTcap;
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap & bellesip::SDP::SDPPotentialCfgGraph::getMediaAcapForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_acap::key_type & idx) const {
	try {
		const auto & cap = acap.at(idx);
		return cap;
	} catch (const std::out_of_range& e) {
		belle_sip_error("Unable to find capability at index %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_acap>();
	}
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & bellesip::SDP::SDPPotentialCfgGraph::getMediaTcapForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap::key_type & idx) const {
	try {
		const auto & cap = tcap.at(idx);
		return cap;
	} catch (const std::out_of_range& e) {
		belle_sip_error("Unable to find transport capability at index %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap>();
	}
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap bellesip::SDP::SDPPotentialCfgGraph::getAllAcapForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_acap::key_type & idx) const {
	auto acaps = getMediaAcapForStream(idx);
	auto globalAcaps = getGlobalAcap();
	acaps.insert(acaps.end(), globalAcaps.begin(), globalAcaps.end());
	return acaps;
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getAllTcapForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap::key_type & idx) const {
	auto tcaps = getMediaTcapForStream(idx);
	auto globalTcaps = getGlobalTcap();
	tcaps.insert(tcaps.end(), globalTcaps.begin(), globalTcaps.end());
	return tcaps;
}

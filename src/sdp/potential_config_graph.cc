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

#include "belle-sip/potential_config_graph.hh"
#include "belle-sip/object.h"
#include "belle-sip/types.h"

bellesip::SDP::SDPPotentialCfgGraph::SDPPotentialCfgGraph () {

}

bellesip::SDP::SDPPotentialCfgGraph::SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc) : SDPPotentialCfgGraph() {
	processSessionDescription(session_desc);
}

bellesip::SDP::SDPPotentialCfgGraph & bellesip::SDP::SDPPotentialCfgGraph::operator= (const bellesip::SDP::SDPPotentialCfgGraph & other) {
	globalAcap = other.globalAcap;
	globalTcap = other.globalTcap;
	cfgs = other.cfgs;
	acap = other.acap;
	tcap = other.tcap;

	return *this;
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
	const auto acfgFound = processMediaCfg(idx, media_desc, bellesip::SDP::config_type::ACFG);

	// PCFG
	const auto pcfgFound = processMediaCfg(idx, media_desc, bellesip::SDP::config_type::PCFG);

	if (acfgFound && pcfgFound) {
		belle_sip_error("The provided sdp is not valid because it defines both attribute configurations and potential configurations - pcfg attrbutes are allowed in offers and acfg attributes in answers ");
	}
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
	auto capList = createACapabilitiesList(caps_attr, cap);
	belle_sip_list_free_with_data(const_cast<belle_sip_list_t *>(caps_attr), (void (*)(void*))belle_sip_object_unref);
	return capList;
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
	auto capList = createACapabilitiesList(caps_attr, cap);
	belle_sip_list_free_with_data(const_cast<belle_sip_list_t *>(caps_attr), (void (*)(void*))belle_sip_object_unref);
	return capList;
}

/*
 * Transport capabilities
 */
bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getSessionDescriptionTCapabilities (const belle_sdp_session_description_t* session_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	const belle_sip_list_t * caps_attr = getSessionCapabilityAttributes(session_desc, cap);
	auto capList = createTCapabilitiesList(caps_attr, cap);
	belle_sip_list_free_with_data(const_cast<belle_sip_list_t *>(caps_attr), (void (*)(void*))belle_sip_object_unref);
	return capList;
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
	auto capList = createTCapabilitiesList(caps_attr, cap);
	belle_sip_list_free_with_data(const_cast<belle_sip_list_t *>(caps_attr), (void (*)(void*))belle_sip_object_unref);
	return capList;
}

bool bellesip::SDP::SDPPotentialCfgGraph::processMediaCfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc, const bellesip::SDP::config_type_t cfgType) {
	bool found = false;
	switch (cfgType) {
		case bellesip::SDP::config_type_t::ACFG:
			found = processMediaAcfg(idx, media_desc);
			break;
		case bellesip::SDP::config_type_t::PCFG:
			found = processMediaPcfg(idx, media_desc);
			break;
	}

	return found;
}

bool bellesip::SDP::SDPPotentialCfgGraph::processMediaAcfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc) {
	belle_sip_list_t * attrs = belle_sdp_media_description_find_attributes_with_name(media_desc, "acfg");
	media_description_unparsed_config unparsed_config;
	media_description_config config;
	const auto mediaAcap = getAllAcapForStream(idx);
	const auto mediaTcap = getAllTcapForStream(idx);
	for(belle_sip_list_t * attr = attrs;attr!=NULL;attr=attr->next){
		belle_sdp_acfg_attribute_t* lAttribute = static_cast<belle_sdp_acfg_attribute_t*>(attr->data);
		auto id = belle_sdp_acfg_attribute_get_id(lAttribute);

		auto attr_configs = createAConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
		if (attr_configs.acap.empty() && attr_configs.tcap.empty()) {
			belle_sip_error("Unable to build a potential config for id %0d because lists of attribute and transport capabilities are empty", id);
			
			char * attrString = belle_sip_object_to_string(lAttribute);
			unparsed_config[id] = attrString;
			belle_sip_free(attrString);
		} else {
			config[id] = attr_configs;
		}
	}

	belle_sip_list_free_with_data(attrs, (void (*)(void*))belle_sip_object_unref);

	bool found = false;
	if (!config.empty()) {
		found = true;
		cfgs[idx] = config;
	}
	if (!unparsed_config.empty()) {
		unparsed_cfgs[idx] = unparsed_config;
	}
	return found;
}

bool bellesip::SDP::SDPPotentialCfgGraph::processMediaPcfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc) {
	belle_sip_list_t * attrs = belle_sdp_media_description_find_attributes_with_name(media_desc, "pcfg");
	media_description_unparsed_config unparsed_config;
	media_description_config config;
	for(belle_sip_list_t * attr = attrs;attr!=NULL;attr=attr->next){
		belle_sdp_pcfg_attribute_t* lAttribute = static_cast<belle_sdp_pcfg_attribute_t*>(attr->data);
		auto id = belle_sdp_pcfg_attribute_get_id(lAttribute);

		const auto mediaAcap = getAllAcapForStream(idx);
		const auto mediaTcap = getAllTcapForStream(idx);
		auto attr_configs = createPConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
		if (attr_configs.acap.empty() && attr_configs.tcap.empty()) {
			belle_sip_error("Unable to build a potential config for id %0d", id);
			unparsed_config[idx] = belle_sip_object_to_string(lAttribute);
		} else {
			config[id] = attr_configs;
		}
	}

	belle_sip_list_free_with_data(attrs, (void (*)(void*))belle_sip_object_unref);

	bool found = false;
	if (!config.empty()) {
		found = true;
		cfgs[idx] = config;
	}
	if (!unparsed_config.empty()) {
		unparsed_cfgs[idx] = unparsed_config;
	}
	return found;
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
	std::list<bellesip::SDP::config_capability<capability>> tcapCfgList;
	bool acapProcessingError = false;
	bool tcapProcessingError = false;

	// Collects all the capacity configuration sets (acap and tcap indexes) and store them in lists.
	// After all possible configs are created by creating a configuration attribute with each pair of <acap,tcap> lists with their delete attributes
	// For example:
	// a=pcfg:1 t=1|4 a=1,5|3
	// acap list will have 2 elements: 1,5 and 3
	// tcap list will have 2 elements: 1 and 4
	// The configuration has therefore 4 possible pairs:
	// a=1,5 and t=1
	// a=1,5 and t=4
	// a=3 and t=1
	// a=3 and t=4
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
			belle_sip_error("size of the vector after splitting using delimiter %c is %0zu", bodyDelim, bodySplit.size());
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
				const auto parsedListPair = parseIdxList(idxList, mediaAcap);
				const auto & success = parsedListPair.second;
				const auto & parsedList = parsedListPair.first;
				// trigger error if an issue has been detected in the parsing and the generated list is empty
				acapProcessingError |= (!success && parsedList.empty());
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
				belle_sip_error("Ignoring second attribute configuration list %s has been found in the configuration because already %0zu elements have been collected", cfg.c_str(), acapCfgList.size());
			}
		} else if (cap == bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL) {
			if (tcapCfgList.empty()) {
				const auto parsedListPair = parseIdxList(idxList, mediaTcap);
				const auto & success = parsedListPair.second;
				const auto & parsedList = parsedListPair.first;
				// trigger error if an issue has been detected in the parsing and the generated list is empty
				tcapProcessingError |= (!success && parsedList.empty());
				// Add only if list is not empty
				if (!parsedList.empty()) {
					// Transport capabilities have only one element for every potential configuration.
					// The general writing is:
					// t=1|2|3
					for (const auto & tcapCfg : parsedList) {
						const auto & tcapCfgSize = tcapCfg.size();
						if (tcapCfgSize > 1) {
							belle_sip_error("Found %0zu transport protocols for a configuration. Ignoring it.", tcapCfgSize);
						} else {
							tcapCfgList.push_back(tcapCfg.front());
						}
					}
				}
			} else {
				belle_sip_error("Ignoring second transport configuration list %s has been found in the configuration because already %0zu elements have been collected", cfg.c_str(), tcapCfgList.size());
			}
		}
	}

	// If a processing error has been detected on both acap and tcap, then do not create the attribute
	const bool processingError = acapProcessingError || tcapProcessingError;

	// Create configs by creating all possible pairs of <acap,tcap> lists
	if (processingError || ((tcapCfgList.empty()) && (acapCfgList.empty()))) {
		belle_sip_error("Unable to build a valid config because no valid list of capacities has been found - error during processing %s acap list is %s tcap list is %s", (processingError ? "detected" : "not detected"), (acapCfgList.empty() ? "empty" : "not empty"), (tcapCfgList.empty() ? "empty" : "not empty"));
	} else {
		attr_configs.acap = acapCfgList;
		attr_configs.tcap = tcapCfgList;
		attr_configs.delete_media_attributes = delete_media_attributes;
		attr_configs.delete_session_attributes = delete_session_attributes;
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

unsigned int bellesip::SDP::SDPPotentialCfgGraph::getElementIdx(const std::string & index) const {
	std::regex indexRegex("(\\d+)");
	auto indexBegin = std::sregex_iterator(index.begin(), index.end(), indexRegex);
	auto indexEnd = std::sregex_iterator();

	if (indexBegin == indexEnd) {
		belle_sip_message("Unable to find index in string %s ", index.c_str());
	}

	auto noMatches = std::distance(indexBegin, indexEnd);
	if (noMatches > 1) {
		belle_sip_error("Expected one match but found %0td instead - only first match will be honored", noMatches);
	}

	std::smatch match = *indexBegin;
	return static_cast<unsigned int>(std::stoi(match.str()));
}

const bellesip::SDP::SDPPotentialCfgGraph::session_description_config & bellesip::SDP::SDPPotentialCfgGraph::getAllCfg() const {
	return cfgs;
}

const bellesip::SDP::SDPPotentialCfgGraph::session_description_unparsed_config & bellesip::SDP::SDPPotentialCfgGraph::getUnparsedCfgs() const {
	return unparsed_cfgs;
}
const bellesip::SDP::SDPPotentialCfgGraph::session_description_acap & bellesip::SDP::SDPPotentialCfgGraph::getStreamAcap() const {
	return acap;
}
const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap & bellesip::SDP::SDPPotentialCfgGraph::getStreamTcap() const {
	return tcap;
}

const bellesip::SDP::SDPPotentialCfgGraph::media_description_config & bellesip::SDP::SDPPotentialCfgGraph::getCfgForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & idx) const {
	try {
		const auto & cfg = cfgs.at(idx);
		return cfg;
	} catch (std::out_of_range&) {
		belle_sip_error("Unable to find configuration for stream %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_config>();
	}
}

const bellesip::SDP::SDPPotentialCfgGraph::media_description_unparsed_config & bellesip::SDP::SDPPotentialCfgGraph::getUnparsedCfgForStream(const session_description_unparsed_config::key_type & idx) const {
	try {
		const auto & cfg = unparsed_cfgs.at(idx);
		return cfg;
	} catch (std::out_of_range&) {
		belle_sip_error("Unable to find unparsed configurations for stream %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::session_description_unparsed_config::mapped_type>();
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
	} catch (std::out_of_range&) {
		belle_sip_error("Unable to find media attribute capabilities for stream %0u", idx);
		return bctoolbox::Utils::getEmptyConstRefObject<bellesip::SDP::SDPPotentialCfgGraph::media_description_acap>();
	}
}
const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap & bellesip::SDP::SDPPotentialCfgGraph::getMediaTcapForStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap::key_type & idx) const {
	try {
		const auto & cap = tcap.at(idx);
		return cap;
	} catch (std::out_of_range&) {
		belle_sip_error("Unable to find media transport capabilities for stream %0u", idx);
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

bool bellesip::SDP::SDPPotentialCfgGraph::addGlobalAcap(const unsigned int & idx, const std::string & name, const std::string & value) {
	const auto canAdd = (canFindAcapWithIdx(idx) == false);
	if (canAdd == true) {
		std::shared_ptr<acapability> elem = std::make_shared<acapability>();
		elem->index = idx;
		elem->name = name;
		elem->value = value;
		elem->type = bellesip::SDP::capability_type_t::ATTRIBUTE;
		globalAcap.push_back(elem);
	}
	return canAdd;
}

bool bellesip::SDP::SDPPotentialCfgGraph::addGlobalTcap(const unsigned int & idx, const std::string & value) {
	const auto canAdd = (canFindTcapWithIdx(idx) == false);
	if (canAdd == true) {
		std::shared_ptr<capability> elem = std::make_shared<capability>();
		elem->index = idx;
		elem->value = value;
		elem->type = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
		globalTcap.push_back(elem);
	}
	return canAdd;
}

bool bellesip::SDP::SDPPotentialCfgGraph::addAcapToStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_acap::key_type & streamIdx, const unsigned int & capIdx, const std::string & capName, const std::string & capValue) {
	const auto canAdd = (canFindAcapWithIdx(capIdx) == false);
	if (canAdd == true) {
		std::shared_ptr<acapability> elem = std::make_shared<acapability>();
		elem->index = capIdx;
		elem->name = capName;
		elem->value = capValue;
		elem->type = bellesip::SDP::capability_type_t::ATTRIBUTE;
		acap[streamIdx].push_back(elem);
	}
	return canAdd;
}

bool bellesip::SDP::SDPPotentialCfgGraph::addTcapToStream(const bellesip::SDP::SDPPotentialCfgGraph::session_description_base_cap::key_type & streamIdx, const unsigned int & capIdx, const std::string & capValue) {
	const auto canAdd = (canFindTcapWithIdx(capIdx) == false);
	if (canAdd == true) {
		std::shared_ptr<capability> elem = std::make_shared<capability>();
		elem->index = capIdx;
		elem->value = capValue;
		elem->type = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
		tcap[streamIdx].push_back(elem);
	}
	return canAdd;
}

bool bellesip::SDP::SDPPotentialCfgGraph::canFindAcapWithIdx(const unsigned int & index) const {
	const auto & globalAcaps = getGlobalAcap();
	const auto globalAcapIt = std::find_if(globalAcaps.cbegin(), globalAcaps.cend(), [&index] (const std::shared_ptr<acapability> & cap) {
		return (cap->index == index);
	});
	const bool foundInGlobalAcap = (globalAcapIt != globalAcap.cend());
	bool foundInStreamAcap = false;
	const auto & acaps = getStreamAcap();
	for (const auto & streamAcapPair : acaps) {
		const auto & acapList = streamAcapPair.second;
		const auto streamAcapIt = std::find_if(acapList.cbegin(), acapList.cend(), [&index] (const std::shared_ptr<acapability> & cap) {
			return (cap->index == index);
		});
		foundInStreamAcap |= (streamAcapIt != acapList.cend());
	}

	if (foundInStreamAcap && foundInGlobalAcap) {
		belle_sip_error("Graph may be corrupted because acap at index %0d has been found in both global and stream attribute capabilities", index);
	}

	return (foundInStreamAcap || foundInGlobalAcap);
}

bool bellesip::SDP::SDPPotentialCfgGraph::canFindTcapWithIdx(const unsigned int & index) const {
	const auto & globalTcaps = getGlobalTcap();
	const auto globalTcapIt = std::find_if(globalTcaps.cbegin(), globalTcaps.cend(), [&index] (const std::shared_ptr<capability> & cap) {
		return (cap->index == index);
	});
	const bool foundInGlobalTcap = (globalTcapIt != globalTcap.cend());
	bool foundInStreamTcap = false;
	const auto & tcaps = getStreamTcap();
	for (const auto & streamTcapPair : tcaps) {
		const auto & tcapList = streamTcapPair.second;
		const auto streamTcapIt = std::find_if(tcapList.cbegin(), tcapList.cend(), [&index] (const std::shared_ptr<capability> & cap) {
			return (cap->index == index);
		});
		foundInStreamTcap |= (streamTcapIt != tcapList.cend());
	}

	if (foundInStreamTcap && foundInGlobalTcap) {
		belle_sip_error("Graph may be corrupted because tcap at index %0d has been found in both global and stream attribute capabilities", index);
	}

	return (foundInStreamTcap || foundInGlobalTcap);
}

void bellesip::SDP::SDPPotentialCfgGraph::addCfg(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const bellesip::SDP::SDPPotentialCfgGraph::media_description_config::key_type & cfgIdx, const std::list<std::map<unsigned int, bool>> & acapIdxs, std::list<unsigned int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes) {

	bellesip::SDP::SDPPotentialCfgGraph::media_description_config cfg;
	try {
		cfg = cfgs.at(streamIdx);
	} catch (std::out_of_range&) {
		belle_sip_error("Creating attribute configuration for stream at index %0u", streamIdx);
	}

	cfg[cfgIdx] = createCfgAttr(streamIdx, acapIdxs, tcapIdx, delete_media_attributes, delete_session_attributes);

	cfgs[streamIdx] = cfg;
}

void bellesip::SDP::SDPPotentialCfgGraph::addAcapListToCfg(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const bellesip::SDP::SDPPotentialCfgGraph::media_description_config::key_type & cfgIdx, const std::map<unsigned int, bool> & acapIdx) {

	if (!acapIdx.empty()) {
		bellesip::SDP::SDPPotentialCfgGraph::media_description_config cfg;
		bellesip::SDP::config_attribute cfgAttr;
		try {
			cfg = cfgs.at(streamIdx);
			cfgAttr = cfg.at(cfgIdx);
		} catch (std::out_of_range&) {
			belle_sip_error("Creating configuration for stream at index %0u", streamIdx);
			cfgAttr.delete_session_attributes = false;
			cfgAttr.delete_media_attributes = false;
		}

		cfgAttr.acap.push_back(createAcapList(streamIdx, acapIdx));
		cfg[cfgIdx] = cfgAttr;

		cfgs[streamIdx] = cfg;
	}

}

void bellesip::SDP::SDPPotentialCfgGraph::addTcapListToCfg(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const bellesip::SDP::SDPPotentialCfgGraph::media_description_config::key_type & cfgIdx, std::list<unsigned int> & tcapIdx) {
	if (!tcapIdx.empty()) {
		bellesip::SDP::SDPPotentialCfgGraph::media_description_config cfg;
		bellesip::SDP::config_attribute cfgAttr;
		try {
			cfg = cfgs.at(streamIdx);
			cfgAttr = cfg.at(cfgIdx);
		} catch (std::out_of_range&) {
			belle_sip_error("Creating configuration for stream at index %0u", streamIdx);
			cfgAttr.delete_session_attributes = false;
			cfgAttr.delete_media_attributes = false;
		}

		const auto tcapList = createTcapList(streamIdx, tcapIdx);
		cfgAttr.tcap.insert(cfgAttr.tcap.begin(), tcapList.begin(), tcapList.end());
		cfg[cfgIdx] = cfgAttr;

		cfgs[streamIdx] = cfg;
	}
}

std::list<bellesip::SDP::config_capability<bellesip::SDP::acapability>> bellesip::SDP::SDPPotentialCfgGraph::createAcapList(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const std::map<unsigned int, bool> & acapIdx) const {
	std::list<bellesip::SDP::config_capability<bellesip::SDP::acapability>> acapList;

	const auto & acaps = getAllAcapForStream(streamIdx);
	for (const auto & acapPair : acapIdx) {
		const auto & idx = acapPair.first;
		const auto & mandatory = acapPair.second;
		config_capability<acapability> cfgCap;
		cfgCap.mandatory = mandatory;
		auto acapIt = std::find_if(acaps.cbegin(), acaps.cend(), [&idx] (const std::shared_ptr<acapability> & cap) {
			return (cap->index == idx);
		});
		if (acapIt == acaps.cend()) {
			belle_sip_error("Unable to find attribute capability with index %0d - skipping it", idx);
			break;
		} else {
			cfgCap.cap = *acapIt;
			acapList.push_back(cfgCap);
		}
	}

	return acapList;
}

std::list<bellesip::SDP::config_capability<bellesip::SDP::capability>> bellesip::SDP::SDPPotentialCfgGraph::createTcapList(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const std::list<unsigned int> & tcapIdx) const {
	std::list<bellesip::SDP::config_capability<bellesip::SDP::capability>> tcapList;
	const auto & tcaps = getAllTcapForStream(streamIdx);
	for (const auto & idx : tcapIdx) {
		config_capability<capability> cfgCap;
		cfgCap.mandatory = false;
		auto tcapIt = std::find_if(tcaps.cbegin(), tcaps.cend(), [&idx] (const std::shared_ptr<capability> & cap) {
			return (cap->index == idx);
		});
		if (tcapIt == tcaps.cend()) {
			belle_sip_error("Unable to find transport capability with index %0d - skipping it", idx);
			break;
		} else {
			cfgCap.cap = *tcapIt;
			tcapList.push_back(cfgCap);
		}
	}

	return tcapList;
}

bellesip::SDP::config_attribute bellesip::SDP::SDPPotentialCfgGraph::createCfgAttr(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const std::list<std::map<unsigned int, bool>> & acapIdxs, std::list<unsigned int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes) const {
	bellesip::SDP::config_attribute cfgAttr;
	cfgAttr.delete_session_attributes = delete_session_attributes;
	cfgAttr.delete_media_attributes = delete_media_attributes;

	for (const auto & acapIdx : acapIdxs) {
		cfgAttr.acap.push_back(createAcapList(streamIdx, acapIdx));
	}

	if (!tcapIdx.empty()) {
		const auto tcapList = createTcapList(streamIdx, tcapIdx);
		cfgAttr.tcap.insert(cfgAttr.tcap.begin(), tcapList.begin(), tcapList.end());
	}

	return cfgAttr;
}

unsigned int bellesip::SDP::SDPPotentialCfgGraph::getFreeTcapIdx() const {
	std::list<unsigned int> tcapIndexes;
	auto addToIndexList = [&tcapIndexes] (const std::shared_ptr<capability> & cap) {
		tcapIndexes.push_back(cap->index);
	};
	const auto & globalTcaps = getGlobalTcap();
	std::for_each(globalTcaps.begin(), globalTcaps.end(), addToIndexList);
	const auto & streamTcaps = getStreamTcap();
#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-lambda-capture"
#endif
	std::for_each(streamTcaps.begin(), streamTcaps.end(), [&tcapIndexes, &addToIndexList] (const std::pair<unsigned int, bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap> & tcapList) {
		std::for_each(tcapList.second.begin(), tcapList.second.end(), addToIndexList);
	});
#if __clang__
#pragma clang diagnostic pop
#endif

	return getFreeIdx(tcapIndexes);
}

unsigned int bellesip::SDP::SDPPotentialCfgGraph::getFreeAcapIdx() const {
	std::list<unsigned int> acapIndexes;
	auto addToIndexList = [&acapIndexes] (const std::shared_ptr<acapability> & cap) {
		acapIndexes.push_back(cap->index);
	};
	const auto & globalAcaps = getGlobalAcap();
	std::for_each(globalAcaps.begin(), globalAcaps.end(), addToIndexList);
	const auto & streamAcaps = getStreamAcap();
	
#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-lambda-capture"
#endif
	std::for_each(streamAcaps.begin(), streamAcaps.end(), [&acapIndexes, &addToIndexList] (const std::pair<unsigned int, bellesip::SDP::SDPPotentialCfgGraph::media_description_acap> & acapList) {
		std::for_each(acapList.second.begin(), acapList.second.end(), addToIndexList);
	});
#if __clang__
#pragma clang diagnostic pop
#endif
	return getFreeIdx(acapIndexes);

}

unsigned int bellesip::SDP::SDPPotentialCfgGraph::getFreeCfgIdx(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & idx) const {
	std::list<unsigned int> cfgIndexes;
	auto addToIndexList = [&cfgIndexes] (const std::pair<unsigned int, bellesip::SDP::config_attribute> & cfg) {
		cfgIndexes.push_back(cfg.first);
	};
	const auto & streamCfgs = getCfgForStream(idx);
	std::for_each(streamCfgs.begin(), streamCfgs.end(), addToIndexList);

	return getFreeIdx(cfgIndexes);
}

unsigned int bellesip::SDP::SDPPotentialCfgGraph::getFreeIdx(const std::list<unsigned int> & l) const {
	auto lCopy = l;
	// Sort elements
	lCopy.sort();
	// Delete duplicates
	lCopy.unique();
	decltype(lCopy) lResult(lCopy.begin(), std::prev(lCopy.end(), 1));
	// Compute the difference between consecutive elements - if any of them is not equal to 1, then a free index is found
	std::transform (std::next(lCopy.begin(), 1), lCopy.end(), lResult.begin(), lResult.begin(), std::minus<int>());
	const auto & gapIt = std::find_if_not(lResult.cbegin(), lResult.cend(), [] (const unsigned int & el) { return (el == 1);});
	if (gapIt == lResult.cend()) {
		// No gap found - then return max element + 1
		return *std::max_element(l.cbegin(), l.cend()) + 1;
	} else {
		const auto elIdx = std::distance(lResult.cbegin(), gapIt);
		const int startGap = *(std::next(l.begin(), elIdx));
		return startGap + 1;
	}

	return 0;
}

bool bellesip::SDP::SDPPotentialCfgGraph::empty() const {
	return globalAcap.empty() && globalTcap.empty() && cfgs.empty() && acap.empty() && tcap.empty() && unparsed_cfgs.empty();
}

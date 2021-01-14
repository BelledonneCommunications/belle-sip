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

bellesip::SDP::SDPPotentialCfgGraph::SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc) {
	processSessionDescription(session_desc);
}

void bellesip::SDP::capabilityToAttributeName(const bellesip::SDP::capability_type_t cap) {
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

void bellesip::SDP::SDPPotentialCfgGraph::processSessionDescription (const belle_sdp_session_description_t* session_desc) {
	const auto globalAcap = getSessionDescriptionACapabilities(session_desc);
	const auto globalTcap = getSessionDescriptionTCapabilities(session_desc);
	for ( media_desc_it=belle_sdp_session_description_get_media_descriptions ( session_desc ); media_desc_it!=NULL; media_desc_it=media_desc_it->next ) {
		const belle_sdp_media_description_t* media_desc=BELLE_SDP_MEDIA_DESCRIPTION ( media_desc_it->data );
		processMediaDescription(media_desc, globalAcap, globalTcap);
	}
}

const belle_sip_list_t * bellesip::SDP::SDPPotentialCfgGraph::getSessionCapabilityAttributes(const belle_sdp_session_description_t* session_desc, const bellesip::SDP::capability_type_t cap) {
	const std::string cap_name(bellesip::SDP::capabilityToAttributeName(cap));
	const char* value=belle_sdp_session_description_get_attribute_value(session_desc, cap_name.c_str());
	return belle_sdp_session_description_find_attributes_with_name(session_desc, cap_name);
}

media_description_acap bellesip::SDP::SDPPotentialCfgGraph::getSessionDescriptionACapabilities (const belle_sdp_session_description_t* session_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::ATTRIBUTE;
	const belle_sip_list_t * caps_attr = getSessionCapabilityAttributes(session_desc, cap);
	return createACapabilitiesList(caps_attr, cap);
}

media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getSessionDescriptionTCapabilities (const belle_sdp_session_description_t* session_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	const belle_sip_list_t * caps_attr = getSessionCapabilityAttributes(session_desc, cap);
	return createTCapabilitiesList(caps_attr, cap);
}

media_description_acap bellesip::SDP::SDPPotentialCfgGraph::createACapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap) {
	media_description_acap caps;
	for(;caps_attr!=NULL;caps_attr=caps_attr->next){
		belle_sdp_acap_attribute_t* lAttribute = static_cast<belle_sdp_acap_attribute_t*>(caps_attr->data);
		std::shared_ptr<acapability> elem = std::make_shared<acapability>();
		elem->id = belle_sdp_acap_attribute_get_id(lAttribute);
		elem->name = static_cast<const char *>(belle_sdp_acap_attribute_get_name(lAttribute));
		elem->value = static_cast<const char *>(belle_sdp_acap_attribute_get_value(lAttribute));
		elem->type = cap;
		caps.push_back(elem);
	}
	return caps;
}

media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::createTCapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap) {
	media_description_base_cap caps;
	for(;caps_attr!=NULL;caps_attr=caps_attr->next){
		belle_sdp_tcap_attribute_t* lAttribute = static_cast<belle_sdp_tcap_attribute_t*>(caps_attr->data);
		int id = belle_sdp_tcap_attribute_get_id(lAttribute);
		const belle_sip_list_t *list = belle_sdp_tcap_attribute_get_protos(lAttribute);
		for(; list!=NULL; list=list->next){
			std::shared_ptr<capability> elem = std::make_shared<capability>();
			elem.index = id;
			elem.value = static_cast<const char *>(list->data);
			elem.type = cap;
			id++;
			caps.push_back(elem);
		}
	}
	return caps;
}

const belle_sip_list_t * bellesip::SDP::SDPPotentialCfgGraph::getMediaCapabilityAttributes(const belle_sdp_media_description_t* session_desc, const bellesip::SDP::capability_type_t cap) {
	const std::string cap_name(bellesip::SDP::capabilityToAttributeName(cap));
	return belle_sdp_session_description_find_attributes_with_name(session_desc, cap_name);
}


media_description_acap bellesip::SDP::SDPPotentialCfgGraph::getMediaDescriptionACapabilities (const belle_sdp_media_description_t* media_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::ATTRIBUTE;
	const belle_sip_list_t * caps_attr = getMediaCapabilityAttributes(media_desc, cap);
	return createACapabilitiesList(caps_attr, cap);
}

media_description_base_cap bellesip::SDP::SDPPotentialCfgGraph::getMediaDescriptionTCapabilities (const belle_sdp_media_description_t* media_desc) {
	const bellesip::SDP::capability_type_t cap = bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	const belle_sip_list_t * caps_attr = getMediaCapabilityAttributes(media_desc, cap);
	return createTCapabilitiesList(caps_attr, cap);
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaDescription(const belle_sdp_media_description_t* media_desc, const media_description_acap & globalAcap, const media_description_base_cap & globalTcap) {
	// ACAP
	auto mediaAcap = getSessionDescriptionACapabilities(media_desc);
	mediaAcap.insert(globalAcap.begin(), globalAcap.end());
	acap.push_back(mediaAcap);

	// TCAP
	auto mediaTcap = getSessionDescriptionTCapabilities(media_desc);
	mediaTcap.insert(globalTcap.begin(), globalTcap.end());
	tcap.push_back(mediaTcap);

	// ACFG
	processMediaCfg(media_desc, mediaAcap, mediaTCap, bellesip::SDP::config_type::ACFG);

	// PCFG
	processMediaCfg(media_desc, mediaAcap, mediaTCap, bellesip::SDP::config_type::PCFG);
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaCfg(const belle_sdp_media_description_t* media_desc, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap, const bellesip::SDP::config_type_t cfgType) {
	const auto & attrs = belle_sdp_session_description_find_attributes_with_name(media_desc, "acfg");
	media_description_config config;
	for(;attrs!=NULL;attrs=attrs->next){
		config_attribute attr_config;
		int id = -1;
		switch (cfgType) {
			case bellesip::SDP::config_type_t::ACFG:
			{
				belle_sdp_acfg_attribute_t* lAttribute = static_cast<belle_sdp_acfg_attribute_t*>(attrs->data);
				id = belle_sdp_acfg_attribute_get_id(lAttribute);
				attr_config = createAConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
			}
				break;
			case bellesip::SDP::config_type_t::PCFG:
			{
				belle_sdp_pcfg_attribute_t* lAttribute = static_cast<belle_sdp_pcfg_attribute_t*>(attrs->data);
				id = belle_sdp_pcfg_attribute_get_id(lAttribute);
				attr_config = createPConfigFromAttribute(lAttribute, mediaAcap, mediaTcap);
			}
				break;
		}
		config[id] = attr_config;
	}

	switch (cfgType) {
		case bellesip::SDP::config_type_t::ACFG:
			acfg.push_back(config);
			break;
		case bellesip::SDP::config_type_t::PCFG:
			pcfg.push_back(config);
			break;
	}
}

config_attribute bellesip::SDP::SDPPotentialCfgGraph::createPConfigFromAttribute(const belle_sdp_pcfg_attribute_t* media_desc, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap) {
	belle_sip_list_t* configList = belle_sdp_pcfg_attribute_get_configs(lAttribute);
	return processConfig(configList, mediaAcap, mediaTcap);
}

config_attribute bellesip::SDP::SDPPotentialCfgGraph::createAConfigFromAttribute(const belle_sdp_acfg_attribute_t* media_desc, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap) {
	belle_sip_list_t* configList = belle_sdp_acfg_attribute_get_configs(lAttribute);
	return processConfig(configList, mediaAcap, mediaTcap);
}

config_attribute bellesip::SDP::SDPPotentialCfgGraph::processConfig(const belle_sip_list_t* configList, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap) const {
	belle_sip_list_t* list = configList;
	config_attribute attr_config;
	for(;list!=NULL;list=list->next){
		std::string cfg = static_cast<const char*>(list->data);
		belle_sip_message("configuration is %s", cfg.c_str());
		// Valid formats for the configuration string:
		// - <char>=-<char>:<pipe separated list of configs>
		// - <char>=-<char><char>:<pipe separated list of configs>
		// - <char>=<pipe separated list of configs>

		// Split at the = sign
		const char bodyDelim = '=';
		std::list<std::string> bodySplit = splitString(cfg, bodyDelim);

		if (bodySplit.size() < 2) {
			belle_sip_error("size of the vector after splitting using delimiter %c is %llu", bodyDelim, strVector.size());
			return attr_config;
		}

		// First element is the type of capability
		auto capType = bodySplit.front();
		const bellesip::SDP::capability_type_t cap = capabilityTypeFromAttrParam(capType);

		// last element is the body of the attribute
		auto attrBody = bodySplit.back();
		belle_sip_message("configuration type is %s and body is %s", capType.c_str(), attrBody.c_str());

		const char deleteAttrDelim = ':';
		std::list<std::string> deleteAttrSplit = splitString(attrBody, deleteAttrDelim);

		// Delete attribute is only in the acfg attribute
		if (cap == bellesip::SDP::capability_type_t::ATTRIBUTE) {
			if (bodySplit.size() > 1) {
				// First element is the delete attribute
				auto deleteAttr = deleteAttrSplit.front();
				attr_config.delete_media_attributes = (deleteAttr.find('m') != std::string::npos);
				attr_config.delete_session_attributes = (deleteAttr.find('s') != std::string::npos);
			} else {
				attr_config.delete_media_attributes = false;
				attr_config.delete_session_attributes = false;
			}
		}

		// last element is the list of configs
		auto idxList = deleteAttrSplit.back();
		belle_sip_message("configuration list is %s", idxList.c_str());

		if (cap == bellesip::SDP::capability_type_t::ATTRIBUTE) {
			attr_config.acap.push_back(parseIdxList(idxList, acap));
		} else if (cap == bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL) {
			attr_config.tcap.push_back(parseIdxList(idxList, tcap));
		}
	}
	return attr_config;
}

const bellesip::SDP::capability_type_t bellesip::SDP::SDPPotentialCfgGraph::capabilityTypeFromAttrParam(const std::string & attrParam) const {
	if (configType.compare("a") == 0) {
		return bellesip::SDP::capability_type_t::ATTRIBUTE;
	} else if (configType.compare("t") == 0) {
		return bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL;
	}
	return bellesip::SDP::capability_type_t::EXTENDED;
}

void bellesip::SDP::SDPPotentialCfgGraph::getElementIdx(const std::string & index) {
	std::smatch match;
	std::regex indexRegex ( "[0-9]+", std::regex::ECMAScript);   // matches words beginning by "sub"

	std::regex indexRregex("(\\d+)");
	auto indexBegin = std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto indexEnd = std::sregex_iterator();

	if (indexBegin == indexEnd) {
		belle_sip_message("Unable to find index in string %s ", index.c_str());
	}

	auto noMatches = std::distance(indexBegin, indexEnd);
	if (noMatches > 1) {
		belle_sip_error("Expected one match but found %0d instead - only first match will be honored", noMatches);
	}

	for (std::sregex_iterator it = indexBegin; it != indexEnd; ++it) {
		std::smatch match = *it;
		return std::to_string(match.str());
	}

	return -1;
}

void bellesip::SDP::SDPPotentialCfgGraph::fillConfigCapability(const int & index, const bool mandatory, config_attribute & attr_config, const bellesip::SDP::capability_type_t & cap) const {
	switch (cap) {
		case bellesip::SDP::capability_type_t::ATTRIBUTE:
		{
			config_capability<acapbility> cap;
			cap.mandatory = mandatory;

			attr_config.acap
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

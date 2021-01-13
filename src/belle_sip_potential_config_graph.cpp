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

void bellesip::SDP::SDPPotentialCfgGraph::processSessionDescription (const belle_sdp_session_description_t* session_desc) {
belle_sdp_attribute_t*
	media_description_capability globalAcap = fillGlobalCapabilities(session_desc, bellesip::SDP::capability_type_t::ATTRIBUTE);
	media_description_capability globalTcap = fillGlobalCapabilities(session_desc, bellesip::SDP::capability_type_t::TRANSPORT_PROTOCOL);
	media_description_capability globalEcap = fillGlobalCapabilities(session_desc, bellesip::SDP::capability_type_t::EXTENDED);
	for ( media_desc_it=belle_sdp_session_description_get_media_descriptions ( session_desc ); media_desc_it!=NULL; media_desc_it=media_desc_it->next ) {
		const belle_sdp_media_description_t* media_desc=BELLE_SDP_MEDIA_DESCRIPTION ( media_desc_it->data );
		processMediaDescription(media_desc, globalAcap, globalTcap, globalEcap);
	}
}

media_description_capability bellesip::SDP::SDPPotentialCfgGraph::processSessionDescription (const belle_sdp_session_description_t* session_desc, const bellesip::SDP::capability_type_t cap) {
	const std::string cap_name(bellesip::SDP::capabilityToAttributeName(cap));

	const char* value=belle_sdp_session_description_get_attribute_value(session_desc, cap_name.c_str());
	
}

void bellesip::SDP::SDPPotentialCfgGraph::processMediaDescription(const belle_sdp_media_description_t* media_desc, const media_description_capability & globalAcap, const media_description_capability & globalTcap, const media_description_capability & globalEcap) {
	media_description_capability mediaAcap = globalAcap;
	media_description_capability mediaTCap = globalTcap;
	media_description_capability mediaEcap = globalEcap;

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

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

#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <list>

#include "bctoolbox/utils.hh"

#include "belle-sip/belle-sdp.h"
#include "belle-sip/utils.h"

namespace bellesip {

	namespace SDP {

		typedef enum config_type {
			ACFG,
			PCFG
		} config_type_t;

		typedef enum capability_type {
			ATTRIBUTE,
			TRANSPORT_PROTOCOL,
			EXTENDED
		} capability_type_t;

		std::string capabilityToAttributeName(const bellesip::SDP::capability_type_t cap);

		struct capability {
			int               index = -1; // Invalid index
			std::string       value;
			capability_type_t type = ATTRIBUTE;
		};

		struct acapability : public capability {
			std::string       name;
		};

		template<class cap_type>
		struct config_capability {
			std::weak_ptr<cap_type> cap;
			bool                    mandatory = false; // Capability is mandatory
		};

		struct config_attribute {
			// list of list of capabilities
			// each element of the outer list stores a list of capabilities (mandatory and optional) to create a media session - in SDP terms, it represent a comma-separated continguous sequence of indexes
			std::list<std::list<config_capability<acapability>>> acap;
			std::list<config_capability<capability>> tcap;
			bool delete_media_attributes = false; // Delete SDP media attributes
			bool delete_session_attributes = false; // Delete SDP session attributes
		};

		#ifdef _WIN32
			// Disable C4251 triggered by types derived from STL.
			#pragma warning(push)
			#pragma warning(disable: 4251)
		#endif // ifdef _WIN32
		class BELLESIP_EXPORT SDPPotentialCfgGraph {

			public:

				using media_description_base_cap = std::list<std::shared_ptr<capability>>;
				using session_description_base_cap = std::map<unsigned int, media_description_base_cap>;
				using media_description_acap = std::list<std::shared_ptr<acapability>>;
				using session_description_acap = std::map<unsigned int, media_description_acap>;
				using media_description_config = std::map<unsigned int, config_attribute>;
				using session_description_config = std::map<unsigned int, media_description_config>;

				explicit SDPPotentialCfgGraph ();
				explicit SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc);
				SDPPotentialCfgGraph & operator= (const SDPPotentialCfgGraph & other);
				const session_description_config & getAllAcfg() const;
				const session_description_config & getAllPcfg() const;
				const session_description_acap & getStreamAcap() const;
				const session_description_base_cap & getStreamTcap() const;

				const media_description_config & getAcfgForStream(const session_description_config::key_type & idx) const;
				const media_description_config & getPcfgForStream(const session_description_config::key_type & idx) const;
				const media_description_acap & getGlobalAcap() const;
				const media_description_base_cap & getGlobalTcap() const;
				const media_description_acap & getMediaAcapForStream(const session_description_acap::key_type & idx) const;
				const media_description_base_cap & getMediaTcapForStream(const session_description_base_cap::key_type & idx) const;
				const media_description_acap getAllAcapForStream(const session_description_acap::key_type & idx) const;
				const media_description_base_cap getAllTcapForStream(const session_description_base_cap::key_type & idx) const;

				bool addGlobalAcap(const int & idx, const std::string & name, const std::string & value);
				bool addGlobalTcap(const int & idx, const std::string & value);

				bool addAcapToStream(const session_description_acap::key_type & streamIdx, const int & capIdx, const std::string & capName, const std::string & capValue);
				bool addTcapToStream(const session_description_base_cap::key_type & streamIdx, const int & capIdx, const std::string & capValue);

				void addAcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx, std::list<int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes);
				void addAcapListToAcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx);
				void addTcapListToAcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, std::list<int> & tcapIdx);

				void addPcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx, std::list<int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes);
				void addAcapListToPcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx);
				void addTcapListToPcfg(const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, std::list<int> & tcapIdx);

				void processSessionDescription (const belle_sdp_session_description_t* session_desc);

				int getFreeTCapIdx() const;
				int getFreeACapIdx() const;
				int getFreeACfgIdx(const session_description_config::key_type & idx) const;
				int getFreePCfgIdx(const session_description_config::key_type & idx) const;

			protected:

			private:
				// configuration list
				// Each element of the vector is a media session

				media_description_acap globalAcap;
				media_description_base_cap globalTcap;
				session_description_config acfg;
				session_description_config pcfg;
				session_description_acap acap;
				session_description_base_cap tcap;

				template<class cap_type>
				const std::pair<std::list<std::list<config_capability<cap_type>>>,bool> parseIdxList(const std::string & idxList, const std::list<std::shared_ptr<cap_type>> & availableCaps) const;

 				// Session
				const belle_sip_list_t * getSessionCapabilityAttributes(const belle_sdp_session_description_t* session_desc, const bellesip::SDP::capability_type_t cap);

 				// Media
				void processMediaDescription(const unsigned int & idx, const belle_sdp_media_description_t* media_desc);
				const belle_sip_list_t * getMediaCapabilityAttributes(const belle_sdp_media_description_t* media_desc, const bellesip::SDP::capability_type_t cap);

 				// Attribute capabilities
				media_description_acap getSessionDescriptionACapabilities (const belle_sdp_session_description_t* session_desc);
				media_description_acap getMediaDescriptionACapabilities (const belle_sdp_media_description_t* media_desc);
				media_description_acap createACapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap);

				// Transport capabilities
				media_description_base_cap getSessionDescriptionTCapabilities (const belle_sdp_session_description_t* session_desc);
				media_description_base_cap getMediaDescriptionTCapabilities (const belle_sdp_media_description_t* media_desc);
				media_description_base_cap createTCapabilitiesList (const belle_sip_list_t * caps_attr, const bellesip::SDP::capability_type_t cap);

				// Configuration
				void processMediaCfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc, const bellesip::SDP::config_type_t cfgType);
				void processMediaACfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc);
				void processMediaPCfg(const unsigned int & idx, const belle_sdp_media_description_t* media_desc);
				// TODO: should attribute have const? belle_sdp_pcfg_attribute_get_configs takes a non const
				media_description_config::mapped_type createPConfigFromAttribute(belle_sdp_pcfg_attribute_t* attribute, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap);
				// TODO: should attribute have const? belle_sdp_acfg_attribute_get_configs takes a non const
				media_description_config::mapped_type createAConfigFromAttribute(belle_sdp_acfg_attribute_t* attribute, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap);
				media_description_config::mapped_type processConfig(const belle_sip_list_t* configList, const media_description_acap & mediaAcap, const media_description_base_cap & mediaTcap) const;
				bellesip::SDP::capability_type_t capabilityTypeFromAttrParam(const std::string & attrParam) const;
				int getElementIdx(const std::string & index) const;

				// streamIdx -> index of the stream to search for capabilities
				// acapIdx -> map of attribute capability indexes and mandatory attributes
				// tcapIdx -> map of transport protocol indexes
				// delete_media_attributes -> delete media attributes flags
				// delete_session_attributes -> delete session attributes flags
				config_attribute createCfgAttr(const bellesip::SDP::SDPPotentialCfgGraph::session_description_config::key_type & streamIdx, const std::map<int, bool> & acapIdx, std::list<int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes) const;

				bool canFindAcapWithIdx(const int & index) const;
				bool canFindTcapWithIdx(const int & index) const;

				void addCfg(session_description_config & sessionCfg, const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx, std::list<int> & tcapIdx, const bool delete_media_attributes, const bool delete_session_attributes);

				void addAcapListToCfg(session_description_config & sessionCfg, const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, const std::map<int, bool> & acapIdx);
				void addTcapListToCfg(session_description_config & sessionCfg, const session_description_config::key_type & streamIdx, const media_description_config::key_type & cfgIdx, std::list<int> & tcapIdx);

				std::list<config_capability<acapability>> createAcapList(const session_description_config::key_type & streamIdx, const std::map<int, bool> & acapIdx) const;
				std::list<config_capability<capability>> createTcapList(const session_description_config::key_type & streamIdx, const std::list<int> & tcapIdx) const;

				int getFreeIdx(const std::list<int> & l) const;
		};
		
		#ifdef _WIN32
			#pragma warning(pop)
		#endif // ifdef _WIN32

		template<class cap_type>
		const std::pair<std::list<std::list<config_capability<cap_type>>>, bool> bellesip::SDP::SDPPotentialCfgGraph::parseIdxList(const std::string & idxList, const std::list<std::shared_ptr<cap_type>> & availableCaps) const {
			const char configDelim = '|';
			const auto attrCapList = bctoolbox::Utils::split(idxList, configDelim);
			bool mandatory = true;

			const char startOptDelim = '[';
			const char endOptDelim = ']';
			std::list<std::list<config_capability<cap_type>>> capList;
			bool success = true;
			for (const auto & config : attrCapList) {
				const char capDelim = ',';
				const auto capIdList = bctoolbox::Utils::split(config, capDelim);
				std::list<config_capability<cap_type>> caps;
				for (const auto & index : capIdList) {
					belle_sip_message("configuration is %s index is %s", config.c_str(), index.c_str());
					const auto startOptPos = index.find(startOptDelim);
					const auto endOptPos = index.find(endOptDelim);
					if (startOptPos != std::string::npos) {
						mandatory = false;
					}
					auto idx = getElementIdx(index);
					config_capability<cap_type> cfg;
					cfg.mandatory = mandatory;
					auto capIt = std::find_if(availableCaps.cbegin(), availableCaps.cend(), [&idx] (const std::shared_ptr<cap_type> & cap) {
						return (cap->index == idx);
					});
					if (capIt == availableCaps.cend()) {
						belle_sip_error("Unable to find capability with index %d - skipping it", idx);
						// Configuration is not valid - clear all capabilities
						caps.clear();
						success = false;
						break;
					} else {
						cfg.cap = *capIt;
						caps.push_back(cfg);
					}

					if (endOptPos != std::string::npos) {
						mandatory = true;
					}
				}

				if (!caps.empty()) {
					capList.push_back(caps);
				}
			}

			return std::make_pair(capList, success);
		}

	}
}


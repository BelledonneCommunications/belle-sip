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

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <list>

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

		struct acapability : public capability_t {
			std::string       name;
		};

		template<class cap_type>
		struct config_capability {
			std::weak_ptr<cap_type> cap;
			bool                    mandatory = false; // Capability is mandatory
		};

		struct config_attribute {
			// vector of list of capabilities
			// each element of the vector stores a list of capabilities (mandatory and optional) to create a media session - in SDP terms, it represent a comma-separated continguous sequence of indexes
			std::vector<std::list<config_capability<acapbility>>> acap,
			std::vector<std::list<config_capability<capability>>> tcap,
			bool delete_media_attributes = false, // Delete SDP media attributes
			bool delete_session_attributes = false // Delete SDP session attributes
		};

		class SDPPotentialCfgGraph {

			using media_description_base_cap = std::list<std::shared_ptr<capability>>;
			using session_description_base_cap = std::vector<media_description_base_cap>;
			using media_description_acap = std::list<std::shared_ptr<acapability>>;
			using session_description_acap = std::vector<media_description_acap>;
			using media_description_config = std::map<unsigned int, config_attribute>;
			using session_description_config = std::vector<media_description_config>;

			public:
				explicit SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc);
				// This method should be moved to an utility file as it is not strictly releated to the configuration graph
				template<class container>
				container splitString(const std::string & str, const char delim);

			protected:

			private:
				// configuration list
				// Each element of the vector is a media session
				session_description_config acfg;
				session_description_config pcfg;
				session_description_acap acap;
				session_description_base_cap tcap;

				void processMediaDescription(const belle_sdp_media_description_t* media_desc, const std::list<capability_t> & globalAcap, const std::list<capability_t> & globalTcap, const std::list<capability_t> & globalEcap);
				void processSessionDescription (const belle_sdp_session_description_t* session_desc);
				const belle_sip_list_t * getSessionCapabilityAttributes(const belle_sdp_session_description_t* session_desc, const bellesip::SDP::capability_type_t cap);
				media_description_acap getSessionDescriptionACapabilities (const belle_sdp_session_description_t* session_desc);
				media_description_base_cap getSessionDescriptionTCapabilities (const belle_sdp_session_description_t* session_desc);
				const belle_sip_list_t * getMediaCapabilityAttributes(const belle_sdp_media_description_t* media_desc, const bellesip::SDP::capability_type_t cap);
				media_description_acap getMediaDescriptionACapabilities (const belle_sdp_media_description_t* media_desc);
				media_description_base_cap getMediaDescrptionTCapabilities (const belle_sdp_media_description_t* media_desc);
		};

		// This method should be moved to an utility file as it is not strictly releated to the configuration graph
		template<class container>
		container bellesip::SDP::SDPPotentialCfgGraph::splitString(const std::string & str, const char delim) {
			container splittedStr;
			std::size_t current, previous = 0;
			current = str.find(delim);
			while (current != std::string::npos) {
				splittedStr.push_back(str.substr(previous, current - previous));
				previous = current + 1;
				current = str.find(delim, previous);
			}
			splittedStr.push_back(str.substr(previous, current - previous));
			return splittedStr;
		}

		template<class cap_type>
		std::list<config_capability<cap_type>> bellesip::SDP::SDPPotentialCfgGraph::parseIdxList(const std::string & idxList, const std::vector<std::list<std::shared_ptr<cap_type>>> & availableCaps) const {
			const char configDelim = '|';
			std::list<std::string> attrCapList = splitString(idxList, configDelim);
			bool mandatory = false;

			const char startOptDelim = '[';
			const char endOptDelim = ']';
			std::list<config_capability<cap_type>> capList;
			for (const auto & config : attrCapList) {
				const char capDelim = ',';
				std::list<std::string> capList = splitString(config, capDelim);
				for (const auto & index : capList) {
					belle_sip_message("configuration is %s index is %s", config.c_str(), index.c_str());
					const auto startOptPos = index.find(startOptDelim);
					const auto endOptPos = index.find(endOptDelim);
					if (startOptPos != std::string::npos) {
						mandatory = true;
					}
					auto idx = getElementIdx(index);
					config_capability<cap_type> cfg;
					cfg.mandatory = mandatory;
					auto capIt = std::find_if(availableCaps.cbegin(); availableCaps.cend(), [&idx] (const auto & cap) {
						return (cap->index == idx);
					}
					if (capIt == availableCaps.cend()) {
						belle_sip_error("Unable to find capability with index %d", idx);
					} else {
						cfg.cap = *capIt;
					}
					capList.push_back(cfg);

					if (endOptPos != std::string::npos) {
						mandatory = false;
					}	
				}
			}
		}

	}
}


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

		typedef enum capability_type {
			ATTRIBUTE,
			TRANSPORT_PROTOCOL,
			EXTENDED
		} capability_type_t;

		std::string capabilityToAttributeName(const bellesip::SDP::capability_type_t cap);

		typedef struct capability {
			int  index = -1, // Invalid index
			std::string       value,
			capability_type_t type = ATTRIBUTE
		} capability_t;

		typedef struct config_capability {
			std::weak_ptr<capability_t>,
			bool mandatory = false // Capability is mandatory
		} capability_t;

		typedef struct config_attribute {
			// vector of list of capabilities
			// each element of the vector stores a list of capabilities (mandatory and optional) to create a media session - in SDP terms, it represent a comma-separated continguous sequence of indexes
			std::vector<std::list<config_capability>> acap,
			std::vector<std::list<config_capability>> tcap,
			std::vector<std::list<config_capability>> ecap,
			bool delete_media_attributes = false, // Delete SDP media attributes
			bool delete_session_attributes = false // Delete SDP session attributes
		} config_attribute_t;

		class SDPPotentialCfgGraph {

			using media_description_capability = std::list<capability_t>;
			using session_description_capability = std::vector<media_description_capability>;
			using media_description_config = std::map<int, config_attribute_t>;
			using session_description_config = std::vector<media_description_config>;

			public:
				explicit SDPPotentialCfgGraph (const belle_sdp_session_description_t* session_desc);

			protected:

			private:
				// configuration list
				// Each element of the vector is a media session
				session_description_config pcfg;
				session_description_capability acap;
				session_description_capability tcap;
				session_description_capability ecap;

				void processMediaDescription(const belle_sdp_media_description_t* media_desc, const std::list<capability_t> & globalAcap, const std::list<capability_t> & globalTcap, const std::list<capability_t> & globalEcap);
				void processSessionDescription (const belle_sdp_session_description_t* session_desc);
		}

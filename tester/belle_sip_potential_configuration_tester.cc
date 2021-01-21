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

#include "belle_sip_tester.h"
#include "belle-sip/potential_config_graph.hh"

static const char* simpleSdpWithNoPotentialConfig = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"m=audio 7078 RTP/AVP 111 110 3 0 8 101\r\n"\
						"a=rtpmap:111 speex/16000\r\n"\
						"a=fmtp:111 vbr=on\r\n"\
						"a=rtpmap:110 speex/8000\r\n"\
						"a=fmtp:110 vbr=on\r\n"\
						"a=rtpmap:101 telephone-event/8000\r\n"\
						"a=fmtp:101 0-11\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_no_potential_config(void) {
	const char* src = simpleSdpWithNoPotentialConfig;
	const belle_sdp_session_description_t* sessionDescription = belle_sdp_session_description_parse(src);
	const auto mediaDescriptions = belle_sdp_session_description_get_media_descriptions(sessionDescription);
	const auto noMediaDescriptions = belle_sip_list_size(mediaDescriptions);

	bellesip::SDP::SDPPotentialCfgGraph graph(sessionDescription);

	BC_ASSERT_EQUAL(graph.getAllAcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllTcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllAcfg().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllPcfg().size(), noMediaDescriptions, std::size_t, "%0lu");

	// ACAP 
	const auto globalAcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "acap");
	const auto noGlobalAcap = belle_sip_list_size(globalAcap);
	BC_ASSERT_EQUAL(noGlobalAcap, 1, std::size_t, "%0lu");

	// TCAP
	const auto globalTcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "tcap");
	BC_ASSERT_EQUAL(belle_sip_list_size(globalTcap), 1, std::size_t, "%0lu");
	std::size_t noGlobalTcap = 0;
	std::map<int, std::string> idList;
	for(auto it = globalTcap; it!=NULL; it=it->next){
		auto attr = static_cast<belle_sdp_tcap_attribute_t*>(bctbx_list_get_data(it));
		auto id = belle_sdp_tcap_attribute_get_id(attr);
		auto tcapList = belle_sdp_tcap_attribute_get_protos(attr);
		auto protoId = id;
		for(auto list = tcapList; list!=NULL; list=list->next){
			auto proto = static_cast<const char *>(bctbx_list_get_data(list));
			idList[protoId] = proto;
			protoId++;
		}
		auto noTcap = belle_sip_list_size(tcapList);
		noGlobalTcap += noTcap;
	}
	BC_ASSERT_EQUAL(noGlobalTcap, 2, std::size_t, "%0lu");

	auto mediaDescriptionElem = mediaDescriptions;
	for (std::size_t idx = 0; idx < noMediaDescriptions; idx++) {
		BC_ASSERT_PTR_NOT_NULL(mediaDescriptionElem);
		auto mediaDescription = static_cast<belle_sdp_media_description_t*>(bctbx_list_get_data(mediaDescriptionElem));
		const auto noMediaAcap = belle_sip_list_size(belle_sdp_media_description_find_attributes_with_name(mediaDescription, "acap"));
		BC_ASSERT_EQUAL(noMediaAcap, 0, std::size_t, "%0lu");
		const auto noMediaTcap = belle_sip_list_size(belle_sdp_media_description_find_attributes_with_name(mediaDescription, "tcap"));
		BC_ASSERT_EQUAL(noMediaTcap, 0, std::size_t, "%0lu");

		BC_ASSERT_EQUAL(graph.getAcapForStream(idx).size(), (noGlobalAcap+noMediaAcap), std::size_t, "%0lu");
		auto tcap = graph.getTcapForStream(idx);
		BC_ASSERT_EQUAL(tcap.size(), (noGlobalTcap+noMediaTcap), std::size_t, "%0lu");
		for (const auto & cap : tcap) {
			auto id = cap->index;
			auto expIt = idList.find(id);
			BC_ASSERT_TRUE(expIt != idList.end());
			if (expIt != idList.end()) {
				auto proto = cap->value;
				auto expProto = idList[id];
				BC_ASSERT_TRUE(expProto.compare(proto) == 0);
			};
		}
		mediaDescriptionElem = mediaDescriptionElem->next;
	}
}

test_t potential_configuration_graph_tests[] = {
	TEST_NO_TAG("SDP with no potential configs", test_no_potential_config)
};

test_suite_t potential_configuration_graph_test_suite = {"Potential configuration graph", NULL, NULL, belle_sip_tester_before_each, belle_sip_tester_after_each,
								sizeof(potential_configuration_graph_tests) / sizeof(potential_configuration_graph_tests[0]), potential_configuration_graph_tests};

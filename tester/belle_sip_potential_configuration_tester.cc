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

struct acapParts {
	const std::string name;
	const std::string value;
};

static std::map<int, std::string> fillTcapMap(const bctbx_list_t* currentTcap, const int & expProtoCap) {
	std::map<int, std::string> protoList;
	for(auto it = currentTcap; it!=NULL; it=it->next){
		auto attr = static_cast<belle_sdp_tcap_attribute_t*>(bctbx_list_get_data(it));
		auto id = belle_sdp_tcap_attribute_get_id(attr);
		auto tcapList = belle_sdp_tcap_attribute_get_protos(attr);
		auto protoId = id;
		for(auto list = tcapList; list!=NULL; list=list->next){
			auto proto = static_cast<const char *>(bctbx_list_get_data(list));
			protoList[protoId] = proto;
			protoId++;
		}
	}
	BC_ASSERT_EQUAL(protoList.size(), expProtoCap, std::size_t, "%0lu");
	return protoList;
}

static void checkAcap(const bellesip::SDP::SDPPotentialCfgGraph::media_description_acap acap, const int & expNoAcap, std::map<int, acapParts> & expAcapAttrs) {
	BC_ASSERT_EQUAL(acap.size(), expNoAcap, std::size_t, "%0lu");
	for (const auto & cap : acap) {
		auto id = cap->index;
		auto expIt = expAcapAttrs.find(id);
		BC_ASSERT_TRUE(expIt != expAcapAttrs.end());
		if (expIt != expAcapAttrs.end()) {
			const auto & value = cap->value;
			const auto & expValue = expAcapAttrs[id].value;
			BC_ASSERT_STRING_EQUAL(value.c_str(), expValue.c_str());

			const auto & name = cap->name;
			const auto & expName = expAcapAttrs[id].name;
			BC_ASSERT_STRING_EQUAL(name.c_str(), expName.c_str());

		}
	}
}

static void checkTcap(const bellesip::SDP::SDPPotentialCfgGraph::media_description_base_cap tcap, const int & expNoTcap, std::map<int, std::string> & expTcapProtos) {
	BC_ASSERT_EQUAL(tcap.size(), expNoTcap, std::size_t, "%0lu");
	for (const auto & cap : tcap) {
		auto id = cap->index;
		auto expIt = expTcapProtos.find(id);
		BC_ASSERT_TRUE(expIt != expTcapProtos.end());
		if (expIt != expTcapProtos.end()) {
			auto proto = cap->value;
			auto expProto = expTcapProtos[id];
			BC_ASSERT_STRING_EQUAL(proto.c_str(), expProto.c_str());
		};
	}
}

static void base_test_no_potential_config(const char* src, int expGlobalProtoCap, int expGlobalTcap, int expGlobalAcap, int expMediaProtoCap, int expMediaTcap, int expMediaAcap) {
	const belle_sdp_session_description_t* sessionDescription = belle_sdp_session_description_parse(src);
	const auto mediaDescriptions = belle_sdp_session_description_get_media_descriptions(sessionDescription);
	const auto noMediaDescriptions = belle_sip_list_size(mediaDescriptions);

	bellesip::SDP::SDPPotentialCfgGraph graph(sessionDescription);

	std::map<int, acapParts> expAcapAttrs = {
		{ 1, {"key-mgmt" ,"mikey AQAFgM"} },
		{ 20, {"ptime", "30"} },
		{ 59, {"crypto", "10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4"} },
		{ 10021, {"crypto", "1 AES_CM_256_HMAC_SHA1_80 inline:WVNfX19zZW1jdGwgKCkgewkyMjA7fQp9CnVubGVz|2^20|1:4"} },
		{ 1001, {"crypto", "5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4"} },
	};
	BC_ASSERT_EQUAL(graph.getAllAcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllTcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllAcfg().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllPcfg().size(), noMediaDescriptions, std::size_t, "%0lu");

	// ACAP 
	const auto globalAcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "acap");
	const auto noGlobalAcap = belle_sip_list_size(globalAcap);
	BC_ASSERT_EQUAL(noGlobalAcap, expGlobalAcap, std::size_t, "%0lu");


	// TCAP
	const auto globalTcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "tcap");
	BC_ASSERT_EQUAL(belle_sip_list_size(globalTcap), expGlobalTcap, std::size_t, "%0lu");
	auto protoList = fillTcapMap(globalTcap, expGlobalProtoCap);
	auto noGlobalProtoCap = protoList.size();

	auto mediaDescriptionElem = mediaDescriptions;
	for (std::size_t idx = 0; idx < noMediaDescriptions; idx++) {
		BC_ASSERT_PTR_NOT_NULL(mediaDescriptionElem);
		auto mediaDescription = static_cast<belle_sdp_media_description_t*>(bctbx_list_get_data(mediaDescriptionElem));

		// ACAP
		const auto noMediaAcap = belle_sip_list_size(belle_sdp_media_description_find_attributes_with_name(mediaDescription, "acap"));
		BC_ASSERT_EQUAL(noMediaAcap, expMediaAcap, std::size_t, "%0lu");
		auto acap = graph.getAcapForStream(idx);
		checkAcap(acap, (noGlobalAcap+noMediaAcap), expAcapAttrs);

		// TCAP
		const auto mediaTcap = belle_sdp_media_description_find_attributes_with_name(mediaDescription, "tcap");
		BC_ASSERT_EQUAL(belle_sip_list_size(mediaTcap), expMediaTcap, std::size_t, "%0lu");
		auto mediaProtoList = fillTcapMap(mediaTcap, expMediaProtoCap);
		auto noMediaProtoCap = mediaProtoList.size();
		protoList.insert(mediaProtoList.begin(), mediaProtoList.end());

		auto tcap = graph.getTcapForStream(idx);
		checkTcap(tcap, (noGlobalProtoCap+noMediaProtoCap), protoList);

		auto acfg = graph.getAcfgForStream(idx);
		BC_ASSERT_EQUAL(acfg.size(), 0, std::size_t, "%0lu");

		auto pcfg = graph.getPcfgForStream(idx);
		BC_ASSERT_EQUAL(pcfg.size(), 0, std::size_t, "%0lu");

		mediaDescriptionElem = mediaDescriptionElem->next;
	}
}

static const char* simpleSdpWithNoCapabilities = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
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

static void test_no_capabilities(void) {
	base_test_no_potential_config(simpleSdpWithNoCapabilities, 0, 0, 0, 0, 0, 0);
}

static const char* simpleSdpWithSingleCapabilityInSession = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
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

static void test_single_capability_in_session(void) {
	base_test_no_potential_config(simpleSdpWithSingleCapabilityInSession, 1, 1, 1, 0, 0, 0);
}

static const char* simpleSdpWithMultipleProtosOnSameLineInSession = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
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

static void test_multiple_capabilities_on_same_line_in_session(void) {
	base_test_no_potential_config(simpleSdpWithMultipleProtosOnSameLineInSession, 3, 2, 2, 0, 0, 0);
}

static const char* simpleSdpWithMultipleCapabilitiesInSession = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=acap:10021 crypto:1 AES_CM_256_HMAC_SHA1_80 inline:WVNfX19zZW1jdGwgKCkgewkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
						"a=tcap:2 RTP/SAVPF\r\n"\
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

static void test_multiple_capabilities_in_session(void) {
	base_test_no_potential_config(simpleSdpWithMultipleCapabilitiesInSession, 2, 2, 3, 0, 0, 0);
}

static const char* simpleSdpWithSingleCapabilityInMedia = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_single_capability_in_media(void) {
	base_test_no_potential_config(simpleSdpWithSingleCapabilityInMedia, 0, 0, 0, 1, 1, 1);
}

static const char* simpleSdpWithMultipleCapabilitiesInMedia = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:10021 crypto:1 AES_CM_256_HMAC_SHA1_80 inline:WVNfX19zZW1jdGwgKCkgewkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
						"a=tcap:2 RTP/SAVPF\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_multiple_capabilities_in_media(void) {
	base_test_no_potential_config(simpleSdpWithMultipleCapabilitiesInMedia, 0, 0, 0, 2, 2, 3);
}

static const char* simpleSdpWithMultipleProtosOnSameLineInMedia = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_multiple_capabilities_on_same_line_in_media(void) {
	base_test_no_potential_config(simpleSdpWithMultipleProtosOnSameLineInMedia, 0, 0, 0, 3, 2, 2);
}

static const char* simpleSdpWithSingleCapability = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_single_capability(void) {
	base_test_no_potential_config(simpleSdpWithSingleCapability, 1, 1, 1, 1, 1, 1);
}

static const char* simpleSdpWithMultipleCapabilities = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:10021 crypto:1 AES_CM_256_HMAC_SHA1_80 inline:WVNfX19zZW1jdGwgKCkgewkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=tcap:1 RTP/SAVP\r\n"\
						"a=tcap:2 RTP/SAVPF\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_multiple_capabilities(void) {
	base_test_no_potential_config(simpleSdpWithMultipleCapabilities, 1, 1, 1, 2, 2, 3);
}

static const char* simpleSdpWithMultipleProtosOnSameLine = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"b=AS:380\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_multiple_capabilities_on_same_line(void) {
	base_test_no_potential_config(simpleSdpWithMultipleProtosOnSameLine, 1, 1, 1, 3, 2, 2);
}

static void checkCfg(const bellesip::SDP::SDPPotentialCfgGraph::media_description_config & cfg, const int & expNoCfg, std::map<int, std::list<int>> expCfgAcapAttrs, std::map<int, std::list<int>> expCfgTcapAttrs, std::map<int, acapParts> expAcapAttrs, std::map<int, std::string> & expTcapProtos) {

	BC_ASSERT_EQUAL(cfg.size(), expNoCfg, std::size_t, "%0lu");
	for (const auto & cfgPair : cfg) {

		// Check ID exists in the expected config list
		auto cfgId = cfgPair.first;
		auto expCfgAcap = expCfgAcapAttrs.find(cfgId);
		BC_ASSERT_TRUE(expCfgAcap != expCfgAcapAttrs.end());
		auto expCfgTcap = expCfgTcapAttrs.find(cfgId);
		BC_ASSERT_TRUE(expCfgTcap != expCfgTcapAttrs.end());

		auto cfgAttr = cfgPair.second;
		if (expCfgAcap != expCfgAcapAttrs.end()) {
			// Check acap
			const auto & acapCfg = cfgAttr.acap;
			for (const auto & acapCfgEl : acapCfg) {
				for (const auto & cfgAttr : acapCfgEl) {
					// Get shared pointer to capability
					const auto capPtr = cfgAttr.cap.lock();
					BC_ASSERT_PTR_NOT_NULL(capPtr.get());
					if (capPtr) {
						checkAcap({capPtr}, 1, expAcapAttrs);
					}
				}
			}
		}

		if (expCfgTcap != expCfgTcapAttrs.end()) {
			// Check acap
			const auto & tcapCfg = cfgAttr.tcap;
			for (const auto & tcapCfgEl : tcapCfg) {
				for (const auto & cfgAttr : tcapCfgEl) {
					// Get shared pointer to capability
					const auto capPtr = cfgAttr.cap.lock();
					BC_ASSERT_PTR_NOT_NULL(capPtr.get());
					if (capPtr) {
						checkTcap({capPtr}, 1, expTcapProtos);
					}
				}
			}
		}
	}
}

static void base_test_with_potential_config(const char* src, int expGlobalProtoCap, int expGlobalTcap, int expGlobalAcap, int expMediaProtoCap, int expMediaTcap, int expMediaAcap, int expAcfg, int expPcfg) {
	const belle_sdp_session_description_t* sessionDescription = belle_sdp_session_description_parse(src);
	const auto mediaDescriptions = belle_sdp_session_description_get_media_descriptions(sessionDescription);
	const auto noMediaDescriptions = belle_sip_list_size(mediaDescriptions);

	bellesip::SDP::SDPPotentialCfgGraph graph(sessionDescription);

	std::map<int, acapParts> expAcapAttrs = {
		{ 1, {"key-mgmt" ,"mikey AQAFgM"} },
		{ 20, {"ptime", "30"} },
		{ 59, {"crypto", "10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4"} },
		{ 10021, {"crypto", "1 AES_CM_256_HMAC_SHA1_80 inline:WVNfX19zZW1jdGwgKCkgewkyMjA7fQp9CnVubGVz|2^20|1:4"} },
		{ 1001, {"crypto", "5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4"} },
	};

	std::map<int, std::list<int>> expCfgAcapAttrs = {
		{ 1, {1, 1001} },
		{ 1475, {20, 59} },
	};

	std::map<int, std::list<int>> expCfgTcapAttrs = {
		{ 1, {1} },
		{ 1475, {10} },
	};

	BC_ASSERT_EQUAL(graph.getAllAcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllTcap().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllAcfg().size(), noMediaDescriptions, std::size_t, "%0lu");
	BC_ASSERT_EQUAL(graph.getAllPcfg().size(), noMediaDescriptions, std::size_t, "%0lu");

	// ACAP 
	const auto globalAcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "acap");
	const auto noGlobalAcap = belle_sip_list_size(globalAcap);
	BC_ASSERT_EQUAL(noGlobalAcap, expGlobalAcap, std::size_t, "%0lu");


	// TCAP
	const auto globalTcap = belle_sdp_session_description_find_attributes_with_name(sessionDescription, "tcap");
	BC_ASSERT_EQUAL(belle_sip_list_size(globalTcap), expGlobalTcap, std::size_t, "%0lu");
	auto protoList = fillTcapMap(globalTcap, expGlobalProtoCap);
	auto noGlobalProtoCap = protoList.size();

	auto mediaDescriptionElem = mediaDescriptions;
	for (std::size_t idx = 0; idx < noMediaDescriptions; idx++) {
		BC_ASSERT_PTR_NOT_NULL(mediaDescriptionElem);
		auto mediaDescription = static_cast<belle_sdp_media_description_t*>(bctbx_list_get_data(mediaDescriptionElem));

		// ACAP
		const auto noMediaAcap = belle_sip_list_size(belle_sdp_media_description_find_attributes_with_name(mediaDescription, "acap"));
		BC_ASSERT_EQUAL(noMediaAcap, expMediaAcap, std::size_t, "%0lu");
		const auto acap = graph.getAcapForStream(idx);
		checkAcap(acap, (noGlobalAcap+noMediaAcap), expAcapAttrs);

		// TCAP
		const auto mediaTcap = belle_sdp_media_description_find_attributes_with_name(mediaDescription, "tcap");
		BC_ASSERT_EQUAL(belle_sip_list_size(mediaTcap), expMediaTcap, std::size_t, "%0lu");
		auto mediaProtoList = fillTcapMap(mediaTcap, expMediaProtoCap);
		auto noMediaProtoCap = mediaProtoList.size();
		protoList.insert(mediaProtoList.begin(), mediaProtoList.end());

		const auto tcap = graph.getTcapForStream(idx);
		checkTcap(tcap, (noGlobalProtoCap+noMediaProtoCap), protoList);

		auto acfg = graph.getAcfgForStream(idx);
		checkCfg(acfg, expAcfg, expCfgAcapAttrs, expCfgTcapAttrs, expAcapAttrs, protoList);

		auto pcfg = graph.getPcfgForStream(idx);
		checkCfg(pcfg, expPcfg, expCfgAcapAttrs, expCfgTcapAttrs, expAcapAttrs, protoList);

		mediaDescriptionElem = mediaDescriptionElem->next;
	}
}

static const char* simpleSdpWithOnePotentialAConfig = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=acfg:1475 a=20,59 t=10\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_one_acfg(void) {
	base_test_with_potential_config(simpleSdpWithOnePotentialAConfig, 1, 1, 1, 3, 2, 3, 1, 0);
}

static const char* simpleSdpWithOnePotentialPConfig = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=pcfg:1475 a=20,59 t=10\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_one_pcfg(void) {
	base_test_with_potential_config(simpleSdpWithOnePotentialPConfig, 1, 1, 1, 3, 2, 3, 0, 1);
}

static const char* simpleSdpWithMultiplePotentialAConfig = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=acfg:1 a=1001,1 t=1\r\n"\
						"a=acfg:1475 a=20,59 t=10\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_multiple_acfg(void) {
	base_test_with_potential_config(simpleSdpWithMultiplePotentialAConfig, 1, 1, 1, 3, 2, 3, 2, 0);
}

static const char* simpleSdpWithMultiplePotentialPConfig = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=pcfg:1475 a=20,59 t=10\r\n"\
						"a=pcfg:1 a=1001,1 t=1\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_multiple_pcfg(void) {
	base_test_with_potential_config(simpleSdpWithMultiplePotentialPConfig, 1, 1, 1, 3, 2, 3, 0, 2);
}

static const char* simpleSdpWithCapabilitiesReferredInAConfigBeforeDefinition = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=acfg:1475 a=20,59 t=10\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=acfg:1 a=1001,1 t=1\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_capability_referenced_by_acfg_before_defined(void) {
	base_test_with_potential_config(simpleSdpWithCapabilitiesReferredInAConfigBeforeDefinition, 0, 0, 2, 4, 3, 2, 2, 0);
}

static const char* simpleSdpWithCapabilitiesReferredInPConfigBeforeDefinition = "v=0\r\n"\
						"o=jehan-mac 1239 1239 IN IP6 2a01:e35:1387:1020:6233:4bff:fe0b:5663\r\n"\
						"s=SIP Talk\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"t=0 0\r\n"\
						"a=ice-pwd:31ec21eb38b2ec6d36e8dc7b\r\n"\
						"a=acap:20 ptime:30\r\n"\
						"a=acap:1001 crypto:5 AES_CM_192_HMAC_SHA1_32 inline:CY/Dizd1QrlobZtgnigr0hWE+oDSx4S1F51Zpo4aZamN+8ZMdp8|2^20|1:4\r\n"\
						"m=video 8078 RTP/AVP 99 97 98\r\n"\
						"c=IN IP4 192.168.0.18\r\n"\
						"b=AS:380\r\n"\
						"a=acap:1 key-mgmt:mikey AQAFgM\r\n"\
						"a=pcfg:1475 a=20,59 t=10\r\n"\
						"a=acap:59 crypto:10 MS_AES_256_SHA1_80 inline:HjdHIU446fe64hnu6K446rkyMjA7fQp9CnVubGVz|2^20|1:4\r\n"\
						"a=tcap:10 UDP/TLS/RTP/SAVP\r\n"\
						"a=pcfg:1 a=1001,1 t=1\r\n"\
						"a=rtcp-fb:98 nack rpsi\r\n"\
						"a=rtcp-xr:rcvr-rtt=all:10\r\n"\
						"a=rtpmap:99 MP4V-ES/90000\r\n"\
						"a=fmtp:99 profile-level-id=3\r\n"\
						"a=tcap:19 UDP/TLS/RTP/SAVPF\r\n"\
						"a=rtpmap:97 theora/90000\r\n"\
						"a=rtpmap:98 H263-1998/90000\r\n"\
						"a=tcap:1 RTP/SAVP RTP/SAVPF\r\n"\
						"a=fmtp:98 CIF=1;QCIF=1\r\n";

static void test_with_capability_referenced_by_pcfg_before_defined(void) {
	base_test_with_potential_config(simpleSdpWithCapabilitiesReferredInPConfigBeforeDefinition, 0, 0, 2, 4, 3, 2, 0, 2);
}

test_t potential_configuration_graph_tests[] = {
	TEST_NO_TAG("SDP with no capabilities", test_no_capabilities),
	TEST_NO_TAG("SDP with single capability in session", test_single_capability_in_session),
	TEST_NO_TAG("SDP with multiple capabilities in session", test_multiple_capabilities_in_session),
	TEST_NO_TAG("SDP with multiple capabilities on same line in session", test_multiple_capabilities_on_same_line_in_session),
	TEST_NO_TAG("SDP with single capability in media", test_single_capability_in_media),
	TEST_NO_TAG("SDP with multiple capabilities in media", test_multiple_capabilities_in_media),
	TEST_NO_TAG("SDP with multiple capabilities on same line in media", test_multiple_capabilities_on_same_line_in_media),
	TEST_NO_TAG("SDP with single capability", test_single_capability),
	TEST_NO_TAG("SDP with multiple capabilities", test_multiple_capabilities),
	TEST_NO_TAG("SDP with multiple capabilities on same line", test_multiple_capabilities_on_same_line),
	TEST_NO_TAG("SDP with one acfg", test_with_one_acfg),
	TEST_NO_TAG("SDP with one pcfg", test_with_one_pcfg),
	TEST_NO_TAG("SDP with multiple acfg", test_with_multiple_acfg),
	TEST_NO_TAG("SDP with multiple pcfg", test_with_multiple_pcfg),
	TEST_NO_TAG("SDP with capability referenced by acfg before it is defined", test_with_capability_referenced_by_acfg_before_defined),
	TEST_NO_TAG("SDP with capability referenced by pcfg before it is defined", test_with_capability_referenced_by_pcfg_before_defined),
};

test_suite_t potential_configuration_graph_test_suite = {"Potential configuration graph", NULL, NULL, belle_sip_tester_before_each, belle_sip_tester_after_each,
								sizeof(potential_configuration_graph_tests) / sizeof(potential_configuration_graph_tests[0]), potential_configuration_graph_tests};

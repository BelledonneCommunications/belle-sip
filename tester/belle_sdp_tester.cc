#include "belle-sip/belle-sip.h"
#include "parser/sdp.hh"
#include "belle_sip_tester.h"
#include "port.h"

using namespace bellesip;

static void test_belr_attribute(void) {
	auto parser = new Parser::SDP;
	auto lAttribute = (belle_sdp_attribute_t *)parser->parse("attribute-fields", "a=rtpmap:101 telephone-event/8000\r\n");
	/*belle_sdp_attribute_t* lAttribute = attribute_parse_marshall_parse_clone("a=rtpmap:101 telephone-event/8000");*/
	BC_ASSERT_STRING_EQUAL(belle_sdp_attribute_get_name(lAttribute), "rtpmap");
	BC_ASSERT_STRING_EQUAL(belle_sdp_attribute_get_value(lAttribute), "101 telephone-event/8000");
	BC_ASSERT_TRUE(belle_sdp_attribute_has_value(lAttribute));
	belle_sip_object_unref(BELLE_SIP_OBJECT(lAttribute));

    BC_ASSERT_TRUE(true);
}


test_t sdp_belr_tests[] = {
	TEST_NO_TAG("a= (attribute)", test_belr_attribute)
};

test_suite_t sdp_belr_test_suite = {"SDP Belr", NULL, NULL, belle_sip_tester_before_each, belle_sip_tester_after_each,
							   sizeof(sdp_belr_tests) / sizeof(sdp_belr_tests[0]), sdp_belr_tests};

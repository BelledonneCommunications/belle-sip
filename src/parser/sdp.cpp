#include "parser/sdp.hh"
#include "belle-sip/belle-sdp.h"
#include "bctoolbox/logging.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
using namespace belr;
using namespace bellesip;

// Initialize the singleton instance
bellesip::Parser::SDP *bellesip::Parser::SDP::instance = 0;
bellesip::Parser::SDP *bellesip::Parser::SDP::getInstance() {
    if (!instance) {
       instance = new SDP();
    }

    return instance;
}

bellesip::Parser::SDP::SDP() {
    shared_ptr<Grammar> grammar = loadGrammar();
    _parser = make_shared<belr::Parser<void*>>(grammar);

    _parser->setHandler("session-description", make_fn(&belle_sdp_session_description_new))
           ->setCollector("attribute", make_fn(&belle_sdp_session_description_add_attribute))
           ->setCollector("session-name", make_fn(&belle_sdp_session_description_set_session_name))
           ->setCollector("origin", make_fn(&belle_sdp_session_description_set_origin))
           ->setCollector("proto-version", make_fn(&belle_sdp_session_description_set_version))
           ->setCollector("connection", make_fn(&belle_sdp_session_description_set_connection))
           ->setCollector("info", make_fn(&belle_sdp_session_description_set_info))
           ->setCollector("times", make_fn(&belle_sdp_session_description_set_time_description))
           ->setCollector("media-description", make_fn(&belle_sdp_session_description_add_media_description))

           // RFC5939
           ->setCollector("creq-attribute", make_fn(&belle_sdp_session_description_set_creq_attribute))
           ->setCollector("csup-attribute", make_fn(&belle_sdp_session_description_set_csup_attribute))
           ->setCollector("tcap-attribute", make_fn(&belle_sdp_session_description_add_tcap_attribute))
           ->setCollector("acap-attribute", make_fn(&belle_sdp_session_description_add_acap_attribute));

    _parser->setHandler("csup-attribute", make_fn(&belle_sdp_csup_attribute_new))
           ->setCollector("option-tag", make_fn(&belle_sdp_csup_attribute_add_option_tag));

    _parser->setHandler("creq-attribute", make_fn(&belle_sdp_creq_attribute_new))
           ->setCollector("option-tag", make_fn(&belle_sdp_csup_attribute_add_option_tag));

    _parser->setHandler("tcap-attribute", make_fn(&belle_sdp_tcap_attribute_new))
           ->setCollector("trpr-cap-num", make_fn(&belle_sdp_tcap_attribute_set_id))
           ->setCollector("proto", make_fn(&belle_sdp_tcap_attribute_add_proto));

    _parser->setHandler("acap-attribute", make_fn(&belle_sdp_acap_attribute_new))
           ->setCollector("acap-cap-num", make_fn(&belle_sdp_acap_attribute_set_id))
           ->setCollector("att-field", make_fn(&belle_sdp_acap_attribute_set_name))
           ->setCollector("att-value", make_fn(&belle_sdp_acap_attribute_set_value));

    _parser->setHandler("acfg-attribute", make_fn(&belle_sdp_acfg_attribute_new))
           ->setCollector("config-number", make_fn(&belle_sdp_acfg_attribute_set_id))
           ->setCollector("sel-config", make_fn(&belle_sdp_acfg_attribute_add_config));

    _parser->setHandler("pcfg-attribute", make_fn(&belle_sdp_pcfg_attribute_new))
           ->setCollector("config-number", make_fn(&belle_sdp_pcfg_attribute_set_id))
           ->setCollector("pot-config", make_fn(&belle_sdp_pcfg_attribute_add_config));

    _parser->setHandler("session-name", make_fn(&belle_sdp_session_name_new))
           ->setCollector("session-name-value", make_fn(&belle_sdp_session_name_set_value));

    _parser->setHandler("proto-version", make_fn(&belle_sdp_version_new))
           ->setCollector("proto-version-value", make_fn(&belle_sdp_version_set_version));

    _parser->setHandler("times", make_fn(&belle_sdp_time_description_new))
           ->setCollector("start-stop-times", make_fn(&belle_sdp_time_description_set_time));

    _parser->setHandler("start-stop-times", make_fn(&belle_sdp_time_new))
           ->setCollector("start-time", make_fn(&belle_sdp_time_set_start))
           ->setCollector("stop-time", make_fn(&belle_sdp_time_set_stop));

    _parser->setHandler("media-description", make_fn(&belle_sdp_media_description_new))
           ->setCollector("attribute", make_fn(&belle_sdp_media_description_add_attribute))
           ->setCollector("media", make_fn(&belle_sdp_media_description_set_media))
           ->setCollector("info", make_fn(&belle_sdp_media_description_set_info))
           ->setCollector("connection", make_fn(&belle_sdp_media_description_set_connection))
           ->setCollector("bandwidth", make_fn(&belle_sdp_media_description_add_bandwidth))

           // RFC5939
           ->setCollector("acfg-attribute", make_fn(&belle_sdp_media_description_set_acfg_attribute))
           ->setCollector("creq-attribute", make_fn(&belle_sdp_media_description_set_creq_attribute))
           ->setCollector("creq-attribute", make_fn(&belle_sdp_media_description_set_csup_attribute))
           ->setCollector("pcfg-attribute", make_fn(&belle_sdp_media_description_add_pcfg_attribute))
           ->setCollector("tcap-attribute", make_fn(&belle_sdp_media_description_add_tcap_attribute))
           ->setCollector("acap-attribute", make_fn(&belle_sdp_media_description_add_acap_attribute));

    _parser->setHandler("rtcp-fb-attribute", make_fn(&belle_sdp_rtcp_fb_attribute_new))
           ->setCollector("rtcp-fb-pt", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_id))
           ->setCollector("rtcp-fb-ack-type", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_type))
           ->setCollector("rtcp-fb-ack-param", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_param))
           ->setCollector("rtcp-fb-nack-type", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_type))
           ->setCollector("rtcp-fb-nack-param", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_param))
           ->setCollector("rtcp-fb-ccm-type", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_type))
           ->setCollector("rtcp-fb-ccm-param", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_param))
           ->setCollector("rtcp-fb-ccm-tmmbr-param", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_param))
           ->setCollector("rtcp-fb-trr-int-type", make_fn(&belle_sdp_rtcp_fb_attribute_set_raw_type))
           ->setCollector("rtcp-fb-trr-int", make_fn(&belle_sdp_rtcp_fb_attribute_set_trr_int));

    _parser->setHandler("rtcp-xr-attribute", make_fn(&belle_sdp_rtcp_xr_attribute_new))
           ->setCollector("rcvr-rtt-mode", make_fn(&belle_sdp_rtcp_xr_attribute_set_rcvr_rtt_mode))
           ->setCollector("max-size", make_fn(&belle_sdp_rtcp_xr_attribute_set_rcvr_rtt_max_size))
           ->setCollector("stat-summary", make_fn(&belle_sdp_rtcp_xr_attribute_enable_stat_summary))
           ->setCollector("stat-flag", make_fn(&belle_sdp_rtcp_xr_attribute_add_stat_summary_flag))
           ->setCollector("voip-metrics", make_fn(&belle_sdp_rtcp_xr_attribute_enable_voip_metrics));

    _parser->setHandler("attribute", make_fn(&belle_sdp_raw_attribute_new))
           ->setCollector("att-field", make_fn(&belle_sdp_raw_attribute_set_name))
           ->setCollector("att-value", make_fn(&belle_sdp_raw_attribute_set_value));

    _parser->setHandler("bandwidth", make_fn(&belle_sdp_bandwidth_new))
           ->setCollector("bwtype", make_fn(&belle_sdp_bandwidth_set_type))
           ->setCollector("bwvalue", make_fn(&belle_sdp_bandwidth_set_value));

    _parser->setHandler("origin", make_fn(&belle_sdp_origin_new))
           ->setCollector("username", make_fn(&belle_sdp_origin_set_username))
           ->setCollector("sess-id", make_fn(&belle_sdp_origin_set_session_id))
           ->setCollector("sess-version", make_fn(&belle_sdp_origin_set_session_version))
           ->setCollector("nettype", make_fn(&belle_sdp_origin_set_network_type))
           ->setCollector("addrtype", make_fn(&belle_sdp_origin_set_address_type))
           ->setCollector("unicast-address", make_fn(&belle_sdp_origin_set_address));

    _parser->setHandler("connection", make_fn(&belle_sdp_connection_new))
           ->setCollector("nettype", make_fn(&belle_sdp_connection_set_network_type))
           ->setCollector("addrtype", make_fn(&belle_sdp_connection_set_address_type))
           ->setCollector("unicast-address", make_fn(&belle_sdp_connection_set_address))
           ->setCollector("IP4-multicast-address", make_fn(&belle_sdp_connection_set_address))
           ->setCollector("hexpart", make_fn(&belle_sdp_connection_set_address))
           ->setCollector("ttl", make_fn(&belle_sdp_connection_set_ttl))
           ->setCollector("range", make_fn(&belle_sdp_connection_set_range));

    _parser->setHandler("email", make_fn(&belle_sdp_email_new))
           ->setCollector("email-address", make_fn(&belle_sdp_email_set_value));

    _parser->setHandler("info", make_fn(&belle_sdp_info_new))
           ->setCollector("info-value", make_fn(&belle_sdp_info_set_value));

    _parser->setHandler("media", make_fn(&belle_sdp_media_new))
           ->setCollector("media-type", make_fn(&belle_sdp_media_set_media_type))
           ->setCollector("sdp-port", make_fn(&belle_sdp_media_set_media_port))
           ->setCollector("proto", make_fn(&belle_sdp_media_set_protocol))
           ->setCollector("fmt", make_fn(&belle_sdp_media_media_formats_add));
}

void * bellesip::Parser::SDP::parse(const string &input, const string &rule) {
    string parsedRule = rule;
    size_t parsedSize = 0;
    replace(parsedRule.begin(), parsedRule.end(), '_', '-');
    void * elem = _parser->parseInput(parsedRule, input, &parsedSize);
    if (parsedSize < input.size()){
        bctbx_error("[bellesip-sdp-parser] Parsing ended prematuraly at pos %llu", (unsigned long long)parsedSize);
    }

    return elem;
}

shared_ptr<Grammar> bellesip::Parser::SDP::loadGrammar() {
    shared_ptr<Grammar> grammar = GrammarLoader::get().load("sdp_grammar");

    if (!grammar) bctbx_fatal("Unable to load SDP grammar");

    return grammar;
}
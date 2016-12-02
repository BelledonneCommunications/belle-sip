#include "belle-sip/msrp-headers.h"
#include "belle-sip/parameters.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "grammars/belle_sip_messageLexer.h"
#include "grammars/belle_sip_messageParser.h"

#include "belle_sip_internal.h"
#include "listeningpoint_internal.h"

BELLE_SIP_PARSE(msrp_to_path)
belle_sip_header_msrp_to_path_t* belle_sip_header_msrp_to_path_create (const char* uri) {
	belle_sip_header_msrp_to_path_t* msrp_to_path = belle_sip_header_msrp_to_path_new();
	belle_sip_header_msrp_to_path_set_uri(msrp_to_path,uri);
	return msrp_to_path;
}
GET_SET_STRING(belle_sip_header_msrp_to_path,uri);

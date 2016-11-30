/*
	belle-sip - SIP (RFC3261) library.
    Copyright (C) 2010  Belledonne Communications SARL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "belle_sip_internal.h"
#include "belle-sip/msrp-message.h"

static void belle_msrp_request_init(belle_msrp_request_t *req){
	/*nop*/
}

static void belle_msrp_request_destroy(belle_msrp_request_t *req){
	// if (req->req_uri) belle_sip_object_unref(req->req_uri);
	DESTROY_STRING(req,transaction_id)
	DESTROY_STRING(req,method)
	// belle_msrp_request_set_listener(req,NULL);
	// belle_msrp_request_set_channel(req,NULL);
	// SET_OBJECT_PROPERTY(req,response,NULL);
}

static void belle_msrp_request_clone(belle_msrp_request_t *obj, const belle_msrp_request_t *orig){
	// if (orig->req_uri) obj->req_uri=(belle_generic_uri_t*)belle_sip_object_clone((belle_sip_object_t*)orig->req_uri);
	CLONE_STRING(belle_msrp_request,transaction_id,obj,orig)
	CLONE_STRING(belle_msrp_request,method,obj,orig)
}

static belle_sip_error_code belle_msrp_request_marshal(const belle_msrp_request_t* request, char* buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error=belle_sip_snprintf(buff,buff_size,offset,"MSRP %s %s\r\n",
		belle_msrp_request_get_transaction_id(request),
		belle_msrp_request_get_method(request));
	if (error!=BELLE_SIP_OK) return error;
	error=belle_sip_headers_marshal(BELLE_SIP_MESSAGE(request),buff,buff_size,offset);
	if (error!=BELLE_SIP_OK) return error;

	return error;
}

BELLE_NEW(belle_msrp_request,belle_sip_message)

#if 0
belle_msrp_request_t *belle_msrp_request_create(const char *method, belle_generic_uri_t *url, ...){
	va_list vl;
	belle_msrp_request_t *obj;
	belle_sip_header_t *header;

	// if (belle_generic_uri_get_host(url) == NULL) {
	// 	belle_sip_error("%s: NULL host in url", __FUNCTION__);
	// 	return NULL;
	// }

	obj=belle_sip_object_new(belle_msrp_request_t);
	obj->method=belle_sip_strdup(method);
	// obj->req_uri=(belle_generic_uri_t*)belle_sip_object_ref(url);

	va_start(vl,url);
	while((header=va_arg(vl,belle_sip_header_t*))!=NULL){
		belle_sip_message_add_header(BELLE_SIP_MESSAGE(obj),header);
	}
	va_end(vl);
	return obj;
}

void belle_msrp_request_set_listener(belle_msrp_request_t *req, belle_msrp_request_listener_t *l){
	if (req->listener){
		 belle_sip_object_weak_unref(req->listener,(belle_sip_object_destroy_notify_t)belle_msrp_request_listener_destroyed,req);
		 req->listener=NULL;
	}
	if (l){
		belle_sip_object_weak_ref(l,(belle_sip_object_destroy_notify_t)belle_msrp_request_listener_destroyed,req);
		req->listener=l;
	}
}

static void notify_msrp_request_of_channel_destruction(belle_msrp_request_t *obj, belle_sip_channel_t *chan_being_destroyed){
	obj->channel=NULL;
}

void belle_msrp_request_set_channel(belle_msrp_request_t *req, belle_sip_channel_t* chan){
	if (req->channel){
		belle_sip_object_weak_unref(req->channel, (belle_sip_object_destroy_notify_t)notify_msrp_request_of_channel_destruction, req);
		req->channel=NULL;
	}
	if (chan){
		belle_sip_object_weak_ref(chan, (belle_sip_object_destroy_notify_t)notify_msrp_request_of_channel_destruction, req);
		req->channel=chan;
	}
}

belle_msrp_request_listener_t * belle_msrp_request_get_listener(const belle_msrp_request_t *req){
	return req->listener;
}

belle_generic_uri_t *belle_msrp_request_get_uri(const belle_msrp_request_t *req){
	return req->req_uri;
}

void belle_msrp_request_set_uri(belle_msrp_request_t* request, belle_generic_uri_t* uri) {
	SET_OBJECT_PROPERTY(request,req_uri,uri);
}

void belle_msrp_request_set_response(belle_msrp_request_t *req, belle_msrp_response_t *resp){
	SET_OBJECT_PROPERTY(req,response,resp);
}

belle_msrp_response_t *belle_msrp_request_get_response(belle_msrp_request_t *req){
	return req->response;
}
#endif

GET_SET_STRING(belle_msrp_request, method)

GET_SET_STRING(belle_msrp_request, transaction_id)

/*response*/


struct belle_msrp_response{
	belle_sip_message_t base;
	char *msrp_version;
	int status_code;
	char *reason_phrase;
};


void belle_msrp_response_destroy(belle_msrp_response_t *resp){
	if (resp->msrp_version) belle_sip_free(resp->msrp_version);
	if (resp->reason_phrase) belle_sip_free(resp->reason_phrase);
}

#if 0
static void belle_msrp_response_init(belle_msrp_response_t *resp){
}

static void belle_msrp_response_clone(belle_msrp_response_t *resp, const belle_msrp_response_t *orig){
	if (orig->msrp_version) resp->msrp_version=belle_sip_strdup(orig->msrp_version);
	resp->status_code=orig->status_code;
	if (orig->reason_phrase) resp->reason_phrase=belle_sip_strdup(orig->reason_phrase);
}

belle_sip_error_code belle_msrp_response_marshal(belle_msrp_response_t *resp, char* buff, size_t buff_size, size_t *offset) {
	belle_sip_error_code error=belle_sip_snprintf(	buff
													,buff_size
													,offset
													,"msrp/1.1 %i %s\r\n"
													,belle_msrp_response_get_status_code(resp)
													,belle_msrp_response_get_reason_phrase(resp)?belle_msrp_response_get_reason_phrase(resp):"");
	if (error!=BELLE_SIP_OK) return error;
	// error=belle_sip_headers_marshal(BELLE_SIP_MESSAGE(resp),buff,buff_size,offset);
	if (error!=BELLE_SIP_OK) return error;

	return error;
}
#endif

/*
BELLE_NEW(belle_msrp_response,belle_sip_message)
BELLE_PARSE(belle_sip_messageParser,belle_,msrp_response)
GET_SET_STRING(belle_msrp_response,reason_phrase);
GET_SET_INT(belle_msrp_response,status_code,int)
*/

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
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "belle_sip_tester.h"

#include <belle-sip/utils.h>
#include <belle-sip/belle-sip.h>
#include "../src/belle_sip_internal.h"
#include "../src/listeningpoint_internal.h"
#include <belle-sip/msrp-message.h>
#include <belle-sip/msrp-headers.h>

#include "port.h"

typedef struct msrp_impl {
	belle_sip_object_t base;
} belle_msrp_impl_t;



#define BELLE_MSRP_IMPL(obj) BELLE_SIP_CAST(obj,belle_msrp_impl_t)


static belle_sip_channel_t *channel;

static void channel_state_changed(belle_sip_channel_listener_t *obj, belle_sip_channel_t *chan, belle_sip_channel_state_t state){
	switch(state){
		case BELLE_SIP_CHANNEL_READY:
			belle_sip_message("Ready!");
			channel = chan;
			break;
		default:
			channel = NULL;
	}
}

static void channel_on_message_headers(belle_sip_channel_listener_t *obj, belle_sip_channel_t *chan, belle_sip_message_t *msg){
	printf("%s\n", __FUNCTION__);
}

static void channel_on_message(belle_sip_channel_listener_t *obj, belle_sip_channel_t *chan, belle_sip_message_t *msg){
	printf("%s\n", __FUNCTION__);
}

static void channel_on_sending(belle_sip_channel_listener_t *obj, belle_sip_channel_t *chan, belle_sip_message_t *msg){
	printf("%s\n", __FUNCTION__);
}


static int channel_on_auth_requested(belle_sip_channel_listener_t *obj, belle_sip_channel_t *chan, const char* distinguished_name){
	printf("%s\n", __FUNCTION__);
	return 0;
}

static void msrp_impl_uninit(belle_msrp_impl_t* obj) {
	printf("%s\n", __FUNCTION__);
}

BELLE_SIP_IMPLEMENT_INTERFACE_BEGIN(belle_msrp_impl_t,belle_sip_channel_listener_t)
	channel_state_changed,
	channel_on_message_headers,
	channel_on_message,
	channel_on_sending,
	channel_on_auth_requested
BELLE_SIP_IMPLEMENT_INTERFACE_END

BELLE_SIP_DECLARE_IMPLEMENTED_INTERFACES_1(belle_msrp_impl_t,belle_sip_channel_listener_t);
BELLE_SIP_INSTANCIATE_VPTR(belle_msrp_impl_t,belle_sip_object_t,msrp_impl_uninit,NULL,NULL,FALSE);

static int read_stdin(void* data, unsigned int a) {
	char buffer[1024];
 	struct timeval tv;

	fd_set fds;
 	FD_ZERO(&fds);
 	FD_SET(STDIN_FILENO, &fds);
	tv.tv_sec = 0;
 	tv.tv_usec = 0;
   if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {
		fgets(buffer, 1024, stdin);
		buffer[strlen(buffer)-1] = '\0';

   	printf("########### MSG '%s'\n", buffer);
   	belle_msrp_request_t* msg = belle_msrp_request_new();
   	char transaction_id[20];
   	belle_sip_random_token(transaction_id, 20);
   	belle_msrp_request_set_method(msg, "SEND");
   	belle_msrp_request_set_transaction_id(msg, transaction_id);
   	belle_sip_message_add_header(BELLE_SIP_MESSAGE(msg), BELLE_SIP_HEADER(belle_sip_header_msrp_to_path_create("msrp://bob.example.com:8888/9di4eae923wzd;tcp")));
   	belle_sip_message_add_header(BELLE_SIP_MESSAGE(msg), BELLE_SIP_HEADER(belle_sip_header_msrp_from_path_create("msrp://alicepc.example.com:7777/iau39soe2843z;tcp")));


		belle_sip_memory_body_handler_t* body = belle_sip_memory_body_handler_new_from_buffer(strdup(buffer), strlen(buffer), NULL, NULL);
		belle_sip_message_set_body_handler(BELLE_SIP_MESSAGE(msg), BELLE_SIP_BODY_HANDLER(body));
   	belle_sip_channel_queue_message(channel, BELLE_SIP_MESSAGE(msg));
   }

	return BELLE_SIP_CONTINUE;
}










int main (int argc, char *argv[]) {
	int i;
	int server_mode = FALSE;
	int remote_port = 50000;
	belle_sip_source_t* source;

	belle_sip_stack_t* stack;
	belle_msrp_impl_t* msrp_channel_listener = NULL;

	belle_sip_set_log_level(BELLE_SIP_LOG_DEBUG);

	for(i=1; i<argc; i++){
		if (!strcmp(argv[i], "--server") || !strcmp(argv[i], "-s")) {
			server_mode = TRUE;
		} else if (!strcmp(argv[i], "--port") || !strcmp(argv[i], "-p")) {
			remote_port = atoi(argv[i+1]);
			i++;
		}
	}

	stack = belle_sip_stack_new(NULL);
	// implement msrp as channel listener
	msrp_channel_listener=belle_sip_object_new(belle_msrp_impl_t);

	belle_sip_object_ref(stack);
	belle_sip_object_ref(msrp_channel_listener);

	// TODO: create channel
	if (server_mode) {
		printf("MSRP server %d\n", remote_port);
		/* msrp tcp listening point */
		belle_sip_listening_point_t *lp;
		lp=belle_sip_stack_create_listening_point(stack,"0.0.0.0", remote_port,"TCP");
		belle_sip_listening_point_set_channel_listener(lp, (belle_sip_channel_listener_t*)msrp_channel_listener);
		belle_sip_object_ref(lp);
	} else {
		/* msrp tcp channel */
		printf("MSRP client %d\n", remote_port);
		belle_sip_channel_t* channel = belle_sip_stream_channel_new_client(stack
																, NULL
																, 30000 + rand() % 30000
																, NULL
																, "127.0.0.1"
																, remote_port);
		belle_sip_channel_add_listener(channel, (belle_sip_channel_listener_t*)msrp_channel_listener);
		belle_sip_channel_prepare(channel);
		belle_sip_object_ref(channel);
	}
	source = belle_sip_fd_source_new(read_stdin, NULL, STDIN_FILENO, BELLE_SIP_EVENT_READ, -1);
	belle_sip_main_loop_add_source(stack->ml, source);


	belle_sip_stack_main(stack);
}

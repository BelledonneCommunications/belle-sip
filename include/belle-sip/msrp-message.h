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
#ifndef BELLE_MSRP_MESSAGE_H
#define BELLE_MSRP_MESSAGE_H

#include "belle-sip/generic-uri.h"

#define BELLE_MSRP_REQUEST(obj)		BELLE_SIP_CAST(obj,belle_msrp_request_t)
#define BELLE_MSRP_RESPONSE(obj)	BELLE_SIP_CAST(obj,belle_msrp_response_t)

BELLE_SIP_BEGIN_DECLS

BELLESIP_EXPORT belle_msrp_request_t* belle_msrp_request_new(void);
BELLESIP_EXPORT belle_msrp_request_t* belle_msrp_request_parse(const char* raw);

BELLESIP_EXPORT const char* belle_msrp_request_get_method(const belle_msrp_request_t* request);
BELLESIP_EXPORT void belle_msrp_request_set_method(belle_msrp_request_t* request,const char* method);

BELLESIP_EXPORT const char* belle_msrp_request_get_transaction_id(const belle_msrp_request_t* request);
BELLESIP_EXPORT void belle_msrp_request_set_transaction_id(belle_msrp_request_t* request,const char* transction_id);


BELLESIP_EXPORT belle_msrp_response_t *belle_msrp_response_new(void);


BELLE_SIP_END_DECLS

#endif

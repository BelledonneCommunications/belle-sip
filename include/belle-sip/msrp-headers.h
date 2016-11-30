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

#ifndef MSRP_HEADERS_H_
#define MSRP_HEADERS_H_

#include "belle-sip/defs.h"
#include "belle-sip/sip-uri.h"
#include "belle-sip/generic-uri.h"
#include "belle-sip/utils.h"
#include "belle-sip/parameters.h"

#include <time.h>

BELLE_SIP_BEGIN_DECLS

/* To-Path */
typedef struct _belle_sip_header_msrp_to_path belle_sip_header_msrp_to_path_t;

BELLESIP_EXPORT belle_sip_header_msrp_to_path_t* belle_sip_header_msrp_to_path_new(void);
BELLESIP_EXPORT belle_sip_header_msrp_to_path_t* belle_sip_header_msrp_to_path_parse(const char* to_path);
BELLESIP_EXPORT belle_sip_header_msrp_to_path_t* belle_sip_header_msrp_to_path_create (const char* uri) ;

BELLESIP_EXPORT const char* belle_sip_header_msrp_to_path_get_uri(const belle_sip_header_msrp_to_path_t* msrp_to_path);
BELLESIP_EXPORT void belle_sip_header_msrp_to_path_set_uri(belle_sip_header_msrp_to_path_t* msrp_to_path,const char* uri);

#define BELLE_SIP_HEADER_MSRP_TO_PATH(t) BELLE_SIP_CAST(t,belle_sip_header_msrp_to_path_t)
#define BELLE_SIP_MSRP_TO_PATH "To-Path"

/* From-Path */
typedef struct _belle_sip_header_msrp_from_path belle_sip_header_msrp_from_path_t;

BELLESIP_EXPORT belle_sip_header_msrp_from_path_t* belle_sip_header_msrp_from_path_new(void);
BELLESIP_EXPORT belle_sip_header_msrp_from_path_t* belle_sip_header_msrp_from_path_parse(const char* from_path);
BELLESIP_EXPORT belle_sip_header_msrp_from_path_t* belle_sip_header_msrp_from_path_create (const char* uri) ;

BELLESIP_EXPORT const char* belle_sip_header_msrp_from_path_get_uri(const belle_sip_header_msrp_from_path_t* msrp_from_path);
BELLESIP_EXPORT void belle_sip_header_msrp_from_path_set_uri(belle_sip_header_msrp_from_path_t* msrp_from_path,const char* uri);

#define BELLE_SIP_HEADER_MSRP_FROM_PATH(t) BELLE_SIP_CAST(t,belle_sip_header_msrp_from_path_t)
#define BELLE_SIP_MSRP_FROM_PATH "From-Path"

BELLE_SIP_END_DECLS


#endif /* MSRP_HEADERS_H_ */

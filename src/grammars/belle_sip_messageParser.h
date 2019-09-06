/*
 * Copyright (c) 2012-2019 Belledonne Communications SARL.
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
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_belle_sip_messageParser_H
#define _belle_sip_messageParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */
 

#include "belle-sip/defs.h"
#include "belle-sip/types.h"
#include "belle-sip/message.h"
#include "belle-sip/http-message.h"
#include "parserutils.h"
BELLESIP_EXPORT void belle_sip_header_address_set_quoted_displayname(belle_sip_header_address_t* address,const char* value);


#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct belle_sip_messageParser_Ctx_struct belle_sip_messageParser, * pbelle_sip_messageParser;



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

#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wunused"
#ifndef __clang__
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-function"
#endif


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/* ========================
 * BACKTRACKING IS ENABLED
 * ========================
 */

typedef struct belle_sip_messageParser_method_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_method_return;



typedef struct belle_sip_messageParser_status_code_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_status_code_return;



typedef struct belle_sip_messageParser_reason_phrase_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_reason_phrase_return;



typedef struct belle_sip_messageParser_opaque_part_for_from_to_contact_addr_spec_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_opaque_part_for_from_to_contact_addr_spec_return;



typedef struct belle_sip_messageParser_opaque_part_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_opaque_part_return;



typedef struct belle_sip_messageParser_scheme_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_scheme_return;



typedef struct belle_sip_messageParser_path_segments_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_path_segments_return;



typedef struct belle_sip_messageParser_query_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_query_return;



typedef struct belle_sip_messageParser_authority_user_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_authority_user_return;



typedef struct belle_sip_messageParser_authority_password_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_authority_password_return;



typedef struct belle_sip_messageParser_gen_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_gen_value_return;



typedef struct belle_sip_messageParser_quoted_string_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_quoted_string_return;



typedef struct belle_sip_messageParser_methods_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_methods_return;



typedef struct belle_sip_messageParser_username_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_username_value_return;



typedef struct belle_sip_messageParser_qop_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_qop_value_return;



typedef struct belle_sip_messageParser_cnonce_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_cnonce_value_return;



typedef struct belle_sip_messageParser_nc_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_nc_value_return;



typedef struct belle_sip_messageParser_request_digest_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_request_digest_return;



typedef struct belle_sip_messageParser_auth_param_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_auth_param_value_return;



typedef struct belle_sip_messageParser_auth_param_name_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_auth_param_name_return;



typedef struct belle_sip_messageParser_auth_scheme_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_auth_scheme_return;



typedef struct belle_sip_messageParser_nonce_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_nonce_value_return;



typedef struct belle_sip_messageParser_call_id_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_call_id_return;



typedef struct belle_sip_messageParser_retry_after_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_retry_after_return;



typedef struct belle_sip_messageParser_display_name_tokens_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_display_name_tokens_return;



typedef struct belle_sip_messageParser_delta_seconds_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_delta_seconds_return;



typedef struct belle_sip_messageParser_content_length_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_content_length_return;



typedef struct belle_sip_messageParser_m_type_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_m_type_return;



typedef struct belle_sip_messageParser_type_param_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_type_param_value_return;



typedef struct belle_sip_messageParser_m_subtype_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_m_subtype_return;



typedef struct belle_sip_messageParser_seq_number_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_seq_number_return;



typedef struct belle_sip_messageParser_sip_date_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_sip_date_return;



typedef struct belle_sip_messageParser_max_forwards_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_max_forwards_return;



typedef struct belle_sip_messageParser_realm_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_realm_value_return;



typedef struct belle_sip_messageParser_stale_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_stale_value_return;



typedef struct belle_sip_messageParser_via_address_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_via_address_return;



typedef struct belle_sip_messageParser_sent_protocol_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_sent_protocol_return;



typedef struct belle_sip_messageParser_transport_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_transport_return;



typedef struct belle_sip_messageParser_state_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_state_value_return;



typedef struct belle_sip_messageParser_event_package_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_event_package_return;



typedef struct belle_sip_messageParser_content_disposition_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_content_disposition_value_return;



typedef struct belle_sip_messageParser_accept_main_media_type_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_accept_main_media_type_return;



typedef struct belle_sip_messageParser_accept_sub_media_type_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_accept_sub_media_type_return;



typedef struct belle_sip_messageParser_header_reason_protocol_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_header_reason_protocol_return;



typedef struct belle_sip_messageParser_header_name_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_header_name_return;



typedef struct belle_sip_messageParser_header_value_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    belle_sip_header_t* ret;
}
    belle_sip_messageParser_header_value_return;



typedef struct belle_sip_messageParser_user_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_user_return;



typedef struct belle_sip_messageParser_password_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_password_return;



typedef struct belle_sip_messageParser_pname_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_pname_return;



typedef struct belle_sip_messageParser_pvalue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_pvalue_return;



typedef struct belle_sip_messageParser_hname_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_hname_return;



typedef struct belle_sip_messageParser_hvalue_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_hvalue_return;



typedef struct belle_sip_messageParser_fast_hostname_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_fast_hostname_return;



typedef struct belle_sip_messageParser_hostname_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_hostname_return;



typedef struct belle_sip_messageParser_ipv4address_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_ipv4address_return;



typedef struct belle_sip_messageParser_ipv6address_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_ipv6address_return;



typedef struct belle_sip_messageParser_port_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    int ret;
}
    belle_sip_messageParser_port_return;



typedef struct belle_sip_messageParser_token_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_token_return;



typedef struct belle_sip_messageParser_word_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
}
    belle_sip_messageParser_word_return;





/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the message scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_messagePush().
 */
typedef struct  belle_sip_messageParser_message_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_message_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    size_t message_length;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_message_SCOPE, * pbelle_sip_messageParser_message_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the message_raw scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_message_rawPush().
 */
typedef struct  belle_sip_messageParser_message_raw_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_message_raw_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    size_t* message_length;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_message_raw_SCOPE, * pbelle_sip_messageParser_message_raw_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the common_request scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_common_requestPush().
 */
typedef struct  belle_sip_messageParser_common_request_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_common_request_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_message_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_common_request_SCOPE, * pbelle_sip_messageParser_common_request_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the request_line scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_request_linePush().
 */
typedef struct  belle_sip_messageParser_request_line_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_request_line_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_request_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_request_line_SCOPE, * pbelle_sip_messageParser_request_line_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the status_line scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_status_linePush().
 */
typedef struct  belle_sip_messageParser_status_line_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_status_line_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_response_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_status_line_SCOPE, * pbelle_sip_messageParser_status_line_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the http_request_line scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_http_request_linePush().
 */
typedef struct  belle_sip_messageParser_http_request_line_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_http_request_line_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_http_request_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_http_request_line_SCOPE, * pbelle_sip_messageParser_http_request_line_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the generic_uri_for_from_to_contact_addr_spec scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_generic_uri_for_from_to_contact_addr_specPush().
 */
typedef struct  belle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_generic_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE, * pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the generic_uri scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_generic_uriPush().
 */
typedef struct  belle_sip_messageParser_generic_uri_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_generic_uri_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_generic_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_generic_uri_SCOPE, * pbelle_sip_messageParser_generic_uri_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the authority_userinfo scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_authority_userinfoPush().
 */
typedef struct  belle_sip_messageParser_authority_userinfo_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_authority_userinfo_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_generic_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_authority_userinfo_SCOPE, * pbelle_sip_messageParser_authority_userinfo_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the authority_hostport scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_authority_hostportPush().
 */
typedef struct  belle_sip_messageParser_authority_hostport_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_authority_hostport_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_generic_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_authority_hostport_SCOPE, * pbelle_sip_messageParser_authority_hostport_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the generic_param scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_generic_paramPush().
 */
typedef struct  belle_sip_messageParser_generic_param_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_generic_param_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    int is_value;
    char* gen_value_string;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_generic_param_SCOPE, * pbelle_sip_messageParser_generic_param_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_allow scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_allowPush().
 */
typedef struct  belle_sip_messageParser_header_allow_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_allow_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_allow_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_allow_SCOPE, * pbelle_sip_messageParser_header_allow_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_authorization scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_authorizationPush().
 */
typedef struct  belle_sip_messageParser_header_authorization_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_authorization_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_authorization_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_authorization_SCOPE, * pbelle_sip_messageParser_header_authorization_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_call_id scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_call_idPush().
 */
typedef struct  belle_sip_messageParser_header_call_id_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_call_id_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_call_id_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_call_id_SCOPE, * pbelle_sip_messageParser_header_call_id_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_retry_after scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_retry_afterPush().
 */
typedef struct  belle_sip_messageParser_header_retry_after_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_retry_after_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_retry_after_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_retry_after_SCOPE, * pbelle_sip_messageParser_header_retry_after_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_contact scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_contactPush().
 */
typedef struct  belle_sip_messageParser_header_contact_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_contact_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_contact_t* current;
    belle_sip_header_contact_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_contact_SCOPE, * pbelle_sip_messageParser_header_contact_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the contact_param scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_contact_paramPush().
 */
typedef struct  belle_sip_messageParser_contact_param_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_contact_param_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_contact_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_contact_param_SCOPE, * pbelle_sip_messageParser_contact_param_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_content_length scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_content_lengthPush().
 */
typedef struct  belle_sip_messageParser_header_content_length_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_content_length_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_content_length_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_content_length_SCOPE, * pbelle_sip_messageParser_header_content_length_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_content_type scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_content_typePush().
 */
typedef struct  belle_sip_messageParser_header_content_type_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_content_type_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_content_type_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_content_type_SCOPE, * pbelle_sip_messageParser_header_content_type_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_cseq scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_cseqPush().
 */
typedef struct  belle_sip_messageParser_header_cseq_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_cseq_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_cseq_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_cseq_SCOPE, * pbelle_sip_messageParser_header_cseq_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_date scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_datePush().
 */
typedef struct  belle_sip_messageParser_header_date_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_date_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_date_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_date_SCOPE, * pbelle_sip_messageParser_header_date_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_expires scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_expiresPush().
 */
typedef struct  belle_sip_messageParser_header_expires_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_expires_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_expires_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_expires_SCOPE, * pbelle_sip_messageParser_header_expires_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_from scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_fromPush().
 */
typedef struct  belle_sip_messageParser_header_from_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_from_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_from_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_from_SCOPE, * pbelle_sip_messageParser_header_from_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_max_forwards scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_max_forwardsPush().
 */
typedef struct  belle_sip_messageParser_header_max_forwards_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_max_forwards_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_max_forwards_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_max_forwards_SCOPE, * pbelle_sip_messageParser_header_max_forwards_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_proxy_authenticate scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_proxy_authenticatePush().
 */
typedef struct  belle_sip_messageParser_header_proxy_authenticate_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_proxy_authenticate_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_proxy_authenticate_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_proxy_authenticate_SCOPE, * pbelle_sip_messageParser_header_proxy_authenticate_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the qop_opts scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_qop_optsPush().
 */
typedef struct  belle_sip_messageParser_qop_opts_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_qop_opts_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_list_t* list;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_qop_opts_SCOPE, * pbelle_sip_messageParser_qop_opts_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_proxy_authorization scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_proxy_authorizationPush().
 */
typedef struct  belle_sip_messageParser_header_proxy_authorization_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_proxy_authorization_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_proxy_authorization_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_proxy_authorization_SCOPE, * pbelle_sip_messageParser_header_proxy_authorization_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_service_route scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_service_routePush().
 */
typedef struct  belle_sip_messageParser_header_service_route_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_service_route_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_service_route_t* current;
    belle_sip_header_service_route_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_service_route_SCOPE, * pbelle_sip_messageParser_header_service_route_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the srv_route scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_srv_routePush().
 */
typedef struct  belle_sip_messageParser_srv_route_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_srv_route_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_service_route_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_srv_route_SCOPE, * pbelle_sip_messageParser_srv_route_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_record_route scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_record_routePush().
 */
typedef struct  belle_sip_messageParser_header_record_route_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_record_route_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_record_route_t* current;
    belle_sip_header_record_route_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_record_route_SCOPE, * pbelle_sip_messageParser_header_record_route_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the rec_route scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_rec_routePush().
 */
typedef struct  belle_sip_messageParser_rec_route_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_rec_route_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_record_route_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_rec_route_SCOPE, * pbelle_sip_messageParser_rec_route_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_route scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_routePush().
 */
typedef struct  belle_sip_messageParser_header_route_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_route_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_route_t* current;
    belle_sip_header_route_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_route_SCOPE, * pbelle_sip_messageParser_header_route_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the route_param scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_route_paramPush().
 */
typedef struct  belle_sip_messageParser_route_param_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_route_param_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_route_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_route_param_SCOPE, * pbelle_sip_messageParser_route_param_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_to scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_toPush().
 */
typedef struct  belle_sip_messageParser_header_to_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_to_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_to_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_to_SCOPE, * pbelle_sip_messageParser_header_to_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_diversion scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_diversionPush().
 */
typedef struct  belle_sip_messageParser_header_diversion_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_diversion_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_diversion_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_diversion_SCOPE, * pbelle_sip_messageParser_header_diversion_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_user_agent scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_user_agentPush().
 */
typedef struct  belle_sip_messageParser_header_user_agent_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_user_agent_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_user_agent_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_user_agent_SCOPE, * pbelle_sip_messageParser_header_user_agent_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_via scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_viaPush().
 */
typedef struct  belle_sip_messageParser_header_via_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_via_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_via_t* current;
    belle_sip_header_via_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_via_SCOPE, * pbelle_sip_messageParser_header_via_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the via_parm scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_via_parmPush().
 */
typedef struct  belle_sip_messageParser_via_parm_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_via_parm_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_via_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_via_parm_SCOPE, * pbelle_sip_messageParser_via_parm_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_www_authenticate scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_www_authenticatePush().
 */
typedef struct  belle_sip_messageParser_header_www_authenticate_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_www_authenticate_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_www_authenticate_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_www_authenticate_SCOPE, * pbelle_sip_messageParser_header_www_authenticate_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_subscription_state scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_subscription_statePush().
 */
typedef struct  belle_sip_messageParser_header_subscription_state_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_subscription_state_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_subscription_state_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_subscription_state_SCOPE, * pbelle_sip_messageParser_header_subscription_state_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_event scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_eventPush().
 */
typedef struct  belle_sip_messageParser_header_event_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_event_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_event_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_event_SCOPE, * pbelle_sip_messageParser_header_event_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_replaces scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_replacesPush().
 */
typedef struct  belle_sip_messageParser_header_replaces_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_replaces_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_replaces_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_replaces_SCOPE, * pbelle_sip_messageParser_header_replaces_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_privacy scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_privacyPush().
 */
typedef struct  belle_sip_messageParser_header_privacy_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_privacy_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_privacy_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_privacy_SCOPE, * pbelle_sip_messageParser_header_privacy_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_supported scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_supportedPush().
 */
typedef struct  belle_sip_messageParser_header_supported_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_supported_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_supported_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_supported_SCOPE, * pbelle_sip_messageParser_header_supported_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_require scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_requirePush().
 */
typedef struct  belle_sip_messageParser_header_require_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_require_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_require_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_require_SCOPE, * pbelle_sip_messageParser_header_require_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_content_disposition scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_content_dispositionPush().
 */
typedef struct  belle_sip_messageParser_header_content_disposition_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_content_disposition_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_content_disposition_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_content_disposition_SCOPE, * pbelle_sip_messageParser_header_content_disposition_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_accept scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_acceptPush().
 */
typedef struct  belle_sip_messageParser_header_accept_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_accept_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_accept_t* current;
    belle_sip_header_accept_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_accept_SCOPE, * pbelle_sip_messageParser_header_accept_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the accept_param scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_accept_paramPush().
 */
typedef struct  belle_sip_messageParser_accept_param_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_accept_param_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_accept_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_accept_param_SCOPE, * pbelle_sip_messageParser_accept_param_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_reason scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_reasonPush().
 */
typedef struct  belle_sip_messageParser_header_reason_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_reason_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_reason_t* current;
    belle_sip_header_reason_t* first;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_reason_SCOPE, * pbelle_sip_messageParser_header_reason_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_reason_param scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_reason_paramPush().
 */
typedef struct  belle_sip_messageParser_header_reason_param_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_reason_param_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_reason_t* prev;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_reason_param_SCOPE, * pbelle_sip_messageParser_header_reason_param_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_authentication_info scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_authentication_infoPush().
 */
typedef struct  belle_sip_messageParser_header_authentication_info_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_authentication_info_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_header_authentication_info_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_authentication_info_SCOPE, * pbelle_sip_messageParser_header_authentication_info_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the header_extension_base scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_header_extension_basePush().
 */
typedef struct  belle_sip_messageParser_header_extension_base_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_header_extension_base_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    int as_value;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_header_extension_base_SCOPE, * pbelle_sip_messageParser_header_extension_base_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the paramless_uri scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_paramless_uriPush().
 */
typedef struct  belle_sip_messageParser_paramless_uri_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_paramless_uri_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_paramless_uri_SCOPE, * pbelle_sip_messageParser_paramless_uri_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the uri scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_uriPush().
 */
typedef struct  belle_sip_messageParser_uri_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_uri_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_uri_SCOPE, * pbelle_sip_messageParser_uri_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the fast_uri scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_fast_uriPush().
 */
typedef struct  belle_sip_messageParser_fast_uri_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_fast_uri_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_fast_uri_SCOPE, * pbelle_sip_messageParser_fast_uri_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the userinfo scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_userinfoPush().
 */
typedef struct  belle_sip_messageParser_userinfo_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_userinfo_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_userinfo_SCOPE, * pbelle_sip_messageParser_userinfo_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the hostport scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_hostportPush().
 */
typedef struct  belle_sip_messageParser_hostport_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_hostport_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_hostport_SCOPE, * pbelle_sip_messageParser_hostport_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the fast_hostport scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_fast_hostportPush().
 */
typedef struct  belle_sip_messageParser_fast_hostport_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_fast_hostport_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_fast_hostport_SCOPE, * pbelle_sip_messageParser_fast_hostport_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the uri_parameters scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_uri_parametersPush().
 */
typedef struct  belle_sip_messageParser_uri_parameters_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_uri_parameters_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_uri_parameters_SCOPE, * pbelle_sip_messageParser_uri_parameters_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the headers scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_headersPush().
 */
typedef struct  belle_sip_messageParser_headers_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_headers_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    belle_sip_uri_t* current;
    int is_hvalue;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_headers_SCOPE, * pbelle_sip_messageParser_headers_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the uri_header scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_uri_headerPush().
 */
typedef struct  belle_sip_messageParser_uri_header_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_uri_header_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    int is_hvalue;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_uri_header_SCOPE, * pbelle_sip_messageParser_uri_header_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the fast_host scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_fast_hostPush().
 */
typedef struct  belle_sip_messageParser_fast_host_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_fast_host_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    const char* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_fast_host_SCOPE, * pbelle_sip_messageParser_fast_host_SCOPE;


/* ruleAttributeScopeDecl(scope)
 */
/* makeScopeSet()
 */
 /** Definition of the host scope variable tracking
 *  structure. An instance of this structure is created by calling
 *  belle_sip_messageParser_hostPush().
 */
typedef struct  belle_sip_messageParser_host_SCOPE_struct
{
    /** Function that the user may provide to be called when the
     *  scope is destroyed (so you can free pANTLR3_HASH_TABLES and so on)
     *
     * \param POinter to an instance of this typedef/struct
     */
    void    (ANTLR3_CDECL *free)	(struct belle_sip_messageParser_host_SCOPE_struct * frame);

    /* =============================================================================
     * Programmer defined variables...
     */
    const char* current;

    /* End of programmer defined variables
     * =============================================================================
     */
}
    belle_sip_messageParser_host_SCOPE, * pbelle_sip_messageParser_host_SCOPE;


/** Context tracking structure for 
belle_sip_messageParser

 */
struct belle_sip_messageParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;
    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  message stack for use by pbelle_sip_messageParser_messagePush()
     *  and pbelle_sip_messageParser_messagePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_messageStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_messageStack_limit;
    pbelle_sip_messageParser_message_SCOPE   (*pbelle_sip_messageParser_messagePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_message_SCOPE   pbelle_sip_messageParser_messageTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  message_raw stack for use by pbelle_sip_messageParser_message_rawPush()
     *  and pbelle_sip_messageParser_message_rawPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_message_rawStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_message_rawStack_limit;
    pbelle_sip_messageParser_message_raw_SCOPE   (*pbelle_sip_messageParser_message_rawPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_message_raw_SCOPE   pbelle_sip_messageParser_message_rawTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  common_request stack for use by pbelle_sip_messageParser_common_requestPush()
     *  and pbelle_sip_messageParser_common_requestPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_common_requestStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_common_requestStack_limit;
    pbelle_sip_messageParser_common_request_SCOPE   (*pbelle_sip_messageParser_common_requestPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_common_request_SCOPE   pbelle_sip_messageParser_common_requestTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  request_line stack for use by pbelle_sip_messageParser_request_linePush()
     *  and pbelle_sip_messageParser_request_linePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_request_lineStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_request_lineStack_limit;
    pbelle_sip_messageParser_request_line_SCOPE   (*pbelle_sip_messageParser_request_linePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_request_line_SCOPE   pbelle_sip_messageParser_request_lineTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  status_line stack for use by pbelle_sip_messageParser_status_linePush()
     *  and pbelle_sip_messageParser_status_linePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_status_lineStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_status_lineStack_limit;
    pbelle_sip_messageParser_status_line_SCOPE   (*pbelle_sip_messageParser_status_linePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_status_line_SCOPE   pbelle_sip_messageParser_status_lineTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  http_request_line stack for use by pbelle_sip_messageParser_http_request_linePush()
     *  and pbelle_sip_messageParser_http_request_linePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_http_request_lineStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_http_request_lineStack_limit;
    pbelle_sip_messageParser_http_request_line_SCOPE   (*pbelle_sip_messageParser_http_request_linePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_http_request_line_SCOPE   pbelle_sip_messageParser_http_request_lineTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  generic_uri_for_from_to_contact_addr_spec stack for use by pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specPush()
     *  and pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specStack_limit;
    pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE   (*pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_spec_SCOPE   pbelle_sip_messageParser_generic_uri_for_from_to_contact_addr_specTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  generic_uri stack for use by pbelle_sip_messageParser_generic_uriPush()
     *  and pbelle_sip_messageParser_generic_uriPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_generic_uriStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_generic_uriStack_limit;
    pbelle_sip_messageParser_generic_uri_SCOPE   (*pbelle_sip_messageParser_generic_uriPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_generic_uri_SCOPE   pbelle_sip_messageParser_generic_uriTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  authority_userinfo stack for use by pbelle_sip_messageParser_authority_userinfoPush()
     *  and pbelle_sip_messageParser_authority_userinfoPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_authority_userinfoStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_authority_userinfoStack_limit;
    pbelle_sip_messageParser_authority_userinfo_SCOPE   (*pbelle_sip_messageParser_authority_userinfoPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_authority_userinfo_SCOPE   pbelle_sip_messageParser_authority_userinfoTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  authority_hostport stack for use by pbelle_sip_messageParser_authority_hostportPush()
     *  and pbelle_sip_messageParser_authority_hostportPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_authority_hostportStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_authority_hostportStack_limit;
    pbelle_sip_messageParser_authority_hostport_SCOPE   (*pbelle_sip_messageParser_authority_hostportPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_authority_hostport_SCOPE   pbelle_sip_messageParser_authority_hostportTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  generic_param stack for use by pbelle_sip_messageParser_generic_paramPush()
     *  and pbelle_sip_messageParser_generic_paramPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_generic_paramStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_generic_paramStack_limit;
    pbelle_sip_messageParser_generic_param_SCOPE   (*pbelle_sip_messageParser_generic_paramPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_generic_param_SCOPE   pbelle_sip_messageParser_generic_paramTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_allow stack for use by pbelle_sip_messageParser_header_allowPush()
     *  and pbelle_sip_messageParser_header_allowPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_allowStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_allowStack_limit;
    pbelle_sip_messageParser_header_allow_SCOPE   (*pbelle_sip_messageParser_header_allowPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_allow_SCOPE   pbelle_sip_messageParser_header_allowTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_authorization stack for use by pbelle_sip_messageParser_header_authorizationPush()
     *  and pbelle_sip_messageParser_header_authorizationPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_authorizationStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_authorizationStack_limit;
    pbelle_sip_messageParser_header_authorization_SCOPE   (*pbelle_sip_messageParser_header_authorizationPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_authorization_SCOPE   pbelle_sip_messageParser_header_authorizationTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_call_id stack for use by pbelle_sip_messageParser_header_call_idPush()
     *  and pbelle_sip_messageParser_header_call_idPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_call_idStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_call_idStack_limit;
    pbelle_sip_messageParser_header_call_id_SCOPE   (*pbelle_sip_messageParser_header_call_idPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_call_id_SCOPE   pbelle_sip_messageParser_header_call_idTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_retry_after stack for use by pbelle_sip_messageParser_header_retry_afterPush()
     *  and pbelle_sip_messageParser_header_retry_afterPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_retry_afterStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_retry_afterStack_limit;
    pbelle_sip_messageParser_header_retry_after_SCOPE   (*pbelle_sip_messageParser_header_retry_afterPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_retry_after_SCOPE   pbelle_sip_messageParser_header_retry_afterTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_contact stack for use by pbelle_sip_messageParser_header_contactPush()
     *  and pbelle_sip_messageParser_header_contactPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_contactStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_contactStack_limit;
    pbelle_sip_messageParser_header_contact_SCOPE   (*pbelle_sip_messageParser_header_contactPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_contact_SCOPE   pbelle_sip_messageParser_header_contactTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  contact_param stack for use by pbelle_sip_messageParser_contact_paramPush()
     *  and pbelle_sip_messageParser_contact_paramPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_contact_paramStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_contact_paramStack_limit;
    pbelle_sip_messageParser_contact_param_SCOPE   (*pbelle_sip_messageParser_contact_paramPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_contact_param_SCOPE   pbelle_sip_messageParser_contact_paramTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_content_length stack for use by pbelle_sip_messageParser_header_content_lengthPush()
     *  and pbelle_sip_messageParser_header_content_lengthPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_content_lengthStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_content_lengthStack_limit;
    pbelle_sip_messageParser_header_content_length_SCOPE   (*pbelle_sip_messageParser_header_content_lengthPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_content_length_SCOPE   pbelle_sip_messageParser_header_content_lengthTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_content_type stack for use by pbelle_sip_messageParser_header_content_typePush()
     *  and pbelle_sip_messageParser_header_content_typePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_content_typeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_content_typeStack_limit;
    pbelle_sip_messageParser_header_content_type_SCOPE   (*pbelle_sip_messageParser_header_content_typePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_content_type_SCOPE   pbelle_sip_messageParser_header_content_typeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_cseq stack for use by pbelle_sip_messageParser_header_cseqPush()
     *  and pbelle_sip_messageParser_header_cseqPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_cseqStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_cseqStack_limit;
    pbelle_sip_messageParser_header_cseq_SCOPE   (*pbelle_sip_messageParser_header_cseqPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_cseq_SCOPE   pbelle_sip_messageParser_header_cseqTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_date stack for use by pbelle_sip_messageParser_header_datePush()
     *  and pbelle_sip_messageParser_header_datePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_dateStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_dateStack_limit;
    pbelle_sip_messageParser_header_date_SCOPE   (*pbelle_sip_messageParser_header_datePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_date_SCOPE   pbelle_sip_messageParser_header_dateTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_expires stack for use by pbelle_sip_messageParser_header_expiresPush()
     *  and pbelle_sip_messageParser_header_expiresPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_expiresStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_expiresStack_limit;
    pbelle_sip_messageParser_header_expires_SCOPE   (*pbelle_sip_messageParser_header_expiresPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_expires_SCOPE   pbelle_sip_messageParser_header_expiresTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_from stack for use by pbelle_sip_messageParser_header_fromPush()
     *  and pbelle_sip_messageParser_header_fromPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_fromStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_fromStack_limit;
    pbelle_sip_messageParser_header_from_SCOPE   (*pbelle_sip_messageParser_header_fromPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_from_SCOPE   pbelle_sip_messageParser_header_fromTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_max_forwards stack for use by pbelle_sip_messageParser_header_max_forwardsPush()
     *  and pbelle_sip_messageParser_header_max_forwardsPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_max_forwardsStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_max_forwardsStack_limit;
    pbelle_sip_messageParser_header_max_forwards_SCOPE   (*pbelle_sip_messageParser_header_max_forwardsPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_max_forwards_SCOPE   pbelle_sip_messageParser_header_max_forwardsTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_proxy_authenticate stack for use by pbelle_sip_messageParser_header_proxy_authenticatePush()
     *  and pbelle_sip_messageParser_header_proxy_authenticatePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_proxy_authenticateStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_proxy_authenticateStack_limit;
    pbelle_sip_messageParser_header_proxy_authenticate_SCOPE   (*pbelle_sip_messageParser_header_proxy_authenticatePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_proxy_authenticate_SCOPE   pbelle_sip_messageParser_header_proxy_authenticateTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  qop_opts stack for use by pbelle_sip_messageParser_qop_optsPush()
     *  and pbelle_sip_messageParser_qop_optsPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_qop_optsStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_qop_optsStack_limit;
    pbelle_sip_messageParser_qop_opts_SCOPE   (*pbelle_sip_messageParser_qop_optsPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_qop_opts_SCOPE   pbelle_sip_messageParser_qop_optsTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_proxy_authorization stack for use by pbelle_sip_messageParser_header_proxy_authorizationPush()
     *  and pbelle_sip_messageParser_header_proxy_authorizationPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_proxy_authorizationStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_proxy_authorizationStack_limit;
    pbelle_sip_messageParser_header_proxy_authorization_SCOPE   (*pbelle_sip_messageParser_header_proxy_authorizationPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_proxy_authorization_SCOPE   pbelle_sip_messageParser_header_proxy_authorizationTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_service_route stack for use by pbelle_sip_messageParser_header_service_routePush()
     *  and pbelle_sip_messageParser_header_service_routePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_service_routeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_service_routeStack_limit;
    pbelle_sip_messageParser_header_service_route_SCOPE   (*pbelle_sip_messageParser_header_service_routePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_service_route_SCOPE   pbelle_sip_messageParser_header_service_routeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  srv_route stack for use by pbelle_sip_messageParser_srv_routePush()
     *  and pbelle_sip_messageParser_srv_routePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_srv_routeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_srv_routeStack_limit;
    pbelle_sip_messageParser_srv_route_SCOPE   (*pbelle_sip_messageParser_srv_routePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_srv_route_SCOPE   pbelle_sip_messageParser_srv_routeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_record_route stack for use by pbelle_sip_messageParser_header_record_routePush()
     *  and pbelle_sip_messageParser_header_record_routePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_record_routeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_record_routeStack_limit;
    pbelle_sip_messageParser_header_record_route_SCOPE   (*pbelle_sip_messageParser_header_record_routePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_record_route_SCOPE   pbelle_sip_messageParser_header_record_routeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  rec_route stack for use by pbelle_sip_messageParser_rec_routePush()
     *  and pbelle_sip_messageParser_rec_routePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_rec_routeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_rec_routeStack_limit;
    pbelle_sip_messageParser_rec_route_SCOPE   (*pbelle_sip_messageParser_rec_routePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_rec_route_SCOPE   pbelle_sip_messageParser_rec_routeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_route stack for use by pbelle_sip_messageParser_header_routePush()
     *  and pbelle_sip_messageParser_header_routePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_routeStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_routeStack_limit;
    pbelle_sip_messageParser_header_route_SCOPE   (*pbelle_sip_messageParser_header_routePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_route_SCOPE   pbelle_sip_messageParser_header_routeTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  route_param stack for use by pbelle_sip_messageParser_route_paramPush()
     *  and pbelle_sip_messageParser_route_paramPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_route_paramStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_route_paramStack_limit;
    pbelle_sip_messageParser_route_param_SCOPE   (*pbelle_sip_messageParser_route_paramPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_route_param_SCOPE   pbelle_sip_messageParser_route_paramTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_to stack for use by pbelle_sip_messageParser_header_toPush()
     *  and pbelle_sip_messageParser_header_toPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_toStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_toStack_limit;
    pbelle_sip_messageParser_header_to_SCOPE   (*pbelle_sip_messageParser_header_toPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_to_SCOPE   pbelle_sip_messageParser_header_toTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_diversion stack for use by pbelle_sip_messageParser_header_diversionPush()
     *  and pbelle_sip_messageParser_header_diversionPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_diversionStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_diversionStack_limit;
    pbelle_sip_messageParser_header_diversion_SCOPE   (*pbelle_sip_messageParser_header_diversionPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_diversion_SCOPE   pbelle_sip_messageParser_header_diversionTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_user_agent stack for use by pbelle_sip_messageParser_header_user_agentPush()
     *  and pbelle_sip_messageParser_header_user_agentPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_user_agentStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_user_agentStack_limit;
    pbelle_sip_messageParser_header_user_agent_SCOPE   (*pbelle_sip_messageParser_header_user_agentPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_user_agent_SCOPE   pbelle_sip_messageParser_header_user_agentTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_via stack for use by pbelle_sip_messageParser_header_viaPush()
     *  and pbelle_sip_messageParser_header_viaPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_viaStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_viaStack_limit;
    pbelle_sip_messageParser_header_via_SCOPE   (*pbelle_sip_messageParser_header_viaPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_via_SCOPE   pbelle_sip_messageParser_header_viaTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  via_parm stack for use by pbelle_sip_messageParser_via_parmPush()
     *  and pbelle_sip_messageParser_via_parmPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_via_parmStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_via_parmStack_limit;
    pbelle_sip_messageParser_via_parm_SCOPE   (*pbelle_sip_messageParser_via_parmPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_via_parm_SCOPE   pbelle_sip_messageParser_via_parmTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_www_authenticate stack for use by pbelle_sip_messageParser_header_www_authenticatePush()
     *  and pbelle_sip_messageParser_header_www_authenticatePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_www_authenticateStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_www_authenticateStack_limit;
    pbelle_sip_messageParser_header_www_authenticate_SCOPE   (*pbelle_sip_messageParser_header_www_authenticatePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_www_authenticate_SCOPE   pbelle_sip_messageParser_header_www_authenticateTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_subscription_state stack for use by pbelle_sip_messageParser_header_subscription_statePush()
     *  and pbelle_sip_messageParser_header_subscription_statePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_subscription_stateStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_subscription_stateStack_limit;
    pbelle_sip_messageParser_header_subscription_state_SCOPE   (*pbelle_sip_messageParser_header_subscription_statePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_subscription_state_SCOPE   pbelle_sip_messageParser_header_subscription_stateTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_event stack for use by pbelle_sip_messageParser_header_eventPush()
     *  and pbelle_sip_messageParser_header_eventPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_eventStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_eventStack_limit;
    pbelle_sip_messageParser_header_event_SCOPE   (*pbelle_sip_messageParser_header_eventPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_event_SCOPE   pbelle_sip_messageParser_header_eventTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_replaces stack for use by pbelle_sip_messageParser_header_replacesPush()
     *  and pbelle_sip_messageParser_header_replacesPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_replacesStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_replacesStack_limit;
    pbelle_sip_messageParser_header_replaces_SCOPE   (*pbelle_sip_messageParser_header_replacesPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_replaces_SCOPE   pbelle_sip_messageParser_header_replacesTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_privacy stack for use by pbelle_sip_messageParser_header_privacyPush()
     *  and pbelle_sip_messageParser_header_privacyPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_privacyStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_privacyStack_limit;
    pbelle_sip_messageParser_header_privacy_SCOPE   (*pbelle_sip_messageParser_header_privacyPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_privacy_SCOPE   pbelle_sip_messageParser_header_privacyTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_supported stack for use by pbelle_sip_messageParser_header_supportedPush()
     *  and pbelle_sip_messageParser_header_supportedPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_supportedStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_supportedStack_limit;
    pbelle_sip_messageParser_header_supported_SCOPE   (*pbelle_sip_messageParser_header_supportedPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_supported_SCOPE   pbelle_sip_messageParser_header_supportedTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_require stack for use by pbelle_sip_messageParser_header_requirePush()
     *  and pbelle_sip_messageParser_header_requirePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_requireStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_requireStack_limit;
    pbelle_sip_messageParser_header_require_SCOPE   (*pbelle_sip_messageParser_header_requirePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_require_SCOPE   pbelle_sip_messageParser_header_requireTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_content_disposition stack for use by pbelle_sip_messageParser_header_content_dispositionPush()
     *  and pbelle_sip_messageParser_header_content_dispositionPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_content_dispositionStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_content_dispositionStack_limit;
    pbelle_sip_messageParser_header_content_disposition_SCOPE   (*pbelle_sip_messageParser_header_content_dispositionPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_content_disposition_SCOPE   pbelle_sip_messageParser_header_content_dispositionTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_accept stack for use by pbelle_sip_messageParser_header_acceptPush()
     *  and pbelle_sip_messageParser_header_acceptPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_acceptStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_acceptStack_limit;
    pbelle_sip_messageParser_header_accept_SCOPE   (*pbelle_sip_messageParser_header_acceptPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_accept_SCOPE   pbelle_sip_messageParser_header_acceptTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  accept_param stack for use by pbelle_sip_messageParser_accept_paramPush()
     *  and pbelle_sip_messageParser_accept_paramPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_accept_paramStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_accept_paramStack_limit;
    pbelle_sip_messageParser_accept_param_SCOPE   (*pbelle_sip_messageParser_accept_paramPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_accept_param_SCOPE   pbelle_sip_messageParser_accept_paramTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_reason stack for use by pbelle_sip_messageParser_header_reasonPush()
     *  and pbelle_sip_messageParser_header_reasonPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_reasonStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_reasonStack_limit;
    pbelle_sip_messageParser_header_reason_SCOPE   (*pbelle_sip_messageParser_header_reasonPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_reason_SCOPE   pbelle_sip_messageParser_header_reasonTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_reason_param stack for use by pbelle_sip_messageParser_header_reason_paramPush()
     *  and pbelle_sip_messageParser_header_reason_paramPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_reason_paramStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_reason_paramStack_limit;
    pbelle_sip_messageParser_header_reason_param_SCOPE   (*pbelle_sip_messageParser_header_reason_paramPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_reason_param_SCOPE   pbelle_sip_messageParser_header_reason_paramTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_authentication_info stack for use by pbelle_sip_messageParser_header_authentication_infoPush()
     *  and pbelle_sip_messageParser_header_authentication_infoPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_authentication_infoStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_authentication_infoStack_limit;
    pbelle_sip_messageParser_header_authentication_info_SCOPE   (*pbelle_sip_messageParser_header_authentication_infoPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_authentication_info_SCOPE   pbelle_sip_messageParser_header_authentication_infoTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  header_extension_base stack for use by pbelle_sip_messageParser_header_extension_basePush()
     *  and pbelle_sip_messageParser_header_extension_basePop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_header_extension_baseStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_header_extension_baseStack_limit;
    pbelle_sip_messageParser_header_extension_base_SCOPE   (*pbelle_sip_messageParser_header_extension_basePush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_header_extension_base_SCOPE   pbelle_sip_messageParser_header_extension_baseTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  paramless_uri stack for use by pbelle_sip_messageParser_paramless_uriPush()
     *  and pbelle_sip_messageParser_paramless_uriPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_paramless_uriStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_paramless_uriStack_limit;
    pbelle_sip_messageParser_paramless_uri_SCOPE   (*pbelle_sip_messageParser_paramless_uriPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_paramless_uri_SCOPE   pbelle_sip_messageParser_paramless_uriTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  uri stack for use by pbelle_sip_messageParser_uriPush()
     *  and pbelle_sip_messageParser_uriPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_uriStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_uriStack_limit;
    pbelle_sip_messageParser_uri_SCOPE   (*pbelle_sip_messageParser_uriPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_uri_SCOPE   pbelle_sip_messageParser_uriTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  fast_uri stack for use by pbelle_sip_messageParser_fast_uriPush()
     *  and pbelle_sip_messageParser_fast_uriPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_fast_uriStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_fast_uriStack_limit;
    pbelle_sip_messageParser_fast_uri_SCOPE   (*pbelle_sip_messageParser_fast_uriPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_fast_uri_SCOPE   pbelle_sip_messageParser_fast_uriTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  userinfo stack for use by pbelle_sip_messageParser_userinfoPush()
     *  and pbelle_sip_messageParser_userinfoPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_userinfoStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_userinfoStack_limit;
    pbelle_sip_messageParser_userinfo_SCOPE   (*pbelle_sip_messageParser_userinfoPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_userinfo_SCOPE   pbelle_sip_messageParser_userinfoTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  hostport stack for use by pbelle_sip_messageParser_hostportPush()
     *  and pbelle_sip_messageParser_hostportPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_hostportStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_hostportStack_limit;
    pbelle_sip_messageParser_hostport_SCOPE   (*pbelle_sip_messageParser_hostportPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_hostport_SCOPE   pbelle_sip_messageParser_hostportTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  fast_hostport stack for use by pbelle_sip_messageParser_fast_hostportPush()
     *  and pbelle_sip_messageParser_fast_hostportPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_fast_hostportStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_fast_hostportStack_limit;
    pbelle_sip_messageParser_fast_hostport_SCOPE   (*pbelle_sip_messageParser_fast_hostportPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_fast_hostport_SCOPE   pbelle_sip_messageParser_fast_hostportTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  uri_parameters stack for use by pbelle_sip_messageParser_uri_parametersPush()
     *  and pbelle_sip_messageParser_uri_parametersPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_uri_parametersStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_uri_parametersStack_limit;
    pbelle_sip_messageParser_uri_parameters_SCOPE   (*pbelle_sip_messageParser_uri_parametersPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_uri_parameters_SCOPE   pbelle_sip_messageParser_uri_parametersTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  headers stack for use by pbelle_sip_messageParser_headersPush()
     *  and pbelle_sip_messageParser_headersPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_headersStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_headersStack_limit;
    pbelle_sip_messageParser_headers_SCOPE   (*pbelle_sip_messageParser_headersPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_headers_SCOPE   pbelle_sip_messageParser_headersTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  uri_header stack for use by pbelle_sip_messageParser_uri_headerPush()
     *  and pbelle_sip_messageParser_uri_headerPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_uri_headerStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_uri_headerStack_limit;
    pbelle_sip_messageParser_uri_header_SCOPE   (*pbelle_sip_messageParser_uri_headerPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_uri_header_SCOPE   pbelle_sip_messageParser_uri_headerTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  fast_host stack for use by pbelle_sip_messageParser_fast_hostPush()
     *  and pbelle_sip_messageParser_fast_hostPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_fast_hostStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_fast_hostStack_limit;
    pbelle_sip_messageParser_fast_host_SCOPE   (*pbelle_sip_messageParser_fast_hostPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_fast_host_SCOPE   pbelle_sip_messageParser_fast_hostTop;


    /* ruleAttributeScopeDef(scope)
     */
    /** Pointer to the  host stack for use by pbelle_sip_messageParser_hostPush()
     *  and pbelle_sip_messageParser_hostPop()
     */
    pANTLR3_STACK pbelle_sip_messageParser_hostStack;
    ANTLR3_UINT32 pbelle_sip_messageParser_hostStack_limit;
    pbelle_sip_messageParser_host_SCOPE   (*pbelle_sip_messageParser_hostPush)(struct belle_sip_messageParser_Ctx_struct * ctx);
    pbelle_sip_messageParser_host_SCOPE   pbelle_sip_messageParser_hostTop;




     belle_sip_message_t*
     (*message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_message_t*
     (*message_raw)	(struct belle_sip_messageParser_Ctx_struct * ctx, size_t* length);

     belle_sip_request_t*
     (*request)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_message_t*
     (*common_request)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_request_t*
     (*request_line)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sip_version)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*generic_version)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*message_header)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_message_t* message);

     belle_sip_messageParser_method_return
     (*method)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*extension_method)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_message_t*
     (*common_response)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_response_t*
     (*response)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_response_t*
     (*status_line)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_status_code_return
     (*status_code)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*extension_code)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_reason_phrase_return
     (*reason_phrase)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_http_request_t*
     (*http_request)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_http_request_t *
     (*http_request_line)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*http_version)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_http_response_t*
     (*http_response)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_http_response_t*
     (*http_status_line)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_opaque_part_for_from_to_contact_addr_spec_return
     (*opaque_part_for_from_to_contact_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_opaque_part_return
     (*opaque_part)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*uric_no_slash_for_from_to_contact_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*uric_no_slash)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_scheme_return
     (*scheme)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_generic_uri_t*
     (*generic_uri_for_from_to_contact_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_generic_uri_t*
     (*generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_generic_uri_t*
     (*hier_part)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_generic_uri_t* uri);

     belle_sip_messageParser_path_segments_return
     (*path_segments)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_generic_uri_t* uri);

     void
     (*segment)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*pchar)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_query_return
     (*query)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*uric)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*uric_for_from_to_contact_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*authority)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_generic_uri_t* uri);

     void
     (*authority_userinfo)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_generic_uri_t* uri);

     belle_sip_messageParser_authority_user_return
     (*authority_user)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_authority_password_return
     (*authority_password)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*authority_hostport)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_generic_uri_t* uri);

     belle_sip_param_pair_t*
     (*generic_param)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_parameters_t* object);

     belle_sip_messageParser_gen_value_return
     (*gen_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_quoted_string_return
     (*quoted_string)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_allow_t*
     (*header_allow)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_methods_return
     (*methods)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*authorization_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*digest_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_authorization_t*
     (*header_authorization)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*credentials)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     void
     (*digest_response)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     void
     (*dig_resp)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     void
     (*username_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*username)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_username_value_return
     (*username_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*uri_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*digest_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     const char*
     (*message_qop)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_qop_value_return
     (*qop_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*cnonce)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_cnonce_value_return
     (*cnonce_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*nonce_count)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_nc_value_return
     (*nc_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*dresponse)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_request_digest_return
     (*request_digest)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*huit_lhex)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*auth_param)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     belle_sip_messageParser_auth_param_value_return
     (*auth_param_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_auth_param_name_return
     (*auth_param_name)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*other_response)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_authorization_t* header_authorization_base);

     belle_sip_messageParser_auth_scheme_return
     (*auth_scheme)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_nonce_value_return
     (*nonce_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*call_id_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_call_id_t*
     (*header_call_id)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_call_id_return
     (*call_id)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*retry_after_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_retry_after_t*
     (*header_retry_after)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_retry_after_return
     (*retry_after)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*contact_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_contact_t*
     (*header_contact)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*contact_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_address_t*
     (*header_address)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_address_t*
     (*header_address_param_less)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_address_t*
     (*header_address_base)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* obj);

     belle_sip_header_address_t*
     (*fast_header_address)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_address_t*
     (*fast_header_address_param_less)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*name_addr)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*name_addr_with_generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*fast_name_addr_with_generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*addr_spec_with_generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*fast_addr_spec_with_generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*paramless_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*paramless_addr_spec_with_generic_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     belle_sip_messageParser_display_name_tokens_return
     (*display_name_tokens)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*display_name)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* object);

     void
     (*contact_params)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*contact_extension)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_delta_seconds_return
     (*delta_seconds)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*content_length_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_content_length_t*
     (*header_content_length)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_content_length_return
     (*content_length)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*content_type_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_content_type_t*
     (*header_content_type)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*media_type)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_m_type_return
     (*m_type)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*type_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_type_param_value_return
     (*type_param_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_m_subtype_return
     (*m_subtype)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*cseq_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_cseq_t*
     (*header_cseq)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_seq_number_return
     (*seq_number)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*date_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_date_t*
     (*header_date)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*date)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_sip_date_return
     (*sip_date)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_expires_t*
     (*header_expires)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*from_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_from_t*
     (*header_from)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*from_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*from_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_max_forwards_t*
     (*header_max_forwards)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_max_forwards_return
     (*max_forwards)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_proxy_authenticate_t*
     (*header_proxy_authenticate)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*challenge)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_www_authenticate_t* www_authenticate);

     void
     (*other_challenge)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_www_authenticate_t* www_authenticate);

     void
     (*digest_cln)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_www_authenticate_t* www_authenticate);

     char*
     (*realm)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_realm_value_return
     (*realm_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*domain)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*nonce)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*opaque)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*stale)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_stale_value_return
     (*stale_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*algorithm)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_list_t*
     (*qop_opts)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*qop_opts_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_proxy_authorization_t*
     (*header_proxy_authorization)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*service_route_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_service_route_t*
     (*header_service_route)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*srv_route)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sr_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*record_route_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_record_route_t*
     (*header_record_route)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*rec_route)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*rr_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*comment)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*route_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_route_t*
     (*header_route)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*route_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*r_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*to_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_to_t*
     (*header_to)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*to_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*to_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*diversion_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_diversion_t*
     (*header_diversion)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*diversion_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*diversion_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*refer_to_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_refer_to_t*
     (*header_refer_to)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*referred_by_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_referred_by_t*
     (*header_referred_by)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_address_t*
     (*refer_to_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_address_t* address);

     belle_sip_header_user_agent_t*
     (*header_user_agent)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*server_val)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*via_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_via_t*
     (*header_via)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*via_parm)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*via_params)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*via_received)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_header_via_t* object);

     belle_sip_messageParser_via_address_return
     (*via_address)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_sent_protocol_return
     (*sent_protocol)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*protocol_name)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*protocol_version)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_transport_return
     (*transport)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*other_transport)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sent_by)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_www_authenticate_t*
     (*header_www_authenticate)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_state_value_return
     (*state_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_subscription_state_t*
     (*header_subscription_state)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_event_t*
     (*header_event)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_event_package_return
     (*event_package)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_replaces_t*
     (*header_replaces)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_p_preferred_identity_t*
     (*header_p_preferred_identity)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_privacy_t*
     (*header_privacy)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*privacy_val)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_supported_t*
     (*header_supported)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*supported_val)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_require_t*
     (*header_require)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*require_val)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_content_disposition_value_return
     (*content_disposition_value)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_content_disposition_t*
     (*header_content_disposition)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*accept_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_accept_t*
     (*header_accept)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*accept_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_accept_main_media_type_return
     (*accept_main_media_type)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_accept_sub_media_type_return
     (*accept_sub_media_type)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_reason_t*
     (*header_reason)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*header_reason_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_header_reason_protocol_return
     (*header_reason_protocol)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_authentication_info_t*
     (*header_authentication_info)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*auth_info)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*qop_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*authentication_info_message_qop)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*rspauth)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*next_nonce)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     char*
     (*quoted_algorithm)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_t*
     (*header)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_header_t*
     (*header_extension_base)	(struct belle_sip_messageParser_Ctx_struct * ctx, ANTLR3_BOOLEAN is_http);

     belle_sip_messageParser_header_name_return
     (*header_name)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_header_value_return
     (*header_value)	(struct belle_sip_messageParser_Ctx_struct * ctx, const char* name, ANTLR3_BOOLEAN is_http);

     void
     (*message_body)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_uri_t*
     (*paramless_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_uri_t*
     (*uri)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_uri_t*
     (*fast_uri)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sip_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sips_token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sip_schema)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     void
     (*userinfo)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     belle_sip_messageParser_user_return
     (*user)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_password_return
     (*password)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hostport)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     void
     (*fast_hostport)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     void
     (*uri_parameters)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     void
     (*uri_parameter)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*other_param)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_pname_return
     (*pname)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_pvalue_return
     (*pvalue)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*paramchar)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*param_unreserved)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*headers)	(struct belle_sip_messageParser_Ctx_struct * ctx, belle_sip_uri_t* uri);

     void
     (*uri_header)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_hname_return
     (*hname)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_hvalue_return
     (*hvalue)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hnv_unreserved)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*fast_host)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_fast_hostname_return
     (*fast_hostname)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*user_unreserved)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*host)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_hostname_return
     (*hostname)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*domainlabel)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*toplabel)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_ipv4address_return
     (*ipv4address)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     const char*
     (*ipv6reference)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_ipv6address_return
     (*ipv6address)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hexpart)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hexseq)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hex4)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_port_return
     (*port)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*escaped)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*ttl)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*three_digit)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_token_return
     (*token)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*reserved_for_from_to_contact_addr_spec)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*reserved)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*unreserved)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*alphanum)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hexdigit)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*alpha)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     belle_sip_messageParser_word_return
     (*word)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*mark)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sp_tab_colon)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*hcolon)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*ldquot)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*rdquot)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*semi)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*comma)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*sp_laquot)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*raquot_sp)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*equal)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*slash)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     void
     (*lws)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred1_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred2_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred3_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred4_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred6_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred7_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred8_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred9_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred10_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred11_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred12_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred13_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred14_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred15_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred16_belle_sip_message)	(struct belle_sip_messageParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct belle_sip_messageParser_Ctx_struct * ctx);
    void	    (*free)   (struct belle_sip_messageParser_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pbelle_sip_messageParser belle_sip_messageParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API pbelle_sip_messageParser belle_sip_messageParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define AND      4
#define AT      5
#define BQUOTE      6
#define BSLASH      7
#define COLON      8
#define COMMA      9
#define COMMON_CHAR      10
#define CRLF      11
#define DASH      12
#define DIGIT      13
#define DOLLARD      14
#define DOT      15
#define DQUOTE      16
#define EMARK      17
#define EQUAL      18
#define HEX_CHAR      19
#define HTAB      20
#define LAQUOT      21
#define LBRACE      22
#define LPAREN      23
#define LSBRAQUET      24
#define OCTET      25
#define OR      26
#define PERCENT      27
#define PLUS      28
#define QMARK      29
#define RAQUOT      30
#define RBRACE      31
#define RPAREN      32
#define RSBRAQUET      33
#define SEMI      34
#define SLASH      35
#define SP      36
#define SQUOTE      37
#define STAR      38
#define TILDE      39
#define USCORE      40
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for belle_sip_messageParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */

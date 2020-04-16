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


#include <belle-sip/mainloop.h>

static belle_sip_source_t * _belle_sip_main_loop_create_cpp_timeout(
	belle_sip_main_loop_t *ml,
	belle_sip_source_cpp_func_t *func,
	unsigned int timeout_value_ms,
	const char* timer_name
) {
	return belle_sip_main_loop_create_timeout_with_remove_cb(
		ml,
		[](void *user_data, unsigned int events){
			return static_cast<belle_sip_source_cpp_func_t *>(user_data)->operator()(events);
		},
		func,
		timeout_value_ms,
		timer_name,
		[](belle_sip_source_t* source){
			delete static_cast<belle_sip_source_cpp_func_t *>(belle_sip_source_get_user_data(source));
			belle_sip_source_set_user_data(source, nullptr);
		}
	);
}

belle_sip_source_t * belle_sip_main_loop_create_cpp_timeout(
	belle_sip_main_loop_t *ml,
	belle_sip_source_cpp_func_t *func,
	unsigned int timeout_value_ms,
	const char* timer_name
) {
	return _belle_sip_main_loop_create_cpp_timeout(ml, func, timeout_value_ms, timer_name);
}

BelleSipSourcePtr belle_sip_main_loop_create_cpp_timeout(
	belle_sip_main_loop_t *ml,
	const belle_sip_source_cpp_func_t &func,
	unsigned int timeout_value_ms,
	const char* timer_name
) {
	belle_sip_source_t* source = _belle_sip_main_loop_create_cpp_timeout(
		ml,
		new belle_sip_source_cpp_func_t{func},
		timeout_value_ms,
		timer_name
	);
	return BelleSipSourcePtr{source};
}

void belle_sip_main_loop_cpp_do_later(belle_sip_main_loop_t *ml, const BelleSipDoLaterFunc &func){
	belle_sip_main_loop_cpp_do_later(ml, func, nullptr);
}

void belle_sip_main_loop_cpp_do_later(
	belle_sip_main_loop_t *ml,
	const BelleSipDoLaterFunc &func,
	const char *task_name
) {
	belle_sip_main_loop_do_later_with_name(
		ml,
		[](void *ud){
			auto func = static_cast<BelleSipDoLaterFunc *>(ud);
			func->operator()();
			delete func;
		},
		new BelleSipDoLaterFunc{func},
		task_name
	);
}

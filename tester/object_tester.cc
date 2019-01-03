/*
 *         belle-sip - SIP (RFC3261) library.
 *                 Copyright (C) 2010  Belledonne Communications SARL
 *
 *                         This program is free software: you can redistribute it and/or modify
 *                                 it under the terms of the GNU General Public License as published by
 *                                         the Free Software Foundation, either version 2 of the License, or
 *                                                 (at your option) any later version.
 *
 *                                                         This program is distributed in the hope that it will be useful,
 *                                                                 but WITHOUT ANY WARRANTY; without even the implied warranty of
 *                                                                         MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *                                                                                 GNU General Public License for more details.
 *
 *                                                                                         You should have received a copy of the GNU General Public License
 *                                                                                                 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *                                                                                                 */

#include "belle-sip/belle-sip.h"
#include "belle_sip_tester.h"

#include "belle-sip/object++.hh"

using namespace bellesip;

static void on_object_destroyed(void *userpointer, belle_sip_object_t *obj_being_destroyed){
	int *value = static_cast<int*>(userpointer);
	*value = TRUE;
}

static void basic_test(void){
	int object_destroyed = FALSE;
	Object *obj = new Object();
	belle_sip_object_t *c_obj = obj->getCObject();
	BC_ASSERT_PTR_NOT_NULL(c_obj);
	if (c_obj){
		belle_sip_object_weak_ref(c_obj, on_object_destroyed, &object_destroyed);
	}
	/*we put a weak ref to this object in order to know when it is destroyed*/
	obj->ref();
	obj->unref();
	BC_ASSERT_FALSE(object_destroyed);
	obj->unref(); /*this unref will destroy the object*/
	BC_ASSERT_TRUE(object_destroyed);
};


static test_t object_tests[] = {
        TEST_NO_TAG("Basic test", basic_test),
};

test_suite_t object_test_suite = {"Object", NULL, NULL, belle_sip_tester_before_each, belle_sip_tester_after_each,
                                                                sizeof(object_tests) / sizeof(object_tests[0]), object_tests};



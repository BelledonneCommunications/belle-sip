#include "belle-sip/object++.hh"
#include "belle_sip_internal.h"



struct _belle_sip_cpp_object{
	belle_sip_object_t base;
};

namespace bellesip{

class ObjectCAccessors{
	public:
		static belle_sip_error_code sMarshal(belle_sip_object_t* obj, char* buff, size_t buff_size, size_t *offset){
			return Object::getCppObject(obj)->marshal(buff, buff_size, offset);
		}
		static void doDelete(belle_sip_object_t* obj){
			delete Object::getCppObject(obj);
		}
};

Object::Object(){
	static bool offsetDefined = false;
	belle_sip_object_vptr_t *vptr = belle_sip_cpp_object_t_vptr_get();
	if (!offsetDefined){
		vptr->cpp_offset = (int)  ((intptr_t)&mObject - (intptr_t)this);
		offsetDefined = true;
	}
	memset(&mObject, 0, sizeof(mObject)); /*the new allocator does not zero the memory*/
	_belle_sip_object_init(&mObject, vptr);
}

Object::~Object(){
	if (mObject.ref != -1){
		belle_sip_fatal("bellesip::Object [%p] has been destroyed directly with delete operator. This is prohibited, use unref() instead.", this);
	}
	belle_sip_object_uninit(&mObject);
	belle_sip_message("Object destroyed");
}

Object *Object::ref(){
	belle_sip_object_ref(&mObject);
	return this;
}

void Object::unref(){
	belle_sip_object_unref(&mObject);
}

belle_sip_error_code Object::marshal(char* buff, size_t buff_size, size_t *offset){
	return mObject.vptr->marshal(&mObject, buff, buff_size, offset); /*default to belle_sip_object_t's implementation*/
}

belle_sip_object_t *Object::getCObject(){
	return &mObject;
}

const belle_sip_object_t *Object::getCObject()const{
	return &mObject;
}

Object *Object::getCppObject(void *ptr){
	belle_sip_object_t *obj = BELLE_SIP_OBJECT(ptr);
	intptr_t cppaddr = (intptr_t)obj - (intptr_t)obj->vptr->cpp_offset;
	return reinterpret_cast<Object*>(cppaddr);
}

const Object *Object::getCppObject(const void *ptr){
	return Object::getCppObject((void*)ptr);
}

}//end of namespace

BELLE_SIP_DECLARE_NO_IMPLEMENTED_INTERFACES(belle_sip_cpp_object_t);
BELLE_SIP_INSTANCIATE_VPTR3(belle_sip_cpp_object_t,belle_sip_object_t,NULL,NULL,bellesip::ObjectCAccessors::sMarshal,NULL,NULL,FALSE,TRUE);


void belle_sip_cpp_object_delete(belle_sip_object_t *obj){
	bellesip::ObjectCAccessors::doDelete(obj);
}



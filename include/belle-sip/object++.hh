

#include "belle-sip/object.h"


namespace bellesip{

class ObjectCAccessors;

class Object{
	friend ObjectCAccessors;
	public:
		Object();
		Object(const Object &other);
		Object *ref();
		void unref();
		virtual belle_sip_error_code marshal(char* buff, size_t buff_size, size_t *offset);
		std::string toString()const{
			std::string ret(belle_sip_object_to_string(&mObject));
			return ret;
		}
		belle_sip_object_t *getCObject();
		const belle_sip_object_t *getCObject()const;
		static Object *getCppObject(void *);
		static const Object *getCppObject(const void *);
	protected:
		virtual ~Object();
	private:
		belle_sip_object_t mObject;
		static belle_sip_object_t *sClone(belle_sip_object_t *);
		static belle_sip_error_code sMarshal(belle_sip_object_t* obj, char* buff, size_t buff_size, size_t *offset);
		
};


}//end of namespace

extern "C" {
BELLE_SIP_DECLARE_VPTR(belle_sip_cpp_object_t);
}


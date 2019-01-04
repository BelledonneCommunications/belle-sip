

#include "belle-sip/object.h"


namespace bellesip{

class ObjectCAccessors;

class Object{
	friend ObjectCAccessors;
	public:
		Object();
		Object *ref();
		void unref();
		virtual belle_sip_error_code marshal(char* buff, size_t buff_size, size_t *offset);
		std::string toString()const{
			std::string ret(belle_sip_object_to_string(&mObject));
			return ret;
		}
		virtual Object *clone()const;
		belle_sip_object_t *getCObject();
		const belle_sip_object_t *getCObject()const;
		void *getCPtr(){
			return static_cast<void*>(getCObject());
		}
		const void *getCPtr()const{
			return static_cast<const void*>(getCObject());
		}
		static Object *getCppObject(void *);
		static const Object *getCppObject(const void *);
	protected:
		virtual ~Object();
		Object(const Object &other);
	private:
		void init();
		belle_sip_object_t mObject;
		static belle_sip_object_t *sClone(belle_sip_object_t *);
		static belle_sip_error_code sMarshal(belle_sip_object_t* obj, char* buff, size_t buff_size, size_t *offset);
};

/**
 * Template class to help define an Object usable in both C and C++
 * The template arguments are:
 * - _CType : the type used to represent this object in C
 * - _CppType : the type used in C++ to implement this object. _CppType is used to be set to the type 
 *   of the class inheriting from HybridObject.
 * Example:
 * typedef struct _CExample CExample;
 * class Example : public HybridObject<CExample, Example>{
 * ...
 * }
 * The C object can be obtained with toC() method, directly cast in the expected type.
 * The C++ object can be obtained from C object with static method toCpp().
**/
template <typename _CType, typename _CppType>
class HybridObject : public Object{
	public:
		HybridObject(){
		}
		_CType *toC(){
			return static_cast<_CType*>(getCPtr());
		}
		const _CType *toC()const{
			return static_cast<const _CType*>(getCPtr());
		}
		static _CppType *toCpp(_CType *ptr){
			return static_cast<_CppType *>(getCppObject(ptr));
		}
		static const _CppType *toCpp(const _CType *ptr){
			return static_cast<const _CppType *>(getCppObject(ptr));
		}
	protected:
		virtual ~HybridObject(){
		}
		HybridObject(const HybridObject<_CType, _CppType> &other) : Object(other){
		}
};


}//end of namespace

extern "C" {
BELLE_SIP_DECLARE_VPTR(belle_sip_cpp_object_t);
}


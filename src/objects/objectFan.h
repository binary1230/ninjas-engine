#ifndef FANOBJECT_H
#define FANOBJECT_H

#include "object.h"

class ObjectFactory;

class FanObject : public Object {
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Object);
		// ar & BOOST_SERIALIZATION_NVP(a_var_you_want_to_serialize);
	}

	protected:
		float current_fan_speed;
	
	public:
		bool Init();
		void Shutdown();
		
		void Update();
		virtual void OnCollide(Object* obj, const b2WorldManifold* pkbWorldManifold);

		FanObject();
		~FanObject();
			
		friend class ObjectFactory;
};

#endif // FanObject_H   

#ifndef DOOROBJECT_H
#define DOOROBJECT_H

#include "object.h"

class ObjectFactory;

enum DoorType {
	INVALID_TYPE = -1,

	SWITCH_TO_ANOTHER_MODE = 0,
	LEVEL_EXIT,
	WARP_TO_ANOTHER_PORTAL,
	RETURN_TO_LAST_MODE
};

class ObjectDoor : public Object {
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Object);
		// ar & BOOST_SERIALIZATION_NVP(a_var_you_want_to_serialize);
	}

	protected:
		int door_open_time;
		
		std::string door_name;		// the door name, used for when we switch levels 
													// around so we can jump back to it if needed

		std::string mode_to_jump_to_on_activate;		// which mode we should use when this door
																						// is activated (e.g. "level2")
	
		enum DoorType door_type; 
	
		void DoDoorAction();
	
	public:
		bool Init();
		void Clear();
		void Shutdown();
		
		void Update();

		virtual bool LoadObjectProperties(XMLNode & xDef);

		// Activate this door.  when it is finished its animation,
		// the door's action will happen (e.g. warp to next level)
		void Activate();

		ObjectDoor();
		~ObjectDoor();

		inline const std::string& GetName() {return door_name;}
			
		friend class ObjectFactory;
		friend class MapSaver;
};

#endif // DoorObject_H   

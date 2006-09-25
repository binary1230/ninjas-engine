#ifndef OBJECT_FACTORY_H
#define OBJECT_FACTORY_H

#include "stdafx.h"

class ObjectFactory;
class AssetManager;

// All must declare objectFactory as friend classes
class Object;
class ObjectPlayer;
class ObjectRadiusBlock;
class ObjectCollectable;
class ObjectController;
class ObjectBackground;
class ObjectStatic;
class ObjectSpring;
class PhysSimulation;

#include "singleton.h"
#include "animation.h"
#include "objectIDs.h"

//! Maps an object definition name to an XMLNode 
//! (e.g. maps "bad_guy_1" to its corresponding XML data)
//! only used for parsing XML
typedef map<const CString, XMLNode> ObjectDefMapping;
typedef map<const CString, XMLNode>::iterator ObjectDefMappingIter;

//! A class which creates Object classes from integer ID's
class ObjectFactory {

	DECLARE_SINGLETON_CLASS(ObjectFactory)

	protected:

		// These create objects of different types
		// xDef is the Object Definition XML (frames, colors, speeds, etc)
		// xObj is a pointer to the XML of the Object Instance (x,y,layer,etc)
		// xObj may be null, and should be ignored if so.
		Object* NewPlayerObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewRadiusBlockObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewCollectableObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewControllerObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewBackgroundObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewStaticObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewSpringObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewFanObject(XMLNode &xDef, XMLNode *xObj=NULL);
		Object* NewDoorObject(XMLNode &xDef, XMLNode *xObj=NULL);
		
		bool LoadObjectSounds(Object* obj, XMLNode &xDef);
		bool LoadObjectProperties(Object* obj, XMLNode &xDef);
		bool LoadObjectAnimations(Object* obj, XMLNode &xDef, 
															AnimationMapping *animation_lookup = NULL);

		// XXX remove once PhysSimulation is a singleton
		PhysSimulation *physSimulation;

		//! Holds object definitions
		//! e.g. the definition of e.g. a "player" object 
		//! is which frames it has, movement speed, etc
		ObjectDefMapping objectDefs;

		//! Maps object def types to OBJECTID's
		map<const CString, OBJECTID> objectDefTypes;

		Object* CreateObject(	OBJECTID id, 
													XMLNode &xObjectDef, 
													XMLNode *xObject=NULL	);

		void SetupTypes();

		OBJECTID GetObjectIDFromXML(XMLNode &xObjectDef);
		CString GetObjectTypeFromXML(XMLNode &xObjectDef);

	public:
		int Init();
		void Shutdown();
		
		inline void SetPhysSimulation(PhysSimulation* p) {physSimulation = p;};
		inline PhysSimulation* GetPhysSimulation() {return physSimulation;};

		// Create an object from an XML node
		Object* CreateObjectFromXML(XMLNode &xObjectDef, XMLNode &xObject);

		// Create an object from a string
		Object* CreateObject(CString objDefName);

		bool AddObjectDefinition(	const CString &objDefName, 
															const XMLNode &xObjectDef);

		// Return the XML associated with an object definition
		XMLNode* FindObjectDefinition(const CString &objDefName);

		//! Load all object definitions from root <objectDefinitions> node
		int LoadObjectDefsFromXML(XMLNode &xObjDefs);

		~ObjectFactory();
};

#define OBJECT_FACTORY ObjectFactory::GetInstance()

#endif // OBJECT_FACTORY_H

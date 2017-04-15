#ifndef ENEMY_OBJECT_H
#define ENEMY_OBJECT_H

#include "object.h"

class ObjectFactory;
class ObjectPlayer;

//! An enemy object that interacts with the player
class ObjectEnemy : public Object {
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP(Object);
		// ar & BOOST_SERIALIZATION_NVP(a_var_you_want_to_serialize);
	}

	protected:
		void MoveTowardsPlayer();
		ObjectPlayer* m_pkTargetPlayer;

		bool bCollidedLastFrame;
		b2Vec2 m_kCollisionDirection;
		int iTimeToWaitBeforeCollisionsAllowedAgain;
				
	public:
		IMPLEMENT_CLONE(ObjectEnemy)

		bool Init();
		void Shutdown();
		
		void Update();

		ObjectEnemy();
		virtual ~ObjectEnemy();

		virtual void OnCollide(Object* obj, const b2WorldManifold* pkbWorldManifold);

		static int iSpawnedObjectCount;

		friend class ObjectFactory;
};

#endif // EnemyObject_H   

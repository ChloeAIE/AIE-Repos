#pragma once
#include "GameObject.h"
#include "Vector3.h"

struct Collider
{
	GameObject* m_Object;

	Collider();

	virtual void CollisionCheck(Collider* other);
};


#pragma once
#include "GameObject.h"

struct Collider
{
	GameObject* m_Object;

	Collider();

	virtual void CollisionCheck(Collider* other);
};


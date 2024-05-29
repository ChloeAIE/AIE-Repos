#include "Barrel.h"

Barrel::Barrel()
{
	pos.x = 1500;
	pos.y = 300;
	m_collider = new Sphere(pos, 30);
	
	m_collider->m_Object = this;
}

Barrel::Barrel(MathClasses::Vector3 pos)
{
	LocalPosition = pos;
	m_collider = new Sphere(GetWorldPosition(), 30);

	m_collider->m_Object = this;
}

#include "Barriers.h"
#include "Plane.h"

Barriers::Barriers()
{
	m_collider = new Plane(GetLocalPosition(), 0);

	m_collider->m_Object = this;
}

Barriers::Barriers(MathClasses::Vector3 normal, float direction)
{
	m_collider = new Plane(normal, direction);
	m_collider->m_Object = this;
}

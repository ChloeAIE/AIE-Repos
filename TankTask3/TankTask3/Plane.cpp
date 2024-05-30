#include "Plane.h"
#include "Sphere.h"

Plane::Plane()
{

}

Plane::Plane(float x, float y, float d) : N(x, y, d), d(d) 
{
}
Plane::Plane(const MathClasses::Vector3& n, float d) : N(n), d(d)
{
}

Plane::Plane(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2)
{
	auto v = p2 - p1;
	v.Normalise();

	N.x = -v.y;
	N.y = v.x;

	d = -p1.Dot(N);
}

Plane::Plane(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2, const MathClasses::Vector3& p3)
{
	auto v1 = (p2 - p1).Normalised();
	auto v2 = (p3 - p1).Normalised();

	N = v1.Cross(v2);

	d = -p1.Dot(N);
}

//Distance to plane - Positive if in front and negative if behind
float Plane::DistanceTo(const MathClasses::Vector3& p) const
{
	return p.Dot(N) + d;
}

MathClasses::Vector3 Plane::ClosestPoint(const MathClasses::Vector3& p) const
{
	return p - N * DistanceTo(p);
}

enum ePlaneResult : int
{
	FRONT = 1, BACK = -1, INTERSECTS = 0
};

//Test Plane
Plane::ePlaneResult Plane::testSide(const MathClasses::Vector3& p) const
{
	float t = p.Dot(N) + d;

	if (t < 0)
	{
		return ePlaneResult::BACK;
	}
	else if (t > 0)
	{
		return ePlaneResult::FRONT;
	}
	return ePlaneResult::INTERSECTS;
}

//Test Sphere
Plane::ePlaneResult Plane::testSide(const Sphere& sphere) const
{
	float t = DistanceTo(sphere.center);

	if (t > sphere.radius)
	{
		return ePlaneResult::FRONT;
	}
	else if (t < -sphere.radius)
	{
		return ePlaneResult::BACK;
	}
	return ePlaneResult::INTERSECTS;
}
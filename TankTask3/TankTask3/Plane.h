#pragma once
#include "Collider.h"

struct Sphere;

struct Plane : public Collider
{
	Plane();

	Plane(float x, float y, float d);
	Plane(const MathClasses::Vector3& n, float d);

	MathClasses::Vector3 N;
	float d;

	Plane(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2);
	Plane(const MathClasses::Vector3& p1, const MathClasses::Vector3& p2, const MathClasses::Vector3& p3);
	
	//Distance to plane - Positive if in front and negative if behind
	float DistanceTo(const MathClasses::Vector3& p) const;
	MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& p) const;

	enum ePlaneResult : int
	{
		FRONT = 1, BACK = -1, INTERSECTS = 0
	};

	//Test Plane
	ePlaneResult testSide(const MathClasses::Vector3& p) const;

	//Test Sphere
	ePlaneResult testSide(const Sphere& sphere) const;


};


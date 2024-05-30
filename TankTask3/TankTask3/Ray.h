#pragma once
#include "Plane.h"
#include "Sphere.h"

namespace Custom
{
	class Ray
	{
	public:
		Ray() {}

		//default inf length
		Ray(const MathClasses::Vector3& start, const MathClasses::Vector3& dir, float l = INFINITY) : origin(start), direction(dir), length(l)
		{

		}

		MathClasses::Vector3 origin;
		MathClasses::Vector3 direction;
		float length;

		MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& point) const
		{
			//ray origin to arbitrary point
			auto p = point - origin;

			//project the point onto the ray and clamp by length
			float t = clampf(p.Dot(direction), 0, length);

			//return position in direction of ray
			return origin + direction * t;
		}

		bool Intersects(const Sphere& sphere, MathClasses::Vector3* I = nullptr, MathClasses::Vector3* R = nullptr) const
		{
			//ray origin to sphere center
			auto L = sphere.center - origin;

			//project sphere center onto ray
			float t = L.Dot(direction);

			//get the sqr distance from sphere center to ray
			float dd = L.Dot(L) - t * t;

			//checks the ray actually hits the sphere
			//also prevents sqrt(<0) errors
			const float ray_project = sphere.radius * sphere.radius - dd;
			if (ray_project < 0)
			{
				return false;
			}

			//subtract penetration amount from projected distance
			t -= sqrt(sphere.radius * sphere.radius - dd);

			//intersects within ray length
			if (t >= 0 && t <= length)
			{
				//store intersection point if requested
				if (I != nullptr)
				{
					*I = origin + direction * t;
				}

				if (R != nullptr)
				{
					//get surface normal at intersection point
					MathClasses::Vector3 N = ((origin + direction * t) - sphere.center);
					N /= sphere.radius;

					//get penetration vector
					auto P = direction * (length - t);

					//get penetration amount
					auto p = P.Dot(N);

					//get reflected vector
					*R = N * -2 * p + P;
				}

				return true;
			}

			//default no intersection
			return false;
		}

		bool Intersect(const Plane& plane, MathClasses::Vector3* I = nullptr, MathClasses::Vector3* R = nullptr) const
		{
			//project ray direction onto plane normal
			//this should give us a value between -1 and 1
			float t = direction.Dot(plane.N);

			//must face the plane
			if (t > 0)
			{
				return false;
			}

			//get distance of ray origin to the plane
			float d = origin.Dot(plane.N) + plane.d;

			//check if ray is parallel with the plane
			//no intersection if poarallel and not touching
			if (t == 0 && d != 0)
			{
				return false;
			}

			//calculate distance along ray to plane
			t = d == 0 ? 0 : -(d / t);

			//intersects if within range
			if (t > 0 && t <= length)
			{
				//store intersection point if requested
				if (I != nullptr)
				{
					*I = origin + direction * t;
				}
				if (R != nullptr)
				{
					//get penetration vector
					auto P = direction * (length - t);
					//get penetration amount
					float p = P.Dot(plane.N);
					//get reflected vector
					*R = plane.N * -2 * p + P;
				}

				return true;
			}

			return false;
		}


	};
}



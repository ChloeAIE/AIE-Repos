#pragma once
#include "Vector3.h"
#include "Collider.h"


struct Sphere : public Collider
{
    Sphere()
    {

    }
    Sphere(const MathClasses::Vector3& p, float r) : center(p), radius(r){}

    MathClasses::Vector3 center;
    float radius;

    void Fit(const MathClasses::Vector3* points, unsigned int count)
    {
        // invalidate extents
        MathClasses::Vector3 min = { FLT_MAX, FLT_MAX, 1 };
        MathClasses::Vector3 max = { -FLT_MAX, -FLT_MAX, 1 };
        

        // find min and max of the points
        for (unsigned int i = 0; i < count; ++i, ++points) {
            min = MathClasses::Vector3::min(min, *points);
            max = MathClasses::Vector3::max(max, *points);
        }

        // put a circle around the min/max box
        center = (min + max) * 0.5f;
        radius = center.Distance(max);
    }

    bool Overlaps(const MathClasses::Vector3& p) const
    {
        MathClasses::Vector3 toPoint = p - center;
        return toPoint.MagnitudeSqr() <= (radius * radius);
    }

    MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& p) const
    {
        MathClasses::Vector3 toPoint = p - center;

        if (toPoint.MagnitudeSqr() > radius * radius)
        {
            toPoint = toPoint.Normalised() * radius;
        }
    }

    
};


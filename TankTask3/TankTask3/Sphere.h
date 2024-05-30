#pragma once
#include "Collider.h"

struct Plane;

struct Sphere : public Collider
{
    Sphere();
    Sphere(const MathClasses::Vector3& p, float r);

    MathClasses::Vector3 center;
    float radius;

    void Fit(const MathClasses::Vector3* points, unsigned int count);

    bool Overlaps(const MathClasses::Vector3& p) const;

    bool Overlaps(const Sphere& other) const;

    ////checking collision with a plane
    bool Overlaps(const Plane& other) const;


    MathClasses::Vector3 ClosestPoint(const MathClasses::Vector3& p) const;

    void CollisionCheck(Collider* other) override;
};


#include "Sphere.h"
#include "Plane.h"

Sphere::Sphere()
{

}

Sphere::Sphere(const MathClasses::Vector3& p, float r) : center(p), radius(r) {}


void Sphere::Fit(const MathClasses::Vector3* points, unsigned int count)
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

bool Sphere::Overlaps(const MathClasses::Vector3& p) const
{
    MathClasses::Vector3 toPoint = p - center;
    return toPoint.MagnitudeSqr() <= (radius * radius);
}

bool Sphere::Overlaps(const Sphere& other) const
{
    //custom sphere to sphere collision/overlapping test
    //Get distance between 2 centers
    //Get the total of both radius
    //if distance < radius sum => collision!

    MathClasses::Vector3 otherCenter = other.center;
    float dist = otherCenter.Distance(center);

    float r_sum = this->radius + other.radius;

    if (dist < r_sum)
    {
        return true;
    }

    return false;
}

//checking collision with a plane
bool Sphere::Overlaps(const Plane& other) const
{
    Plane p = other;

    int result = p.testSide(*this);

    if (result == 0)
    {
        return true;
    }
    
    return false;
}

MathClasses::Vector3 Sphere::ClosestPoint(const MathClasses::Vector3& p) const
{
    MathClasses::Vector3 toPoint = p - center;

    if (toPoint.MagnitudeSqr() > radius * radius)
    {
        toPoint = toPoint.Normalised() * radius;
    }

    return toPoint;
}

void Sphere::CollisionCheck(Collider* other)
{
    //other is some other type of collider
    //figure out which type of collider it is (e.g. sphere/plane)
    //call the correct overlaps function we've created
    //if overlaps is true => yes there was a collision
    //call OnCollision on our owning game object (m_Object)

    //dynamic casting
    //CHECKING IF COLLIDER* OTHER == INSTANCE OF A SPHERE
    Sphere* s_result = dynamic_cast<Sphere*>(other); //attempt to "view" other as a Sphere*
    if (s_result == nullptr)
    {
        //cast failed / other is not a Sphere
    }
    else
    {
        //cast succeded / other was a sphere and we can use s_result as our pointer to data
        if (Overlaps(*s_result))
        {
            //call collision
            m_Object->OnCollision();
        }
    }



    //plane check for collision
    Plane* p_result = dynamic_cast<Plane*>(other);
    if (p_result == nullptr)
    {
        //cast failed or other is not a plane
    }
    else
    {
        //cast succeeded
        if (Overlaps(*p_result))
        {
            m_Object->OnCollision();
        }
    }
}
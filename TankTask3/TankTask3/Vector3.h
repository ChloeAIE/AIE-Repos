#pragma once
#include <string>
#include "Vector4.h"
#include "Utils.h"

namespace MathClasses
{
    struct Vector3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
        {
            
        }

        Vector3(float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        union
        {
            /*struct { float x, y; 
            union { float z, w; };
            };
            float data[3];*/ //this line and above were for homogeneous matricies, not sure if they will break things
            struct { float x, y, z; };
            struct { float r, g, b; };
            float data[3];
        };

        float& operator [](int dim)
        {
            return data[dim];
        }

        const float& operator [](int dim) const
        {
            return data[dim];
        }

        operator float* () {return data;}

        operator const float* () const { return data; }

        Vector3 operator+ (const Vector3& right) const
        {
            Vector3 sum;

            sum.x = x + right.x;
            sum.y = y + right.y;
            sum.z = z + right.z;

            return sum;
        }
        Vector3 operator += (const Vector3& right)
        {
            //Vector3 sum;

            x += right.x;
            y += right.y;
            z += right.z;

            return *this;
        }

        Vector3 operator- (const Vector3& right) const
        {
            Vector3 sum;

            sum.x = x - right.x;
            sum.y = y - right.y;
            sum.z = z - right.z;

            return sum;
        }
        Vector3 operator* (const float& right) const
        {
            Vector3 sum;

            sum.x = x * right;
            sum.y = y * right;
            sum.z = z * right;

            return sum;
        }
        Vector3 operator *= (const float& right) 
        {
           
            x *= right;
            y *= right;
            z *= right;

            return *this;
        }
        Vector3 operator *= (const Vector3& right) 
        {
            

            x *= right.x;
            y *= right.y;
            z *= right.z;

            return *this;
        }

        static friend Vector3 operator*(const float& left, const Vector3& right)
        {
            return right * left;
        }

        Vector3 operator / (const float& right) const
        {
            Vector3 sum;

            sum.x = x / right;
            sum.y = y / right;
            sum.z = z / right;

            return sum;
        }

        Vector3 operator /= (const float& right)
        {
            x = x / right;
            y = y / right;
            z = z / right;

            return *this;
        }

        bool operator == (const Vector3& right) const
        {
            Vector3 sum;

            float xDist = fabsf(x - right.x);
            float yDist = fabsf(y - right.y);
            float zDist = fabsf(z - right.z);

            const float threshold = 0.00001f;

            return xDist < threshold && yDist < threshold && zDist < threshold;
        }

        bool operator != (const Vector3& right) const
        {
            return !(*this == right);
        }

        bool operator < (const Vector3& right) const
        {
            if (x < right.x && y < right.y && z < right.z)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        std::string ToString() const
        {
            return std::to_string(x) + " , " + std::to_string(y) + " , " + std::to_string(z);
        }

        float Magnitude() const
        {
            return sqrtf(x * x + y * y + z * z);
        }

        float MagnitudeSqr() const
        {
            return x * x + y * y + z * z;
        }

        float Distance(const Vector3& other) const
        {
            return (*this - other).Magnitude();
        }

        void Normalise()
        {
            float m = Magnitude();

            if (m == 0)
            {
                x = 0;
                y = 0;
                z = 0;
            }
            else
            {
                x /= m;
                y /= m;
                z /= m;
            }
            
        }

        Vector3 Normalised() const
        {
            Vector3 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector3& other) const
        {
            return x * other.x + y * other.y + z * other.z;
        }

        Vector3 Cross(const Vector3& other)
        {
            return Vector3(y * other.z - z * other.y,
                           z * other.x - x * other.z,
                           x * other.y - y * other.x);
        }

        float AngleBetween(const Vector3& other) const
        {
            Vector3 a = Normalised();
            Vector3 b = other.Normalised();

            float d = a.Dot(other);

            return acosf(d);
        }
    
        static Vector3 min(const Vector3& a, const Vector3& b)
        {
            return { minf(a.x,b.x), minf(a.y,b.y), minf(a.z, b.z)};
        }

        static Vector3 max(const Vector3& a, const Vector3& b)
        {
            return { maxf(a.x,b.x), maxf(a.y,b.y), minf(a.z,b.z)};
        }

        static Vector3 clamp(const Vector3& t, const Vector3& a, const Vector3& b)
        {
            return max(a, min(b, t));
        }
	};
}
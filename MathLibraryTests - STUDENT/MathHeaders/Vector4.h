#pragma once

namespace MathClasses
{
    struct Vector4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        Vector4() : x{ 0 }, y{ 0 }, z{ 0 }, w{ 0 }
        {

        }

        Vector4(float x, float y, float z, float w)
        {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        union
        {
            struct { float x, y, z, w; };
            float data[4];
        };

        float& operator[](int dim)
        {
            return data[dim];
        }

        const float& operator [](int dim) const
        {
            return data[dim];
        }

        operator float* () { return data; }

        //cpy paste from here

        Vector4 operator+ (const Vector4& right) const
        {
            Vector4 sum;

            sum.x = x + right.x;
            sum.y = y + right.y;
            sum.z = z + right.z;
            sum.w = w + right.w;

            return sum;
        }

        Vector4 operator- (const Vector4& right) const
        {
            Vector4 sum;

            sum.x = x - right.x;
            sum.y = y - right.y;
            sum.z = z - right.z;
            sum.w = w - right.w;

            return sum;
        }
        Vector4 operator* (const float& right) const
        {
            Vector4 sum;

            sum.x = x * right;
            sum.y = y * right;
            sum.z = z * right;
            sum.w = w * right;

            return sum;
        }
        static friend Vector4 operator*(const float& left, const Vector4& right)
        {
            return right * left;
        }

        Vector4 operator / (const float& right) const
        {
            Vector4 sum;

            sum.x = x / right;
            sum.y = y / right;
            sum.z = z / right;
            sum.w = w / right;

            return sum;
        }

        bool operator == (const Vector4& right) const
        {
            Vector4 sum;

            float xDist = fabsf(x - right.x);
            float yDist = fabsf(y - right.y);
            float zDist = fabsf(z - right.z);
            float wDist = fabsf(w - right.w);

            const float threshold = 0.00001f;

            return xDist < threshold && yDist < threshold && zDist < threshold && wDist < threshold;
        }

        bool operator != (const Vector4& right) const
        {
            return !(*this == right);
        }

        std::string ToString() const
        {
            return std::to_string(x) + " , " + std::to_string(y) + " , " + std::to_string(z) + " , " + std::to_string(w);
        }

        float Magnitude() const
        {
            return sqrtf(x * x + y * y + z * z + w * w);
        }

        float MagnitudeSqr() const
        {
            return x * x + y * y + z * z + w * w;
        }

        float Distance(const Vector4& other) const
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
                w = 0;
            }
            else
            {
                x /= m;
                y /= m;
                z /= m;
                w /= m;
            }

        }

        Vector4 Normalised() const
        {
            Vector4 copy = *this;
            copy.Normalise();

            return copy;
        }

        float Dot(const Vector4& other)
        {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        Vector4 Vector4::Cross(const Vector4& other)
        {
            return Vector4(y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x,
                0);
        }

        float AngleBetween(const Vector4& other) const
        {
            Vector4 a = Normalised();
            Vector4 b = other.Normalised();

            float d = a.Dot(other);

            return acosf(d);
        }

        /*Vector4& Vector4::operator += (const Vector4& other) 
        {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        Vector4& Vector4::operator -= (const Vector4& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        Vector4& Vector4::operator -= (float& scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;
            w *= scalar;
            return *this;
        }

        float Vector4::Magnitude() const
        {
            return sqrt(x * x + y * y + z * z + w * w);
        }

        void Vector4::Normalise()
        {
            const float mag = sqrt(x * x + y * y + z * z + w * w);
            x /= mag;
            y /= mag;
            z /= mag;
            w /= mag;
        }

        float Vector4::Dot(const Vector4& other) const
        {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }*/
	};
}
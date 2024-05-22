#pragma once
#include "Vector3.h"
#include <string>
namespace MathClasses
{
    struct Matrix3
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...

        Matrix3()
        {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = 0.0f;
        }

        Matrix3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
        {
            this->m1 = m1;
            this->m2 = m2;
            this->m3 = m3;
            this->m4 = m4;
            this->m5 = m5;
            this->m6 = m6;
            this->m7 = m7;
            this->m8 = m8;
            this->m9 = m9;
        }

        Matrix3(float* m)
        {
            m1 = m[0];
            m2 = m[1];
            m3 = m[2];
            m4 = m[3];
            m5 = m[4];
            m6 = m[5];
            m7 = m[6];
            m8 = m[7];
            m9 = m[8];
        }

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9;
            };
            //1-D Array
            float v[9];
            //2-D Array
            float mm[3][3];
            //as vector3
            Vector3 axis[3];
        };

        float& operator [](int dim)
        {
            return v[dim];
        }

        const float& operator[](int dim) const
        {
            return v[dim];
        }

        operator float* () { return v; }

        operator const float* () const { return v; }

        static Matrix3 MakeIdentity()
        {
            Matrix3 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;

            identity.m4 = 0;
            identity.m5 = 1;
            identity.m6 = 0;

            identity.m7 = 0;
            identity.m8 = 0;
            identity.m9 = 1;

            return identity;
        }

        Matrix3 operator * (Matrix3 right) const
        {
            Matrix3 result;

            for (size_t i = 0; i < 3; ++i)
            {
                Vector3 row(mm[0][i], mm[1][i], mm[2][i]);

                for (size_t j = 0; j < 3; ++j)
                {
                    result.mm[j][i] = row.Dot(right.axis[j]);
                }
            }

            return result;
        }

        Vector3 operator * (Vector3 right) const
        {
            return Vector3(Vector3(m1, m4, m7).Dot(right),
                           Vector3(m2, m5, m8).Dot(right),
                           Vector3(m3, m6, m9).Dot(right)
                           );
        }

        Matrix3 Transposed() const
        {
            return Matrix3(m1, m4, m7, m2, m5, m8, m3, m6, m9);
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 9; i++)
            {
                str += " , " + std::to_string(v[i]);
            }
            return str;
        }

        bool operator == (const Matrix3& right) const
        {
            Matrix3 mat;
            
            float m1Dist = fabsf(m1 - right.m1);
            float m2Dist = fabsf(m2 - right.m2);
            float m3Dist = fabsf(m3 - right.m3);
            float m4Dist = fabsf(m4 - right.m4);
            float m5Dist = fabsf(m5 - right.m5);
            float m6Dist = fabsf(m6 - right.m6);
            float m7Dist = fabsf(m7 - right.m7);
            float m8Dist = fabsf(m8 - right.m8);
            float m9Dist = fabsf(m9 - right.m9);

            const float threshold = 0.00001f;

            return m1Dist < threshold && m2Dist < threshold && m3Dist < threshold && m4Dist < threshold && m5Dist < threshold && m6Dist < threshold && m6Dist < threshold &&
                   m7Dist < threshold && m8Dist < threshold && m9Dist < threshold;

        }

        bool operator != (const Matrix3& right) const
        {
            return !(*this == right);
        }

        static Matrix3 MakeRotateX(float a)
        {
            return Matrix3(     1, 0, 0,
                           0, cosf(a), -sinf(a),
                           0, sinf(a), cos(a));
        }

        static Matrix3 MakeRotateY(float a)
        {
            return Matrix3(cosf(a), 0, sinf(a),
                                0, 1, 0,
                           -sinf(a), 0, cosf(a));
        }

        static Matrix3 MakeRotateZ(float a)
        {
            return Matrix3(cosf(a), sinf(a), 0,
                           -sinf(a), cosf(a), 0,
                                0, 0, 1);
        }

        //Matrix3 modelMatrix = Matrix::MakeIdentity()
        //rotate this 3 units on the X axis
        //modelMatrix *= Matrix3::MakeRotateX(3.0f);

        static Matrix3 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix3 x = MakeRotateX(pitch);
            Matrix3 y = MakeRotateY(yaw);
            Matrix3 z = MakeRotateZ(roll);

            return(z * y * x);
        }

        static Matrix3 MakeEuler(Vector3 v3)
        {
            Matrix3 x = MakeRotateX(v3.x);
            Matrix3 y = MakeRotateY(v3.y);
            Matrix3 z = MakeRotateZ(v3.z);

            return(z * y * x);
        }

        static Matrix3 MakeScale(float xScale, float yScale)
        {
            return Matrix3(xScale, 0.0f, 0.0f,
                           0.0f, yScale, 0.0f,
                           0.0f, 0.0f, 1.0f);
        }

        static Matrix3 MakeScale(float xScale, float yScale, float zScale)
        {
            return Matrix3(xScale, 0.0f, 0.0f,
                           0.0f, yScale, 0.0f,
                           0.0f, 0.0f, zScale);
        }

        static Matrix3 MakeScale(Vector3 scale)
        {
            return MakeScale(scale.x, scale.y, scale.z);
        }

        static Matrix3 MakeTranslation(float x, float y, float z)
        {
            Matrix3 mat3;
            mat3 = MakeIdentity();

            mat3.m7 = x;
            mat3.m8 = y;
            mat3.m9 = z;

            return mat3;
        }

        static Matrix3 MakeTranslation(Vector3 v3)
        {
            Matrix3 mat3;
            mat3 = MakeIdentity();
            mat3.m7 = v3.x;
            mat3.m8 = v3.y;
            mat3.m9 = v3.z;

            return mat3;
        }

        /*Matrix3 modelMatrix = Matrix3::MakeIdentity();
        modelMatrix *= Matrix3::MakeScale(3, 3, 3);*/


	};
}
#pragma once
namespace MathClasses
{
    struct Matrix4
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
        Matrix4()
        {
            m1 = m2 = m3 = m4 = m5 = m6 = m7 = m8 = m9 = m10 = m11 = m12 = m13 = m14 = m15 = m16 = 0.0f;
        }

        Matrix4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16)
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
            this->m10 = m10;
            this->m11 = m11;
            this->m12 = m12;
            this->m13 = m13;
            this->m14 = m14;
            this->m15 = m15;
            this->m16 = m16;
        }

        Matrix4(float* m)
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
            m10 = m[9];
            m11 = m[10];
            m12 = m[11];
            m13 = m[12];
            m14 = m[13];
            m15 = m[14];
            m16 = m[15];
        }

        union
        {
            struct
            {
                float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;
            };
            //1-D Array
            float v[16];
            //2-D Array
            float mm[4][4];
            //as vector3
            Vector4 axis[4];
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

        static Matrix4 MakeIdentity()
        {
            Matrix4 identity;
            identity.m1 = 1;
            identity.m2 = 0;
            identity.m3 = 0;
            identity.m4 = 0;

            identity.m5 = 0;
            identity.m6 = 1;
            identity.m7 = 0;
            identity.m8 = 0;

            identity.m9 = 0;
            identity.m10 = 0;
            identity.m11 = 1;
            identity.m12 = 0;

            identity.m13 = 0;
            identity.m14 = 0;
            identity.m15 = 0;
            identity.m16 = 1;

            return identity;
        }

        Matrix4 operator * (Matrix4 right) const
        {
            Matrix4 result;

            for (size_t i = 0; i < 4; ++i)
            {
                Vector4 row(mm[0][i], mm[1][i], mm[2][i], mm[3][i]);

                for (size_t j = 0; j < 4; ++j)
                {
                    result.mm[j][i] = row.Dot(right.axis[j]);
                }
            }

            return result;
        }

        Vector4 operator * (Vector4 right) const
        {
            return Vector4(Vector4(m1, m5, m9, m13).Dot(right),
                Vector4(m2, m6, m10, m14).Dot(right),
                Vector4(m3, m7, m11, m15).Dot(right),
                Vector4(m4, m8, m12, m16).Dot(right)
            );
        }

        Matrix4 Transposed() const
        {
            return Matrix4(m1, m5, m9, m13, m2, m6, m10, m14, m3, m7, m11, m15, m4, m8, m12, m16);
        }

        std::string ToString() const
        {
            std::string str = std::to_string(v[0]);
            for (size_t i = 1; i < 16; i++)
            {
                str += " , " + std::to_string(v[i]);
            }
            return str;
        }

        bool operator == (const Matrix4& right) const
        {
            Matrix4 mat;

            float m1Dist = fabsf(m1 - right.m1);
            float m2Dist = fabsf(m2 - right.m2);
            float m3Dist = fabsf(m3 - right.m3);
            float m4Dist = fabsf(m4 - right.m4);
            float m5Dist = fabsf(m5 - right.m5);
            float m6Dist = fabsf(m6 - right.m6);
            float m7Dist = fabsf(m7 - right.m7);
            float m8Dist = fabsf(m8 - right.m8);
            float m9Dist = fabsf(m9 - right.m9);
            float m10Dist = fabsf(m10 - right.m10);
            float m11Dist = fabsf(m11 - right.m11);
            float m12Dist = fabsf(m12 - right.m12);
            float m13Dist = fabsf(m13 - right.m13);
            float m14Dist = fabsf(m14 - right.m14);
            float m15Dist = fabsf(m15 - right.m15);
            float m16Dist = fabsf(m16 - right.m16);

            const float threshold = 0.00001f;

            return m1Dist < threshold && m2Dist < threshold && m3Dist < threshold && m4Dist < threshold && m5Dist < threshold && m6Dist < threshold &&
                m7Dist < threshold && m8Dist < threshold && m9Dist < threshold && m10Dist < threshold && m11Dist < threshold && m12Dist < threshold && m13Dist < threshold &&
                m14Dist < threshold && m15Dist < threshold && m16Dist < threshold;

        }

        bool operator != (const Matrix4& right) const
        {
            return !(*this == right);
        }

        static Matrix4 MakeRotateX(float a)
        {
            return Matrix4(1,   0,        0,     0,
                           0, cosf(a), -sinf(a), 0,
                           0, sinf(a),  cos(a),  0,
                           0,   0,        0,     1);
        }

        static Matrix4 MakeRotateY(float a)
        {
            return Matrix4(cosf(a), 0, sinf(a), 0,
                               0, 1, 0, 0,
                           -sinf(a), 0, cosf(a), 1,
                           0, 0, 0, 1);
        }

        static Matrix4 MakeRotateZ(float a)
        {
            return Matrix4(cosf(a), sinf(a), 0, 0,
                           -sinf(a), cosf(a), 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1);
        }

        //Matrix3 modelMatrix = Matrix::MakeIdentity()
        //rotate this 3 units on the X axis
        //modelMatrix *= Matrix3::MakeRotateX(3.0f);

        static Matrix4 MakeEuler(float pitch, float yaw, float roll)
        {
            Matrix4 x = MakeRotateX(pitch);
            Matrix4 y = MakeRotateY(yaw);
            Matrix4 z = MakeRotateZ(roll);

            return(z * y * x);
        }

        static Matrix4 MakeEuler(Vector4 v4)
        {
            Matrix4 x = MakeRotateX(v4.x);
            Matrix4 y = MakeRotateY(v4.y);
            Matrix4 z = MakeRotateZ(v4.z);

            return(z * y * x);
        }

        static Matrix4 MakeScale(float xScale, float yScale, float zScale, float wScale)
        {
            return Matrix4(xScale, 0.0f, 0.0f, 0.0f,
                0.0f, yScale, 0.0f, 0.0f,
                0.0f, 0.0f, zScale, 0.0f,
                0.0f, 0.0f, 0.0f, wScale);
        }

        static Matrix4 MakeScale(Vector4 scale)
        {
            return MakeScale(scale.x, scale.y, scale.z, scale.w);
        }
	};
}
//
// Created by angus on 7/28/18.
//

#ifndef GENGINE_MAT4_H
#define GENGINE_MAT4_H

#include "Vec3.h"
#include "Vec4.h"
#include <math.h>

namespace gengine {
    namespace math {
        struct Mat4
        {
            union {
                float elements[4 * 4];
                Vec4 columns[4];
            };

            Mat4();
            Mat4(float diagonal);
            Mat4(const Mat4& original);

            Mat4& multiply(const Mat4& other);
            friend Mat4 operator*(Mat4 left, const Mat4& right);
            Mat4& operator*=(const Mat4& other);

            static Mat4 identity();
            static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
            static Mat4 perspective(float fieldOfView, float aspectRatio, float near, float far);

            static Mat4 translation(const Vec3& trans);
            static Mat4 scale(const Vec3& scale);
            static Mat4 rotation(float angle, const Vec3& axis);

        };
    }
}

#endif //GENGINE_MAT4_H

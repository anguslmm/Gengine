//
// Created by angus on 7/28/18.
//

#ifndef GENGINE_Vec3_H
#define GENGINE_Vec3_H

#include <iostream>

namespace gengine {
    namespace math {
        struct Vec3 {
            float x, y, z;

            Vec3();

            Vec3(float x, float y, float z);

            Vec3(const Vec3 &other);

            Vec3 &add(const Vec3 &other);

            Vec3 &subtract(const Vec3 &other);

            Vec3 &multiply(const Vec3 &other);

            Vec3 &divide(const Vec3 &other);

            friend std::ostream &operator<<(std::ostream &stream, const Vec3 &vector);

            bool operator==(const Vec3 &other);

            friend Vec3 operator+(Vec3 left, const Vec3 &right);

            friend Vec3 operator-(Vec3 left, const Vec3 &right);

            friend Vec3 operator*(Vec3 left, const Vec3 &right);

            friend Vec3 operator/(Vec3 left, const Vec3 &right);

            Vec3 &operator-=(const Vec3 &other);

            Vec3 &operator*=(const Vec3 &other);

            Vec3 &operator/=(const Vec3 &other);

            Vec3 &operator+=(const Vec3 &other);
        };
    }
}
#endif //GENGINE_Vec3_H

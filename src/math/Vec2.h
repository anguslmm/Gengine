//
// Created by angus on 7/28/18.
//

#ifndef GENGINE_VEC2_H
#define GENGINE_VEC2_H

#include <iostream>

namespace gengine {
    namespace math {
        struct Vec2 {
            float x, y;

            Vec2();

            Vec2(float x, float y);

            Vec2(const Vec2 &other);

            Vec2 &add(const Vec2 &other);

            Vec2 &subtract(const Vec2 &other);

            Vec2 &multiply(const Vec2 &other);

            Vec2 &divide(const Vec2 &other);

            friend std::ostream &operator<<(std::ostream &stream, const Vec2 &vector);

            bool operator==(const Vec2 &other);

            friend Vec2 operator+(Vec2 left, const Vec2 &right);

            friend Vec2 operator-(Vec2 left, const Vec2 &right);

            friend Vec2 operator*(Vec2 left, const Vec2 &right);

            friend Vec2 operator/(Vec2 left, const Vec2 &right);

            Vec2 &operator-=(const Vec2 &other);

            Vec2 &operator*=(const Vec2 &other);

            Vec2 &operator/=(const Vec2 &other);

            Vec2 &operator+=(const Vec2 &other);
        };
    }
}
#endif //GENGINE_VEC2_H

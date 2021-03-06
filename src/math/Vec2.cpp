//
// Created by angus on 7/28/18.
//

#include "Vec2.h"

namespace gengine {
    namespace math {
        Vec2::Vec2() {
            x = 0;
            y = 0;
        }

        Vec2::Vec2(float x, float y) {
            this->x = x;
            this->y = y;
        }

        Vec2::Vec2(const Vec2 &other) {
            x = other.x;
            y = other.y;
        }

        Vec2 &Vec2::add(const Vec2 &other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vec2 &Vec2::subtract(const Vec2 &other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vec2 &Vec2::multiply(const Vec2 &other) {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        Vec2 &Vec2::divide(const Vec2 &other) {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        bool Vec2::operator==(const Vec2 &other) {
            return x == other.x && y == other.y;
        }

        Vec2 &Vec2::operator+=(const Vec2 &other) {
            return add(other);
        }

        Vec2 &Vec2::operator-=(const Vec2 &other) {
            return subtract(other);
        }

        Vec2 &Vec2::operator*=(const Vec2 &other) {
            return multiply(other);
        }

        Vec2 &Vec2::operator/=(const Vec2 &other) {
            return divide(other);
        }

        Vec2 operator+(Vec2 left, const Vec2 &right) {
            return left.add(right);
        }

        Vec2 operator-(Vec2 left, const Vec2 &right) {
            return left.subtract(right);
        }

        Vec2 operator*(Vec2 left, const Vec2 &right) {
            return left.multiply(right);
        }

        Vec2 operator/(Vec2 left, const Vec2 &right) {
            return left.divide(right);
        }

        std::ostream &operator<<(std::ostream &stream, const Vec2 &vector) {
            stream << "Vec2(" << vector.x << ", " << vector.y << ") ";
            return stream;
        }
    }
}
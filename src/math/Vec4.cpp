//
// Created by angus on 7/28/18.
//

#include "Vec4.h"

namespace gengine {
    namespace math {
        Vec4::Vec4() {
            x = 0;
            y = 0;
            z = 0;
            w = 0;
        }

        Vec4::Vec4(float x, float y, float z, float w) {
            this->x = x;
            this->y = y;
            this->z = z;
            this->w = w;
        }

        Vec4::Vec4(const Vec4 &other) {
            x = other.x;
            y = other.y;
            z = other.z;
            w = other.w;
        }

        Vec4 &Vec4::add(const Vec4 &other) {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        Vec4 &Vec4::subtract(const Vec4 &other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;
            return *this;
        }

        Vec4 &Vec4::multiply(const Vec4 &other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;
            return *this;
        }

        Vec4 &Vec4::divide(const Vec4 &other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            w /= other.w;
            return *this;
        }

        bool Vec4::operator==(const Vec4 &other) {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        Vec4 &Vec4::operator+=(const Vec4 &other) {
            return add(other);
        }

        Vec4 &Vec4::operator-=(const Vec4 &other) {
            return subtract(other);
        }

        Vec4 &Vec4::operator*=(const Vec4 &other) {
            return multiply(other);
        }

        Vec4 &Vec4::operator/=(const Vec4 &other) {
            return divide(other);
        }

        Vec4 operator+(Vec4 left, const Vec4 &right) {
            return left.add(right);
        }

        Vec4 operator-(Vec4 left, const Vec4 &right) {
            return left.subtract(right);
        }

        Vec4 operator*(Vec4 left, const Vec4 &right) {
            return left.multiply(right);
        }

        Vec4 operator/(Vec4 left, const Vec4 &right) {
            return left.divide(right);
        }

        std::ostream &operator<<(std::ostream &stream, const Vec4 &vector) {
            stream << "Vec4(" << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << ") ";
            return stream;
        }
    }
}
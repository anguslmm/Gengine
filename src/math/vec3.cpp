//
// Created by angus on 7/28/18.
//

#include "vec3.h"

Vec3::Vec3() {
    x = 0;
    y = 0;
    z = 0;
}

Vec3::Vec3(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3::Vec3(const Vec3 &other) {
    x = other.x;
    y = other.y;
    z = other.z;
}

Vec3 &Vec3::add(const Vec3 &other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3 &Vec3::subtract(const Vec3 &other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3 &Vec3::multiply(const Vec3 &other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vec3 &Vec3::divide(const Vec3 &other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

bool Vec3::operator==(const Vec3 &other) {
    return x == other.x && y == other.y && z == other.z;
}

Vec3 &Vec3::operator+=(const Vec3 &other) {
    return add(other);
}

Vec3 &Vec3::operator-=(const Vec3 &other) {
    return subtract(other);
}

Vec3 &Vec3::operator*=(const Vec3 &other) {
    return multiply(other);
}

Vec3 &Vec3::operator/=(const Vec3 &other) {
    return divide(other);
}

Vec3 operator+(Vec3 left, const Vec3 &right) {
    return left.add(right);
}

Vec3 operator-(Vec3 left, const Vec3 &right) {
    return left.subtract(right);
}

Vec3 operator*(Vec3 left, const Vec3 &right) {
    return left.multiply(right);
}

Vec3 operator/(Vec3 left, const Vec3 &right) {
    return left.divide(right);
}

std::ostream &operator<<(std::ostream &stream, const Vec3 &vector) {
    stream << "Vec3(" << vector.x << ", " << vector.y << ", " << vector.z << ") ";
    return stream;
}

//
// Created by angus on 7/28/18.
//

#ifndef GENGINE_Vec4_H
#define GENGINE_Vec4_H
#include <iostream>

struct Vec4 {
    float x, y, z, w;

    Vec4();
    Vec4(float x, float y, float z, float w);
    Vec4(const Vec4& other);

    Vec4& add(const Vec4& other);
    Vec4& subtract(const Vec4& other);
    Vec4& multiply(const Vec4& other);
    Vec4& divide(const Vec4& other);

    friend std::ostream& operator<<(std::ostream& stream, const Vec4& vector);

    bool operator==(const Vec4& other);

    friend Vec4 operator+(Vec4 left, const Vec4 &right);
    friend Vec4 operator-(Vec4 left, const Vec4 &right);
    friend Vec4 operator*(Vec4 left, const Vec4 &right);
    friend Vec4 operator/(Vec4 left, const Vec4 &right);

    Vec4& operator-=(const Vec4 &other);
    Vec4& operator*=(const Vec4 &other);
    Vec4& operator/=(const Vec4 &other);
    Vec4& operator+=(const Vec4 &other);
};

#endif //GENGINE_Vec4_H

//
// Created by angus on 7/28/18.
//

#include <math.h>
#include "Mat4.h"

namespace gengine {
    namespace math {

        float toRadians(float degrees) {
            return degrees * (float)M_PI / 180;
        }

        Mat4::Mat4() {
            for (int i=0; i < 4 * 4; i++)
            {
                elements[i] = 0.0f;
            }
        }

        Mat4::Mat4(float diagonal) {
            for (int i=0; i < 4 * 4; i++)
            {
                elements[i] = 0.0f;
            }

            elements[0 + 0 * 4] = diagonal;
            elements[1 + 1 * 4] = diagonal;
            elements[2 + 2 * 4] = diagonal;
            elements[3 + 3 * 4] = diagonal;
        }

        Mat4 Mat4::identity() {
            return Mat4(1.0f);
        }

        Mat4 &Mat4::multiply(const Mat4 &other) {
            for (int y = 0; y < 4; y++) {
                for (int x = 0; x < 4; x++) {
                    float sum = 0.0f;
                    for (int e = 0; e < 4; e++) {
                        sum += elements[x + e*4] * other.elements[e + y*4];
                    }
                    elements[y + x*4] = sum;
                }
            }
            return *this;
        }

        Mat4 operator*(Mat4 left, const Mat4 &right) {
            return left.multiply(right);
        }

        Mat4 &Mat4::operator*=(const Mat4 &other) {
            return multiply(other);
        }

        Mat4 Mat4::orthographic(float left, float right, float bottom, float top, float near, float far) {
            Mat4 result;
            result.elements[0 + 0 * 4] =  2.0f / (right - left);
            result.elements[1 + 1 * 4] =  2.0f / (top - bottom);
            result.elements[2 + 2 * 4] = -2.0f / (far - near);
            result.elements[3 + 3 * 4] =  1.0f;
            result.elements[2 + 3 * 4] =  (near + far) / (near - far); // Whereeeeeevvvver you are...
            result.elements[1 + 3 * 4] =  (bottom + top) / (bottom - top);
            result.elements[0 + 3 * 4] =  (left + right) / (left - right);
            return result;
        }

        Mat4 Mat4::perspective(float fieldOfView, float aspectRatio, float near, float far) {
            Mat4 result;

            const float q = 1.0f/tan(toRadians(0.5f * fieldOfView));
            const float a = q / aspectRatio;

            result.elements[0 + 0 * 4] = a;
            result.elements[1 + 1 * 4] = q;
            result.elements[2 + 2 * 4] = -(far + near) / (far - near);
            result.elements[3 + 2 * 4] = 1.0f;
            result.elements[2 + 3 * 4] = (2 * far * near) / (near - far);
            return result;
        }

        Mat4 Mat4::translation(const Vec3 &distances) {
            Mat4 result(1.0f);
            result.elements[0 + 3 * 4] = distances.x;
            result.elements[1 + 3 * 4] = distances.y;
            result.elements[2 + 3 * 4] = distances.z;
            return result;
        }

        Mat4 Mat4::scale(const Vec3 &magnitudes) {
            Mat4 result(1.0f);
            result.elements[0 + 0 * 4] = magnitudes.x;
            result.elements[1 + 1 * 4] = magnitudes.y;
            result.elements[2 + 2 * 4] = magnitudes.z;
            return result;
        }

        Mat4 Mat4::rotation(float angle, Vec3 &axis) {
            Mat4 result(1.0f);
            float r = toRadians(angle);
            float c = cos(r);
            float omc = 1-c;
            float s = sin(r);
            float x = axis.x;
            float y = axis.y;
            float z = axis.z;

            result.elements[0 + 0 * 4] = x * omc + c;
            result.elements[1 + 0 * 4] = y * x * omc + z * s;
            result.elements[2 + 0 * 4] = x * z * omc - y * s;

            result.elements[0 + 1 * 4] = x * y * omc - z * s;
            result.elements[1 + 1 * 4] = y * omc + c;
            result.elements[2 + 1 * 4] = y * z * omc + x * s;

            result.elements[0 + 2 * 4] = x * z * omc + y * s;
            result.elements[1 + 2 * 4] = y * z * omc - x * s;
            result.elements[2 + 2 * 4] = z * omc + c;

            return result;
        }


    }

}
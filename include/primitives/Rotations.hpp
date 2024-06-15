/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Rotations
*/

#ifndef ROTATIONS_HPP_
#define ROTATIONS_HPP_

#include "Vector3D.hpp"

namespace Math {
    class Matrix3x3 {
    public:
        Matrix3x3() {
            // Initialize to identity matrix
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    data[i][j] = (i == j) ? 1.0 : 0.0;
        }

        // Construct a rotation matrix around a given axis by a given angle (in radians)
        static Matrix3x3 rotationMatrix(const Vector3D& axis, double angle) {
            Matrix3x3 mat;
            double cosA = cos(angle);
            double sinA = sin(angle);
            double oneMinusCosA = 1.0 - cosA;

            mat.data[0][0] = cosA + axis._x * axis._x * oneMinusCosA;
            mat.data[0][1] = axis._x * axis._y * oneMinusCosA - axis._z * sinA;
            mat.data[0][2] = axis._x * axis._z * oneMinusCosA + axis._y * sinA;

            mat.data[1][0] = axis._y * axis._x * oneMinusCosA + axis._z * sinA;
            mat.data[1][1] = cosA + axis._y * axis._y * oneMinusCosA;
            mat.data[1][2] = axis._y * axis._z * oneMinusCosA - axis._x * sinA;

            mat.data[2][0] = axis._z * axis._x * oneMinusCosA - axis._y * sinA;
            mat.data[2][1] = axis._z * axis._y * oneMinusCosA + axis._x * sinA;
            mat.data[2][2] = cosA + axis._z * axis._z * oneMinusCosA;

            return mat;
        }

        // Apply the rotation matrix to a vector
        Vector3D operator*(const Vector3D& vec) const {
            return Vector3D(
                data[0][0] * vec._x + data[0][1] * vec._y + data[0][2] * vec._z,
                data[1][0] * vec._x + data[1][1] * vec._y + data[1][2] * vec._z,
                data[2][0] * vec._x + data[2][1] * vec._y + data[2][2] * vec._z
            );
        }

    private:
        double data[3][3];
    };
}

#endif /* !ROTATIONS_HPP_ */

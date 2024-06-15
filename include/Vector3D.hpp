/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Vector3D
*/

#ifndef VECTOR3D_HPP_
#define VECTOR3D_HPP_

#include "cmath"
#include "algorithm"

namespace Math {
    class Vector3D {
        public:
            Vector3D();
            Vector3D(double x, double y, double z);
            ~Vector3D();
            double length() const;
            double dot(const Vector3D &other) const;
            void normalize();
            static Vector3D normalize(const Vector3D &);
            Vector3D clamp(const Vector3D& col, double min, double max);
            double range(const Vector3D &other) const;

            bool operator==(const Vector3D &other);
            Vector3D operator+(const Vector3D &other) const;
            Vector3D &operator+=(const Vector3D &other);
            Vector3D operator-(const Vector3D &other) const;
            Vector3D &operator-=(const Vector3D &other);
            Vector3D operator*(const Vector3D &other) const;
            Vector3D &operator*=(const Vector3D &other);
            Vector3D operator/(const Vector3D &other) const;
            Vector3D &operator/=(const Vector3D &other);

            Vector3D operator*(const double &other) const;
            Vector3D &operator*=(const double &other);
            Vector3D operator/(const double &other) const;
            Vector3D &operator/=(const double &other);

            double _x;
            double _y;
            double _z;
        private:
    };
};

#endif /* !VECTOR3D_HPP_ */

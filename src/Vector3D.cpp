/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

namespace Math {
    Vector3D::Vector3D() : _x(0), _y(0), _z(0)
    {
    }

    Vector3D::Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z)
    {
    }

    Vector3D::~Vector3D()
    {
    }

    double Vector3D::length() const
    {
        double lenght = sqrt((_x * _x) + (_y * _y) + (_z *_z));
        return std::abs(lenght);
    }

    double Vector3D::dot(const Vector3D &other) const
    {
        return _x * other._x + _y * other._y + _z * other._z;
    }

    void Vector3D::normalize()
    {
        double len = length();
        if (len) {
            _x /= len;
            _y /= len;
            _z /= len;
        }
    }

    Vector3D Vector3D::normalize(const Vector3D &other)
    {
        double len = other.length();
        Vector3D vec(other);
        if (len)
            vec /= len;
        return vec;
    }

    Vector3D Vector3D::clamp(const Vector3D& col, double min, double max) 
    {
        return Vector3D(std::clamp(col._x, min, max), std::clamp(col._y, min, max), std::clamp(col._z, min, max));
    }

    double Vector3D::range(const Vector3D &other) const
    {
        return std::sqrt(std::pow(_x - other._x, 2) + std::pow(_y - other._y, 2) + std::pow(_z - other._z, 2));
    }

    bool Vector3D::operator==(const Vector3D &other)
    {
        return (_x == other._x && _y == other._y && _z == other._z);
    }

    Vector3D Vector3D::operator+(const Vector3D &other) const
    {
        return Vector3D(_x + other._x, _y + other._y, _z + other._z);
    }

    Vector3D &Vector3D::operator+=(const Vector3D &other)
    {
        _x += other._x;
        _y += other._y;
        _z += other._z;
        return *this;
    }

    Vector3D Vector3D::operator-(const Vector3D &other) const
    {
        return Vector3D(_x - other._x, _y - other._y, _z - other._z);
    }

    Vector3D &Vector3D::operator-=(const Vector3D &other)
    {
        _x -= other._x;
        _y -= other._y;
        _z -= other._z;
        return *this;
    }

    Vector3D Vector3D::operator*(const Vector3D &other) const
    {
        return Vector3D(_x * other._x, _y * other._y, _z * other._z);
    }

    Vector3D &Vector3D::operator*=(const Vector3D &other)
    {
        _x *= other._x;
        _y *= other._y;
        _z *= other._z;
        return *this;
    }

    Vector3D Vector3D::operator/(const Vector3D &other) const
    {
        return Vector3D(_x / other._x, _y / other._y, _z / other._z);
    }

    Vector3D &Vector3D::operator/=(const Vector3D &other)
    {
        _x /= other._x;
        _y /= other._y;
        _z /= other._z;
        return *this;
    }

    Vector3D Vector3D::operator*(const double &other) const
    {
        return Vector3D(_x * other, _y * other, _z * other);
    }

    Vector3D &Vector3D::operator*=(const double &other)
    {
        _x *= other;
        _y *= other;
        _z *= other;
        return *this;
    }

    Vector3D Vector3D::operator/(const double &other) const
    {
        return Vector3D(_x / other, _y / other, _z / other);
    }

    Vector3D &Vector3D::operator/=(const double &other)
    {
        _x /= other;
        _y /= other;
        _z /= other;
        return *this;
    }
};
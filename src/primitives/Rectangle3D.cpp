/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Rectangle3D
*/

#include "primitives/Rectangle3D.hpp"

namespace RayTracer {
    Rectangle3D::Rectangle3D()
    {
    }

    Rectangle3D::~Rectangle3D()
    {
    }

    Math::Vector3D Rectangle3D::pointAt(double u, double v)
    {
        double x = _origin._x + u * bottom_side._x + v * left_side._x;
        double y = _origin._y + u * bottom_side._y + v * left_side._y;
        double z = _origin._z + u * bottom_side._z + v * left_side._z;
        return Math::Vector3D(x, y, z);
    }

    Math::Vector3D Rectangle3D::getColor(const Ray& ray) const
    {
        (void)ray;
        return _color;
    }

    Math::Vector3D Rectangle3D::getNormal(const Math::Vector3D &hitpoint) const
    {
        (void)hitpoint;
        return Math::Vector3D();
    }

    bool Rectangle3D::hits(const Ray& ray, double &dist) const
    {
        (void)ray;
        (void)dist;
        return true;
    }

    void Rectangle3D::setWidth(int width)
    {
        _width = width;
    }

    void Rectangle3D::setHeight(int height)
    {
        _height = height;
    }

};

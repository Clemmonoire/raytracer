/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Camera
*/

#include "Camera.hpp"
#include "Vector3D.hpp"
#include "Vector3D.hpp"
#include <iostream>

namespace RayTracer {
    Camera::Camera()
    {
    }

    Camera::~Camera()
    {
    }

    Ray Camera::ray(double u, double v) {
        double scale = tan((_field_of_view * 0.5) * M_PI / 180);
        double imageAspectRatio = _width / (double)_height;
        double px = (2 * (u + 0.5) / (double)_width - 1) * scale;
        double py = (1 - 2 * (v + 0.5) / (double)_height) * scale / imageAspectRatio;
        Math::Vector3D direction = Math::Vector3D(px, py, -1); // Only the direction part
        direction.normalize();

        return Ray(_origin, direction);
    }

    void Camera::setPosition(double x, double y, double z)
    {
        _origin = Math::Vector3D(x, y, z);
    }

    void Camera::setRotation(double x, double y, double z)
    {
        _rotation = Math::Vector3D(x, y, z);
    }

    void Camera::setResolution(int width, int height)
    {
        _width = width;
        _height = height;
        _screen.setWidth(width);
        _screen.setHeight(height);
    }

    void Camera::setFieldOfView(double fov)
    {
        _field_of_view = fov;
    }

};


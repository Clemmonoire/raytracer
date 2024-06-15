/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Ray
*/

#include "Ray.hpp"

namespace RayTracer {
    Ray::Ray() : _origin(), _direction(0, 0, -1)
    {
    }
    
    Ray::Ray(const Math::Vector3D &origin, const Math::Vector3D &direction) : _origin(origin), _direction(direction)
    {
    }

    Ray::~Ray()
    {
    }
};

/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IPrimitive.hpp
*/

#ifndef IPRIMITIVE_HPP
#define IPRIMITIVE_HPP

#include "../Ray.hpp"
#include "../Vector3D.hpp"
#include <vector>
#include <libconfig.h++>
#include <cmath>

namespace RayTracer {
    class IPrimitive
    {
        public:
            virtual ~IPrimitive() = default;
            virtual bool hits(const Ray& ray, double &) const = 0;
            virtual Math::Vector3D getColor(const Ray&) const = 0;
            virtual Math::Vector3D getNormal(const Math::Vector3D &) const = 0;
    };
}

#endif

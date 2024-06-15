/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Plane.hpp
*/

#ifndef PLANE_HPP
#define PLANE_HPP

#include "IPrimitive.hpp"

namespace RayTracer {
    class Plane : public IPrimitive
    {
        public:
            Plane();
            Plane(const std::vector<int>& params);
            ~Plane();
            bool hits(const Ray &, double &) const override;
            virtual Math::Vector3D getColor(const Ray& ray) const override;
            Math::Vector3D getNormal(const Math::Vector3D &) const override;
            static std::vector<int> config(const libconfig::Setting &);

        private:
            Math::Vector3D _point;
            Math::Vector3D _normal;
            Math::Vector3D _color;
    };
}

#endif

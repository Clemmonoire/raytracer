/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "IPrimitive.hpp"

namespace RayTracer {
    class Sphere : public IPrimitive {
        public:
            Sphere();
            Sphere(const std::vector<int>& params);
            ~Sphere();
            bool hits(const Ray &, double &) const override;
            virtual Math::Vector3D getColor(const Ray& ray) const override;
            Math::Vector3D getNormal(const Math::Vector3D &) const override;
            static std::vector<int> config(const libconfig::Setting &);

        private:
            Math::Vector3D _center;
            double _radius;
            Math::Vector3D _color;
    };
};

#endif /* !SPHERE_HPP_ */

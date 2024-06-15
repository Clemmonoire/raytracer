/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Cylindre
*/

#ifndef CYLINDRE_HPP_
#define CYLINDRE_HPP_

#include "IPrimitive.hpp"

namespace RayTracer {
    class Cylindre : public IPrimitive {
        public:
            Cylindre();
            Cylindre(const std::vector<int>& params);
            ~Cylindre();
            bool hits(const Ray &, double &) const override;
            virtual Math::Vector3D getColor(const Ray& ray) const override;
            Math::Vector3D getNormal(const Math::Vector3D &) const override;
            static std::vector<int> config(const libconfig::Setting &);
        private:
            Math::Vector3D _center;
            double _radius;
            Math::Vector3D _color;
            Math::Vector3D dir;
    };
};
#endif /* !CYLINDRE_HPP_ */

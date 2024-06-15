/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Cone.hpp
*/

#ifndef CONE_HPP_
#define CONE_HPP_

#include "IPrimitive.hpp"

namespace RayTracer {
    class Cone : public IPrimitive {
        public:
            Cone();
            Cone(const std::vector<int>& params);
            ~Cone();
            bool hits(const Ray &, double &) const override;
            virtual Math::Vector3D getColor(const Ray& ray) const override;
            Math::Vector3D getNormal(const Math::Vector3D &) const override;
            static std::vector<int> config(const libconfig::Setting &);
            void setAxis(const Math::Vector3D& axis);

        private:
            Math::Vector3D _apex;
            Math::Vector3D _axis;
            double _angle;
            double _height;
            Math::Vector3D _color;
    };
};

#endif /* !CONE_HPP_ */

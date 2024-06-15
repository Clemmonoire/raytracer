/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "IPrimitive.hpp"

namespace RayTracer {
    class Rectangle3D : public IPrimitive {
        public:
            Rectangle3D();
            ~Rectangle3D();
            Math::Vector3D pointAt(double u, double v);
            virtual Math::Vector3D getColor(const Ray& ray) const override;
            bool hits(const Ray &, double &) const override;
            Math::Vector3D getNormal(const Math::Vector3D &) const override;
            void setWidth(int width);
            void setHeight(int height);

        private:
            Math::Vector3D _origin;
            Math::Vector3D bottom_side;
            Math::Vector3D left_side;
            Math::Vector3D _color;
            int _width;
            int _height;
    };
};

#endif /* !RECTANGLE3D_HPP_ */

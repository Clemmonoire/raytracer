/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Ray
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Vector3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Ray();
            Ray(const Math::Vector3D &, const Math::Vector3D &);
            ~Ray();

        Math::Vector3D _origin;
        Math::Vector3D _direction;

        protected:
        private:
    };
};

#endif /* !RAY_HPP_ */

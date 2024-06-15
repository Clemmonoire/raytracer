/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "Ray.hpp"
#include "Vector3D.hpp"
#include <libconfig.h++>
#include <vector>
#include "algorithm"
#include "utility"

namespace RayTracer {
    class Light {
        public:
            Light();
            Light(const Math::Vector3D &, const double &);
            ~Light();
            static std::pair<Math::Vector3D, double> config(const libconfig::Setting &);
            Math::Vector3D getOrigin() const;
            double getIntensity() const;

        private:
            Math::Vector3D _origin;  
            double _intensity;
    };
};

#endif /* !LIGHT_HPP_ */

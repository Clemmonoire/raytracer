/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Light
*/

#include "Light.hpp"
namespace RayTracer {
    Light::Light(const Math::Vector3D &pos, const double &intensity) : _origin(pos), _intensity(intensity)
    {
    }

    Light::Light() : _origin(), _intensity(1)
    {
    }

    Light::~Light()
    {
    }

    Math::Vector3D Light::getOrigin() const
    {
        return _origin;
    }
    double Light::getIntensity() const
    {
        return _intensity;
    }

    std::pair<Math::Vector3D, double> Light::config(const libconfig::Setting &conf)
    {
        double intensity;

        int x = conf["x"];
        int y = conf["y"];
        int z = conf["z"];
        if (conf.exists("intensity")) {
            intensity = conf["intensity"];
            intensity = std::min(1.0, std::max(intensity, 0.0));
        }
        else
            intensity = 1.0;
        return std::make_pair(Math::Vector3D(x, y, z), intensity);
    }
};

/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Plane
*/

#include "primitives/Plane.hpp"

namespace RayTracer {
    using Math::Vector3D;
    using Math::Vector3D;
    Plane::Plane() : _point(), _normal(0, 1, 0), _color()
    {
    }

    Plane::Plane(const std::vector<int>& params)
        : _point(), _normal(), _color(params[2], params[3], params[4])
    {
        if (params[0] == 0) {
            _normal = Math::Vector3D(1, 0, 0);
            _point = Math::Vector3D(params[1], 0, 0);
        } else if (params[0] == 1) {
            _normal = Math::Vector3D(0, 1, 0);
            _point = Math::Vector3D(0, params[1], 0);
        } else if (params[0] == 2) {
            _normal = Math::Vector3D(0, 0, 1);
            _point = Math::Vector3D(0, 0, params[1]);
        }
        _normal.normalize();
    }

    Plane::~Plane()
    {
    }

    bool Plane::hits(const Ray &ray, double &dist) const {
        Vector3D normal = _normal; 
        double denominator = normal.dot(ray._direction);

        if (std::fabs(denominator) < 1e-6) {
            return false; 
        }

        Vector3D p0_to_origin = _point - ray._origin;
        double t = p0_to_origin.dot(normal) / denominator;

        if (t < 0) {
            return false; 
        }

        dist = t;
        return true;
    }

    Math::Vector3D Plane::getColor(const Ray& ray) const
    {
        (void)ray;
        return _color;
    }

    Math::Vector3D Plane::getNormal(const Math::Vector3D &hitpoint) const
    {
        (void)hitpoint;
        return _normal;
    }

    std::vector<int> Plane::config(const libconfig::Setting &conf)
    {
        std::vector<int> info;
        info.push_back(conf["axis"]);
        info.push_back(conf["position"]);
        info.push_back(conf["color"]["r"]);
        info.push_back(conf["color"]["g"]);
        info.push_back(conf["color"]["b"]);
        return info;
    }
};

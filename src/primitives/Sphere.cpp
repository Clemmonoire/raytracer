/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Sphere
*/

#include "primitives/Sphere.hpp"

namespace RayTracer {
    Sphere::Sphere() : _center(), _radius(0), _color()
    {
    }

    Sphere::Sphere(const std::vector<int>& params)
        : _center(params[0], params[1], params[2]), _radius(params[3]), _color(params[4], params[5], params[6])
    {
    }

    Sphere::~Sphere()
    {
    }

    bool Sphere::hits(const Ray& ray, double& dist) const {
        Math::Vector3D oc = ray._origin - _center;
        
        double a = ray._direction.dot(ray._direction);
        double b = 2.0 * oc.dot(ray._direction);
        double c = oc.dot(oc) - _radius * _radius;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }

        double sqrtDiscriminant = std::sqrt(discriminant);
        double t1 = (-b - sqrtDiscriminant) / (2 * a);
        double t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 > 0 && t2 > 0)
            dist = std::min(t1, t2);
        else if (t1 > 0)
            dist = t1;
        else if (t2 > 0)
            dist = t2;
        else
            return false;

        return true;
    }

    Math::Vector3D Sphere::getColor(const Ray& ray) const
    {
        (void)ray;
        return _color;
    }

    Math::Vector3D Sphere::getNormal(const Math::Vector3D &hitpoint) const
    {
        return Math::Vector3D::normalize(hitpoint - _center);
    }

    std::vector<int> Sphere::config(const libconfig::Setting &conf)
    {
        std::vector<int> info;
        info.push_back(conf["x"]);
        info.push_back(conf["y"]);
        info.push_back(conf["z"]);
        info.push_back(conf["r"]);
        info.push_back(conf["color"]["r"]);
        info.push_back(conf["color"]["g"]);
        info.push_back(conf["color"]["b"]);
        return info;
    }
};

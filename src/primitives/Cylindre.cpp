/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Cylindre
*/

#include "primitives/Cylindre.hpp"

namespace RayTracer {
    using Math::Vector3D;
    Cylindre::Cylindre()
    {
    }

    Cylindre::Cylindre(const std::vector<int>& params)
        : _radius(params[3]), _color(params[4], params[5], params[6])
    {
        if (params[0] == 0) {
            _center = Math::Vector3D(0.0, params[1], params[2]);
            dir = Math::Vector3D(1.0, 0.0, 0.0);
        } else if (params[0] == 1) {
            _center = Math::Vector3D(params[1], 0.0, params[2]);
            dir = Math::Vector3D(0.0, 1.0, 0.0);
        } else {
            _center = Math::Vector3D(params[1], params[2], 0.0);
            dir = Math::Vector3D(0.0, 0.0, 1.0);
        }
    }

    Cylindre::~Cylindre()
    {
    }

    bool Cylindre::hits(const Ray& ray, double& dist) const {
        Vector3D oc = ray._origin - _center;

        Vector3D d_parallel = dir * ray._direction.dot(dir);
        Vector3D d_perpendicular = ray._direction - d_parallel;

        Vector3D oc_parallel = dir * oc.dot(dir);
        Vector3D oc_perpendicular = oc - oc_parallel;

        double a = d_perpendicular.dot(d_perpendicular);
        double b = 2.0 * oc_perpendicular.dot(d_perpendicular);
        double c = oc_perpendicular.dot(oc_perpendicular) - _radius * _radius;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            return false;
        }

        double sqrtDiscriminant = std::sqrt(discriminant);
        double t1 = (-b - sqrtDiscriminant) / (2 * a);
        double t2 = (-b + sqrtDiscriminant) / (2 * a);

        if (t1 > 0 && t2 > 0) {
            dist = std::min(t1, t2);
        } else if (t1 > 0) {
            dist = t1;
        } else if (t2 > 0) {
            dist = t2;
        } else {
            return false;
        }

        return true;
    }

    Math::Vector3D Cylindre::getColor(const Ray& ray) const
    {
        (void)ray;
        return _color;
    }

    Vector3D Cylindre::getNormal(const Vector3D& point) const {
        Vector3D cp = point - _center;

        Vector3D cp_parallel = dir * cp.dot(dir);

        Vector3D n = cp - cp_parallel;

        n.normalize();
        return n;
    }


    std::vector<int> Cylindre::config(const libconfig::Setting &conf)
    {
        std::vector<int> info;
        info.push_back(conf["axis"]);
        info.push_back(conf["a"]);
        info.push_back(conf["b"]);
        info.push_back(conf["r"]);
        info.push_back(conf["color"]["r"]);
        info.push_back(conf["color"]["g"]);
        info.push_back(conf["color"]["b"]);
        return info;
    }
};

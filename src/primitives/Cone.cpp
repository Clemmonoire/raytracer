/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Cone.cpp
*/

#include "primitives/Cone.hpp"
#include <cmath>
#include <iostream>

namespace RayTracer {
    using Math::Vector3D;

    Cone::Cone() : _apex(), _axis(0, 1, 0), _angle(0), _color() {
        _axis.normalize();
    }

    Cone::Cone(const std::vector<int>& params)
        : _apex(params[0], params[1], params[2]), _axis(0, 1, 0), _angle(params[3] * M_PI / 180.0), _height(params[4]), _color(params[5], params[6], params[7]) 
    {
        _axis.normalize();
    }

    Cone::~Cone() {
    }

    void Cone::setAxis(const Vector3D& axis) {
        _axis = axis;
        _axis.normalize();
    }

    bool Cone::hits(const Ray& ray, double& dist) const
    {
        Vector3D oc = ray._origin - _apex;
        double k = tan(_angle);
        k = k * k;

        double axisDotDir = ray._direction.dot(_axis);
        double axisDotOc = oc.dot(_axis);

        double a = ray._direction.dot(ray._direction) - (1 + k) * (axisDotDir * axisDotDir);
        double b = 2 * (ray._direction.dot(oc) - (1 + k) * axisDotDir * axisDotOc);
        double c = oc.dot(oc) - (1 + k) * (axisDotOc * axisDotOc);

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

        Vector3D hitPoint = ray._origin + ray._direction * dist;
        Vector3D hitToApex = hitPoint - _apex;
        double projectionLength = hitToApex.dot(_axis);

        if (projectionLength < 0 || projectionLength > _height) {
            return false;
        }

        return true;
    }

    Math::Vector3D Cone::getColor(const Ray& ray) const {
        (void)ray;
        return _color;
    }

    Math::Vector3D Cone::getNormal(const Math::Vector3D& hitpoint) const {
        Vector3D hitToApex = hitpoint - _apex;
        double m = hitToApex.dot(_axis);
        Vector3D normal = hitToApex - _axis * (1 + _angle * _angle) * m;
        normal.normalize();
        return normal;
    }

    std::vector<int> Cone::config(const libconfig::Setting& conf) {
        std::vector<int> info;
        info.push_back(conf["x"]);
        info.push_back(conf["y"]);
        info.push_back(conf["z"]);
        info.push_back(conf["angle"]);
        info.push_back(conf["height"]);
        info.push_back(conf["color"]["r"]);
        info.push_back(conf["color"]["g"]);
        info.push_back(conf["color"]["b"]);
        return info;
    }
};

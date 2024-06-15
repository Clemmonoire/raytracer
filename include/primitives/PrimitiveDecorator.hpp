/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** PrimitiveDecorator
*/

#ifndef PRIMITIVEDECORATOR_HPP_
#define PRIMITIVEDECORATOR_HPP_

#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <stdexcept>
#include "Rotations.hpp"

namespace RayTracer {
    class PrimitiveDecorator : public IPrimitive {
        public:
            PrimitiveDecorator(std::unique_ptr<IPrimitive> primitive)  : _primitive(std::move(primitive)) {};
            virtual bool hits(const Ray &ray, double &t) const override {
                return _primitive->hits(ray, t);
            }

            virtual Math::Vector3D getColor(const Ray &ray) const override {
                return _primitive->getColor(ray);
            }

            virtual Math::Vector3D getNormal(const Math::Vector3D &point) const override {
                return _primitive->getNormal(point);
            }
            void translate(Math::Vector3D plane, Math::Vector3D dir) {
                plane += dir;
            }
            std::unique_ptr<IPrimitive> _primitive;
    };

    class TranslationDecorator : public PrimitiveDecorator {
        public:
            TranslationDecorator(std::unique_ptr<IPrimitive> primitive, const Math::Vector3D& translation)
                : PrimitiveDecorator(std::move(primitive)), _translation(translation) {}

            virtual bool hits(const Ray &ray, double &t) const override {
                Ray translatedRay(ray._origin - _translation, ray._direction);
                return _primitive->hits(translatedRay, t);
            }

            virtual Math::Vector3D getNormal(const Math::Vector3D &point) const override {
                Math::Vector3D translatedPoint = point - _translation;
                return _primitive->getNormal(translatedPoint);
            }

        private:
            Math::Vector3D _translation;
    };

    class RotationDecorator : public PrimitiveDecorator {
        public:
            RotationDecorator(std::unique_ptr<IPrimitive> primitive, const Math::Vector3D& axis, double angle)
                : PrimitiveDecorator(std::move(primitive)), _rotationMatrix(Math::Matrix3x3::rotationMatrix(axis, angle)),
                _inverseRotationMatrix(Math::Matrix3x3::rotationMatrix(axis, -angle)) {}

            virtual bool hits(const Ray &ray, double &t) const override {
                // Rotate the ray in the opposite direction
                Ray rotatedRay(_inverseRotationMatrix * ray._origin, _inverseRotationMatrix * ray._direction);
                return _primitive->hits(rotatedRay, t);
            }

            virtual Math::Vector3D getNormal(const Math::Vector3D &point) const override {
                // Rotate the point back and get the normal
                Math::Vector3D rotatedPoint = _inverseRotationMatrix * point;
                Math::Vector3D normal = _primitive->getNormal(rotatedPoint);
                // Rotate the normal to match the original orientation
                return _rotationMatrix * normal;
            }

            virtual Math::Vector3D getColor(const Ray& ray) const override {
                // No rotation needed for color calculation
                return _primitive->getColor(ray);
            }

        private:
            Math::Matrix3x3 _rotationMatrix;
            Math::Matrix3x3 _inverseRotationMatrix;
    };
};

#endif /* !PRIMITIVEDECORATOR_HPP_ */

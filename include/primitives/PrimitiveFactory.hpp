/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** PrimitiveFactory.hpp
*/

#ifndef PRIMITIVEFACTORY_HPP
#define PRIMITIVEFACTORY_HPP

#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <stdexcept>
#include "Cylindre.hpp"


namespace RayTracer {
    class PrimitiveFactory 
    {
        public:
            static std::unique_ptr<IPrimitive> createPrimitive(const std::string& type, const std::vector<int>& info) {
                if (type == "sphere") {
                    return std::make_unique<Sphere>(info);
                } else if (type == "plane") {
                    return std::make_unique<Plane>(info);
                } else if (type == "cone") {
                    return std::make_unique<Cone>(info);
                } else if (type == "cylinder") {
                    return std::make_unique<Cylindre>(info);
                } else {
                    throw std::invalid_argument("Primitive type " + type + " not recognized.");
                }
            }
    };
};

#endif

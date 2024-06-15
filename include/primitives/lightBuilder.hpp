/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** lightBuilder
*/

#ifndef LIGHTBUILDER_HPP_
#define LIGHTBUILDER_HPP_
#include "IPrimitive.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>
#include <vector>
#include <stdexcept>
#include "Ilight.hpp"

namespace RayTracer {
    class PointLight : public ILight
    {
        public:
            // Constructor, methods, properties for PointLight...
            void addObserver(std::shared_ptr<ILightObserver> observer) {
                observers.push_back(observer);
            }
            void removeObserver(std::shared_ptr<ILightObserver> observer) {
                // Implement removal logic if needed
            }
            void notifyObservers() {
                for (auto& observer : observers) {
                    observer->update(*this);
                }
            }
        private:
            std::vector<std::shared_ptr<ILightObserver>> observers;
    };
    class DirectionalLight : public ILight
    {
        public:
            // Constructor, methods, properties for PointLight...
            void addObserver(std::shared_ptr<ILightObserver> observer) {
                observers.push_back(observer);
            }
            void removeObserver(std::shared_ptr<ILightObserver> observer) {
                // Implement removal logic if needed
            }
            void notifyObservers() {
                for (auto& observer : observers) {
                    observer->update(*this);
                }
            }
        private:
            std::vector<std::shared_ptr<ILightObserver>> observers;
    };
};
#endif /* !LIGHTBUILDER_HPP_ */

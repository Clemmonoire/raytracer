/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Scene.hpp
*/

#ifndef SCENE_HPP
#define SCENE_HPP

#include "primitives/IPrimitive.hpp"
#include "primitives/PrimitiveFactory.hpp"
#include "Camera.hpp"
#include <vector>
#include <memory>
#include "Draw.hpp"
#include <iostream>
#include "primitives/PrimitiveDecorator.hpp"
#include "Light.hpp"

namespace RayTracer {
    class Scene
    {
        public:
            Scene();
            ~Scene();
            void addPrimitive(std::unique_ptr<IPrimitive> primitive);
            int getWidth() const;
            int getHeight() const;
            Math::Vector3D trace(Ray &);
            void loadConfig(const std::string &configFile);
            void loadCameraConfig(const libconfig::Setting &camera);
            void loadPrimitivesConfig(const libconfig::Setting &primitives);
            void launch();
            void loadLightsConfig(const libconfig::Setting &lights);
            Math::Vector3D castRay(const Ray &, const int &, const double &);
            std::unique_ptr<Camera> _camera;

        private:
            std::vector<std::unique_ptr<IPrimitive>> primitives;
            std::vector<std::unique_ptr<Light>> _lights;
            int _width;
            int _height;
            double ambient_light_multiplier;
            double diffuse_light_multiplier;
            libconfig::Config cfg;
            Draw _draw;
    };
}

#endif

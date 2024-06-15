/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** SceneBuilder.hpp
*/

#ifndef SCENEBUILDER_HPP
#define SCENEBUILDER_HPP

#include "Scene.hpp"
#include "PrimitiveFactory.hpp"

namespace RayTracer {
    class SceneBuilder
    {
        private:
            Scene scene;
            PrimitiveFactory factory;

        public:
            SceneBuilder &addSphere()
            {
                scene.addPrimitive(factory.createPrimitive("sphere"));
                return *this;
            }

            SceneBuilder &addPlane()
            {
                scene.addPrimitive(factory.createPrimitive("plane"));
                return *this;
            }

            Scene build()
            {
                return std::move(scene);
            }
    };
}

#endif

/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "primitives/Rectangle3D.hpp"
#include "Ray.hpp"

namespace RayTracer {
    class Camera {
        public:
            Camera();
            ~Camera();
            Ray ray(double u, double v);
            void setPosition(double x, double y, double z);
            void setRotation(double x, double y, double z);
            void setResolution(int width, int height);
            void setFieldOfView(double fov);

        private:
            Math::Vector3D _origin;
            Math::Vector3D _rotation;
            Rectangle3D _screen;
            int _width;
            int _height;
            double _field_of_view;
    };
};

#endif /* !CAMERA_HPP_ */

/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Ilight
*/

#ifndef ILIGHT_HPP_
#define ILIGHT_HPP_
#include <memory>
namespace RayTracer {
    class ILightObserver;

    class ILight {
    public:
        virtual ~ILight() = default;
        virtual void addObserver(std::shared_ptr<ILightObserver> observer) = 0;
        virtual void removeObserver(std::shared_ptr<ILightObserver> observer) = 0;
        virtual void notifyObservers() = 0;
    };

    class ILightObserver {
    public:
        virtual ~ILightObserver() = default;
        virtual void update(const ILight& light) = 0;
    };
};

#endif /* !ILIGHT_HPP_ */

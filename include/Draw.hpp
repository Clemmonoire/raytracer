/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Draw
*/

#ifndef DRAW_HPP_
#define DRAW_HPP_
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Types.h>
#include <SFML/Window/Export.hpp>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "Vector3D.hpp"
#include "primitives/PrimitiveDecorator.hpp"

class Draw {
    public:
        Draw();
        ~Draw();
        void screenshot();
        void draw_wind();
        void setScreen(int, int);
        void get_input(const sf::Keyboard::Key keycode);
        sf::Image screen;
    protected:
    private:
        sf::RenderWindow window;
        sf::Texture screent;
        sf::Sprite screens;
};

#endif /* !DRAW_HPP_ */

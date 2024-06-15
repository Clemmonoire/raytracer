/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Draw
*/

#include "Draw.hpp"

Draw::Draw()
{
    window.create(sf::VideoMode(1920, 1080), "Raytracer");
}

Draw::~Draw()
{
}

void Draw::setScreen(int width, int height)
{
    screen.create(width, height);
}

void Draw::screenshot()
{
    unsigned int width = screen.getSize().x;
    unsigned int height = screen.getSize().y;

    std::ofstream ppmFile("screenshot.ppm");
    ppmFile << "P3\n";
    ppmFile << width << " " << height << "\n";
    ppmFile << "255\n";
    for (unsigned int y = 0; y < height; ++y)
        for (unsigned int x = 0; x < width; ++x) {
            sf::Color color = screen.getPixel(x, y);
            ppmFile << static_cast<int>(color.r) << " " << static_cast<int>(color.g) << " " << static_cast<int>(color.b) << "\n";
        }
    ppmFile.close();
}

void Draw::get_input(const sf::Keyboard::Key keycode)
{
    // Math::Vector3D plane;
    // Math::Vector3D temp;
    // RayTracer::PrimitiveDecorator sim;
    if (keycode >= sf::Keyboard::K)
        screenshot();
    // if (keycode >= sf::Keyboard::Z) {
    //     temp._x += 1;
    //     sim.translate(plane, temp);
    // }
    // if (keycode >= sf::Keyboard::Q) {
    //     temp._y -= 1;
    //     sim.translate(plane, temp);
    // }
    // if (keycode >= sf::Keyboard::S) {
    //     temp._x -= 1;
    //     sim.translate(plane, temp);
    // }
    // if (keycode >= sf::Keyboard::D) {
    //     temp._y += 1;
    //     sim.translate(plane, temp);
    // }
}

void Draw::draw_wind()
{
    sf::Event event;
    screent.loadFromImage(screen);
    screens.setTexture(screent, true);
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                const sf::Keyboard::Key keycode = event.key.code;
                get_input(keycode);
            }
        }
        window.draw(screens);
        window.display();
    }
}


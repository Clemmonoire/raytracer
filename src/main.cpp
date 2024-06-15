/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** main
*/

#include "primitives/IPrimitive.hpp"
#include "Scene.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Graphics/Color.hpp"

int main (int argc, char **argv)
{
    RayTracer::Scene scene;

    if (argc != 2)
        return 84;
    std::string arg = argv[1];
    if (arg == "--help") {
        std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
        std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
        return 0;
    }
    scene.loadConfig(arg);
    scene.launch();
    return 0;
}

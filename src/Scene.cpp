/*
** EPITECH PROJECT, 2024
** B-OOP-400-LYN-4-1-raytracer-camille.erades
** File description:
** Scene
*/

#include "../include/Scene.hpp"

void thread(RayTracer::Scene &scene, sf::Image &image)
{
    const int width = scene.getWidth();
    const int height = scene.getHeight();
    Math::Vector3D color;

    for (int y = 0; y < height; ++y)
        for (int x = 0; x < width; ++x) {
            RayTracer::Ray ray = scene._camera->ray(x, y);
            color = scene.trace(ray);
            image.setPixel(x, y, sf::Color(color._x, color._y, color._z));
        }
}

namespace RayTracer {
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::launch()
    {
        _draw.setScreen(_width, _height);
        thread(*this, _draw.screen);
        _draw.draw_wind();
    }

    void Scene::addPrimitive(std::unique_ptr<IPrimitive> primitive)
    {
        primitives.push_back(std::move(primitive));
    }

    int Scene::getWidth() const
    {
        return _width;
    }

    int Scene::getHeight() const
    {
        return _height;
    }

    Math::Vector3D Scene::castRay(const Ray &ray, const int &rindex, const double &t)
    {
        Math::Vector3D hitpoint = ray._origin + ray._direction * t;
        double coef = diffuse_light_multiplier * ambient_light_multiplier * 1;
        Math::Vector3D normal = primitives[rindex]->getNormal(hitpoint);

        for (const auto& light : _lights) {
            int lindex = -1;
            double lnearest = INFINITY;
            double l;
            Ray lightRay(light->getOrigin(), hitpoint - light->getOrigin());
            for (std::size_t i = 0; i < primitives.size(); i++) {
                if (primitives[i]->hits(lightRay, l) && l < lnearest) {
                    lnearest = l;
                    lindex = i;
                }
            }
            if (lindex == rindex) {
                Math::Vector3D lightDir = light->getOrigin() - hitpoint;
                lightDir.normalize();
                coef += diffuse_light_multiplier * light->getIntensity() * std::max(lightDir.dot(normal), 0.0);
            }
        }
        coef = std::min(1.0, coef);
        return primitives[rindex]->getColor(ray) * coef;
    }

    Math::Vector3D Scene::trace(Ray &ray)
    {
        double t;
        double tnearest = INFINITY;
        int index = -1;
        Math::Vector3D color;

        for (std::size_t i = 0; i < primitives.size(); i++) {
            if (primitives[i]->hits(ray, t) && t < tnearest) {
                tnearest = t;
                index = i;
            }
        }
        if (index >= 0)
            color = castRay(ray, index, tnearest);
        return color;
    }

    void Scene::loadCameraConfig(const libconfig::Setting &camera)
    {
        int resolution_width = camera["resolution"]["width"];
        int resolution_height = camera["resolution"]["height"];
        int position_x = camera["position"]["x"];
        int position_y = camera["position"]["y"];
        int position_z = camera["position"]["z"];
        int rotation_x = camera["rotation"]["x"];
        int rotation_y = camera["rotation"]["y"];
        int rotation_z = camera["rotation"]["z"];
        double field_of_view = camera["fieldOfView"];

        _camera = std::make_unique<Camera>();
        _camera->setPosition(position_x, position_y, position_z);
        _camera->setRotation(rotation_x, rotation_y, rotation_z);
        _camera->setResolution(resolution_width, resolution_height);
        _width = resolution_width;
        _height = resolution_height;
        _camera->setFieldOfView(field_of_view);
    }

    void Scene::loadPrimitivesConfig(const libconfig::Setting &info_primitives)
    {
        if (info_primitives.exists("spheres"))
            for (int i = 0; i < info_primitives["spheres"].getLength(); i++) {
                std::vector<int> info = Sphere::config(info_primitives["spheres"][i]);
                primitives.push_back(PrimitiveFactory::createPrimitive("sphere", info));
            }

        if (info_primitives.exists("planes"))
            for (int i = 0; i < info_primitives["planes"].getLength(); i++) {
                std::vector<int> info = Plane::config(info_primitives["planes"][i]);
                primitives.push_back(PrimitiveFactory::createPrimitive("plane", info));
            }

        if (info_primitives.exists("cones"))
            for (int i = 0; i < info_primitives["cones"].getLength(); i++) {
                std::vector<int> info = Cone::config(info_primitives["cones"][i]);            
                primitives.push_back(PrimitiveFactory::createPrimitive("cone", info));
            }

        if (info_primitives.exists("cylinders"))
            for (int i = 0; i < info_primitives["cylinders"].getLength(); i++) {
                std::vector<int> info = Cylindre::config(info_primitives["cylinders"][i]);
                primitives.push_back(PrimitiveFactory::createPrimitive("cylinder", info));
            }

        if (info_primitives.exists("transformation"))
            for (int i = 0; i < info_primitives["transformation"].getLength(); i++) {

                const libconfig::Setting &transfo = info_primitives["transformation"][i];
                int x = transfo["x"];
                int y = transfo["y"];
                int z = transfo["z"];
                Math::Vector3D matrix(x, y, z);
                int index = transfo["index"];
                index = std::min((int)primitives.size(), index);
                std::string type = transfo["Type"];
                if (type == "Translation")
                    primitives[index] = std::make_unique<TranslationDecorator>(std::move(primitives[index]), matrix);
                if (type == "Rotation") {
                    int agl = transfo["angle"];
                    primitives[index] = std::make_unique<RotationDecorator>(std::move(primitives[index]), matrix, (agl * M_PI / 180.0));
                }
            }
    }

    void Scene::loadLightsConfig(const libconfig::Setting &lights)
    {
        double ambient = lights["ambient"];
        double difuse = lights["diffuse"];
        ambient_light_multiplier = std::min(1.0, std::max(ambient, 0.0));
        diffuse_light_multiplier = std::min(1.0, std::max(difuse, 0.0));
        if (lights.exists("point")) {
            const libconfig::Setting &point_lights = lights["point"];
            for (int i = 0; i < point_lights.getLength(); ++i) {
                std::pair<Math::Vector3D, double> info = Light::config(point_lights[i]);
                _lights.push_back(std::make_unique<Light>(info.first, info.second));
            }
        }
    }

    void Scene::loadConfig(const std::string &configFile)
    {
        try {
            cfg.readFile(configFile.c_str());
        } catch (const libconfig::FileIOException &e) {
            std::cerr << "Error: Unable to open configuration file " << configFile << "." << std::endl;
            std::exit(84);
        } catch (const libconfig::ParseException &e) {
            std::cerr << "Error parsing configuration file " << configFile << " at line "
                    << e.getLine() << ": " << e.getError() << std::endl;
            std::exit(84);
        }

        const libconfig::Setting &camera = cfg.lookup("camera");
        loadCameraConfig(camera);

        if (cfg.exists("primitives")) {
            const libconfig::Setting &primitives = cfg.lookup("primitives");
            loadPrimitivesConfig(primitives);
        }

        if (cfg.exists("lights")) {
            const libconfig::Setting &lights = cfg.lookup("lights");
            loadLightsConfig(lights);
        }
    }
};


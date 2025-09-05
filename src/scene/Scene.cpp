#include "Scene.h"

#include <algorithm>

using namespace pathtracer::scene;

void Scene::addObject(const std::shared_ptr<object::Object> &object) {
    this->objects.push_back(object);
}

std::optional<pathtracer::object::Intersection> Scene::intersect(const core::Ray &ray) const {
    std::vector<object::Intersection> xs;
    for (auto &object: this->objects) {
        auto x = object->intersect(ray);
        if (x.has_value()) {
            xs.push_back(*x);
        }
    }

    if (xs.empty()) {
        return {};
    }

    auto result = std::min_element(xs.begin(), xs.end(), [](const auto &a, const auto &b) {
        return a.t < b.t;
    });

    return *result;
}

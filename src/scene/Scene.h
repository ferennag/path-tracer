#pragma once
#include <memory>
#include <vector>

#include "object/Object.h"

namespace pathtracer::scene {
    class Scene {
        std::vector<std::shared_ptr<object::Object>> objects;

    public:
        void addObject(const std::shared_ptr<object::Object> &object);

        [[nodiscard]] std::optional<object::Intersection> intersect(const core::Ray &ray) const;
    };
};

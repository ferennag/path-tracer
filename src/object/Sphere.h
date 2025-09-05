#pragma once
#include <optional>
#include "Object.h"

namespace pathtracer::object {
    struct Sphere : Object {
        core::Point3 center;
        core::Float radius;

        Sphere(const core::Point3 &center, core::Float radius);

        ~Sphere() override = default;

        [[nodiscard]] std::optional<Intersection> intersect(const core::Ray &ray) const override;
    };
}

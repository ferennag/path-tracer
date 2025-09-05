#pragma once
#include <optional>

#include "Intersection.h"

namespace pathtracer::object {
    class Object {
    public:
        virtual ~Object() = default;

        [[nodiscard]] virtual std::optional<Intersection> intersect(const core::Ray &ray) const = 0;
        [[nodiscard]] virtual core::Vec3 normalAt(const core::Point3 &p) const = 0;
    };
}

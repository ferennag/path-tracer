#pragma once
#include <optional>

#include "Intersection.h"

namespace pathtracer::object {
    class Object {
    public:
        virtual ~Object() = default;

        [[nodiscard]] virtual std::optional<Intersection> intersect(const core::Ray &ray) const = 0;
    };
}

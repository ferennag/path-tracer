#pragma once
#include "Point3.h"
#include "Vec3.h"

namespace pathtracer::core {
    struct Ray {
        Point3 origin;
        Vec3 direction;

        Ray(const Point3 &origin, const Vec3 &direction) : origin(origin), direction(direction) {
        }

        [[nodiscard]] Point3 evaluate(const Float t) const {
            return this->origin + direction * t;
        }
    };
}

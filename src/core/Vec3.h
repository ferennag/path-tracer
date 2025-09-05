#pragma once
#include "types.h"

namespace pathtracer::core {
    struct Vec3 {
        Float x, y, z;

        Vec3();

        explicit Vec3(Float value);

        Vec3(Float x, Float y, Float z);

        [[nodiscard]] Float length() const;

        [[nodiscard]] Vec3 normalize() const;

        [[nodiscard]] Float dot(const Vec3 &rhs) const;

        Vec3 operator*(Float rhs) const;
    };
}

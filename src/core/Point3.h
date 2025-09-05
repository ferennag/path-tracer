#pragma once
#include "types.h"

namespace pathtracer::core {
    struct Vec3;

    struct Point3 {
        Float x, y, z;

        Point3();

        explicit Point3(Float value);

        Point3(Float x, Float y, Float z);

        Point3 operator+(const Vec3& rhs) const;

        Vec3 operator-(const Point3& rhs) const;
    };
}

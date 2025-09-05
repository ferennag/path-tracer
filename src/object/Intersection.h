#pragma once
#include <memory>

#include "core/Ray.h"

namespace pathtracer::object {
    class Object;

    struct Intersection {
        core::Ray ray;
        const Object *object;
        core::Float t;
    };
}

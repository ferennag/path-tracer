#include "Sphere.h"

#include <complex>

using namespace pathtracer::object;

Sphere::Sphere(const core::Point3 &center, core::Float radius) : center(center), radius(radius) {
}

std::optional<Intersection> Sphere::intersect(const core::Ray &ray) const {
    auto L = ray.origin - center;
    auto a = ray.direction.dot(ray.direction);
    auto b = 2 * ray.direction.dot(L);
    auto c = L.dot(L) - radius * radius;
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0.0) {
        return {};
    }

    if (discriminant == 0.0) {
        auto t = (-b + std::sqrt(discriminant)) / 2 * a;
        return Intersection{.ray = ray, .object = this, .t = t};
    }

    auto t0 = (-b + std::sqrt(discriminant)) / 2 * a;
    auto t1 = (-b - std::sqrt(discriminant)) / 2 * a;

    if (t1 < t0) {
        std::swap(t0, t1);
    }

    if (t1 < 0.0) {
        return {};
    }

    if (t0 < 0.0) {
        return Intersection{.ray = ray, .object = this, .t = t1};
    }

    return Intersection{.ray = ray, .object = this, .t = t0};
}

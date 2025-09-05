#include "Sphere.h"

#include <complex>

using namespace pathtracer::object;

Sphere::Sphere(const core::Point3 &center, core::Float radius) : center(center), radius(radius) {
}

std::optional<Intersection> Sphere::intersect(const core::Ray &ray) const {
    const auto L = ray.origin - center;
    const auto a = ray.direction.dot(ray.direction);
    const auto b = 2 * ray.direction.dot(L);
    const auto c = L.dot(L) - radius * radius;
    const auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0.0) {
        return {};
    }

    if (discriminant == 0.0) {
        const auto t = (-b + std::sqrt(discriminant)) / 2 * a;
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

pathtracer::core::Vec3 Sphere::normalAt(const core::Point3 &p) const {
    auto result = p - center;
    return result.normalize();
}

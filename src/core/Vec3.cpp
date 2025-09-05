#include "Vec3.h"

#include <complex>
using namespace pathtracer::core;

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {
}

Vec3::Vec3(const Float value) : x(value), y(value), z(value) {
}

Vec3::Vec3(const Float x, const Float y, const Float z) : x(x), y(y), z(z) {
}

Float Vec3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::normalize() const {
    const auto length = this->length();
    return {
        x / length,
        y / length,
        z / length
    };
}

Float Vec3::dot(const Vec3 &rhs) const {
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vec3 Vec3::operator*(const Float rhs) const {
    return {
        this->x * rhs,
        this->y * rhs,
        this->z * rhs
    };
}

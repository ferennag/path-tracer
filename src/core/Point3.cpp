#include "Point3.h"
#include "core/Vec3.h"
using namespace pathtracer::core;

Point3::Point3() : x(0.0), y(0.0), z(0.0) {
}

Point3::Point3(const Float value) : x(value), y(value), z(value) {
}

Point3::Point3(const Float x, const Float y, const Float z) : x(x), y(y), z(z) {
}

Point3 Point3::operator+(const Vec3 &rhs) const {
    return {this->x + rhs.x, this->y + rhs.y, this->z + rhs.z};
}

Vec3 Point3::operator-(const Point3 &rhs) const {
    return {this->x - rhs.x, this->y - rhs.y, this->z - rhs.z};
}

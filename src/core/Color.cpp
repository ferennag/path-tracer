#include "Color.h"

#include <cmath>
#include <complex>

using namespace pathtracer::core;

Color::Color() : r(0.0), g(0.0), b(0.0) {
}

Color::Color(const Float value) : r(value), g(value), b(value) {
}

Color::Color(const Float r, const Float g, const Float b) : r(r), g(g), b(b) {
}

static uint8_t normalize(const Float value) {
    if (value > 1.0) {
        return 255;
    } else if (value <= 0.0) {
        return 0;
    } else {
        return static_cast<uint8_t>(std::round(value * 255.0));
    }
}

uint8_t Color::r_u8() const {
    return normalize(this->r);
}

uint8_t Color::g_u8() const {
    return normalize(this->g);
}

uint8_t Color::b_u8() const {
    return normalize(this->b);
}

Color Color::operator+(const Color &rhs) const {
    return {this->r + rhs.r, this->g + rhs.g, this->b + rhs.b};
}

Color Color::operator-(const Color &rhs) const {
    return {this->r - rhs.r, this->g - rhs.g, this->b - rhs.b};
}

Color Color::operator*(const Color &rhs) const {
    return {this->r * rhs.r, this->g * rhs.g, this->b * rhs.b};
}

Color Color::black() {
    return {0.0, 0.0, 0.0};
}

Color Color::white() {
    return {1.0, 1.0, 1.0};
}

Color Color::red() {
    return {1.0, 0.0, 0.0};
}

Color Color::green() {
    return {0.0, 1.0, 0.0};
}

Color Color::blue() {
    return {0.0, 0.0, 1.0};
}

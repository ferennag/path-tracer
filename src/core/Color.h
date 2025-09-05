#pragma once
#include <cstdint>

#include "types.h"

namespace pathtracer::core {
    struct Color {
        Float r, g, b;

        Color();

        explicit Color(Float value);

        Color(Float r, Float g, Float b);

        [[nodiscard]] uint8_t r_u8() const;

        [[nodiscard]] uint8_t g_u8() const;

        [[nodiscard]] uint8_t b_u8() const;

        Color operator+(const Color &rhs) const;

        Color operator-(const Color &rhs) const;

        Color operator*(const Color &rhs) const;

        Color operator*(const Float &rhs) const;

        static Color black();

        static Color white();

        static Color red();

        static Color green();

        static Color blue();
    };
}

#pragma once
#include <vector>

#include "core/Color.h"

namespace pathtracer::renderer {
    class ImageBuffer {
        std::vector<core::Color> pixels;
        unsigned int width, height;

        [[nodiscard]] unsigned int index(unsigned int x, unsigned int y) const {
            return y * this->width + x;
        }

    public:
        ImageBuffer(unsigned int width, unsigned int height) : width(width), height(height) {
            this->pixels = std::vector(width * height, core::Color::black());
        }

        void resize(unsigned int width, unsigned int height) {
            this->width = width;
            this->height = height;
            this->pixels = std::vector(width * height, core::Color::black());
        }


        [[nodiscard]] core::Color getPixel(unsigned int x, unsigned int y) const {
            return this->pixels[this->index(x, y)];
        }

        void setPixel(unsigned int x, unsigned int y, const core::Color &color) {
            this->pixels[this->index(x, y)] = color;
        }

        [[nodiscard]] unsigned int getWidth() const {
            return width;
        }

        [[nodiscard]] unsigned int getHeight() const {
            return height;
        }

        void clear(const core::Color &clearColor) {
            for (auto &pixel: this->pixels) {
                pixel = clearColor;
            }
        }
    };
}

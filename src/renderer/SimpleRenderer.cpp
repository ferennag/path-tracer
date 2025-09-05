#include "SimpleRenderer.h"

#include "core/Point3.h"
#include "core/Ray.h"
#include "core/Vec3.h"
#include "scene/Scene.h"

using namespace pathtracer::renderer;

SimpleRenderer::SimpleRenderer(unsigned int width, unsigned int height) : buffer(ImageBuffer(width, height)) {
}

void SimpleRenderer::resize(unsigned int width, unsigned int height) {
    this->buffer.resize(width, height);
}

ImageBuffer SimpleRenderer::render(const scene::Scene &scene) {
    const core::Point3 eye{0.0, 0.0, 5.0};
    auto aspectRatio = static_cast<core::Float>(this->buffer.getWidth()) / static_cast<core::Float>(this->buffer.
                           getHeight());
    const auto h = 2.0;
    const auto w = h * aspectRatio;
    const auto w_half = w / 2.0;
    const auto h_half = h / 2.0;
    const auto u = core::Vec3(w / static_cast<core::Float>(this->buffer.getWidth()), 0.0, 0.0);
    const auto v = core::Vec3(0.0, -h / static_cast<core::Float>(this->buffer.getHeight()), 0.0);
    const auto pixel_00 = core::Point3(-w_half, h_half, 0.0) + u * 0.5 + v * 0.5;

    this->buffer.clear(core::Color::black());
    for (int y = 0; y < this->buffer.getHeight(); ++y) {
        for (int x = 0; x < this->buffer.getWidth(); ++x) {
            auto pixel = pixel_00 + u * x + v * y;
            auto direction = pixel - eye;
            auto ray = core::Ray(eye, direction);

            if (const auto intersection = scene.intersect(ray)) {
                this->buffer.setPixel(x, y, core::Color::red());
            }
        }
    }

    return this->buffer;
}

#include "SimpleRenderer.h"

#include <future>
#include <thread>

#include "core/Point3.h"
#include "core/Ray.h"
#include "core/Vec3.h"
#include "scene/Scene.h"

using namespace pathtracer::renderer;

SimpleRenderer::SimpleRenderer(unsigned int width, unsigned int height) : width(width), height(height) {
}

void SimpleRenderer::resize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
}

ImageBuffer SimpleRenderer::doRender(const scene::Scene &scene) {
    const core::Point3 eye{0.0, 0.0, 5.0};
    const auto aspectRatio = static_cast<core::Float>(width) / static_cast<core::Float>(height);
    const auto h = 2.0;
    const auto w = h * aspectRatio;
    const auto w_half = w / 2.0;
    const auto h_half = h / 2.0;
    const auto u = core::Vec3(w / static_cast<core::Float>(width), 0.0, 0.0);
    const auto v = core::Vec3(0.0, -h / static_cast<core::Float>(height), 0.0);
    const auto pixel_00 = core::Point3(-w_half, h_half, 0.0) + u * 0.5 + v * 0.5;

    ImageBuffer buffer(width, height);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto pixel = pixel_00 + u * x + v * y;
            auto direction = (pixel - eye).normalize();
            auto ray = core::Ray(eye, direction);

            if (const auto intersection = scene.intersect(ray)) {
                auto point = intersection->ray.evaluate(intersection->t);
                auto normal = intersection->object->normalAt(point);
                auto omega_i = normal.dot(-ray.direction);
                buffer.setPixel(x, y, core::Color::red() * omega_i);
            }
        }
    }

    return buffer;
}

std::future<ImageBuffer> SimpleRenderer::render(const scene::Scene &scene) {
    promise = {};

    auto thread = std::thread([this, &scene] {
        const auto buffer = this->doRender(scene);
        promise.set_value(buffer);
    });
    thread.detach();

    return promise.get_future();
}

#pragma once
#include "Renderer.h"

namespace pathtracer::renderer {
    class SimpleRenderer : public Renderer {
        ImageBuffer buffer;

    public:
        SimpleRenderer(unsigned int width, unsigned int height);

        ~SimpleRenderer() override = default;

        void resize(unsigned int width, unsigned int height) override;

        [[nodiscard]] ImageBuffer render(const scene::Scene &scene) override;
    };
}

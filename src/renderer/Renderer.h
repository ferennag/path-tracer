#pragma once
#include "ImageBuffer.h"

namespace pathtracer::scene {
    class Scene;
}

namespace pathtracer::renderer {
    class Renderer {
    public:
        virtual ~Renderer() = default;

        virtual void resize(unsigned int width, unsigned int height) = 0;

        [[nodiscard]] virtual ImageBuffer render(const scene::Scene &scene) = 0;
    };
}

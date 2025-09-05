#pragma once
#include "Renderer.h"

namespace pathtracer::renderer {
    class SimpleRenderer : public Renderer {
        unsigned int width, height;
        std::promise<ImageBuffer> promise;
        std::mutex renderMutex;

        ImageBuffer doRender(const scene::Scene &scene);
    public:
        SimpleRenderer(unsigned int width, unsigned int height);

        ~SimpleRenderer() override = default;

        void resize(unsigned int width, unsigned int height) override;

        [[nodiscard]] std::future<ImageBuffer> render(const scene::Scene &scene) override;
    };
}

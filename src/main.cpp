#include <SDL3/SDL.h>

#include "object/Sphere.h"
#include "renderer/SimpleRenderer.h"
#include "scene/Scene.h"

using namespace pathtracer;

int main(int argc, char **argv) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Path Tracer", 800, 600, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);
    if (!window) {
        SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Texture *image = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING, 800, 600);

    scene::Scene scene;
    scene.addObject(std::make_shared<object::Sphere>(core::Point3(0.0, 0.0, -5.0), 1.0));
    renderer::SimpleRenderer sceneRenderer(800, 600);

    auto running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT: {
                    running = false;
                    break;
                }
                case SDL_EVENT_WINDOW_RESIZED: {
                    SDL_DestroyTexture(image);
                    image = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR8888, SDL_TEXTUREACCESS_STREAMING,
                                              event.window.data1,
                                              event.window.data2);
                    sceneRenderer.resize(event.window.data1, event.window.data2);
                    break;
                }
                case SDL_EVENT_KEY_DOWN: {
                    switch (event.key.key) {
                        case SDLK_ESCAPE: {
                            running = false;
                            break;
                        }
                        default: break;
                    }
                }
                default: break;
            }
        }

        auto result = sceneRenderer.render(scene);

        uint8_t *pixels;
        int pitch;
        SDL_LockTexture(image, nullptr, reinterpret_cast<void **>(&pixels), &pitch);
        for (int y = 0; y < result.getHeight(); ++y) {
            for (int x = 0; x < result.getWidth(); ++x) {
                auto color = result.getPixel(x, y);
                auto pos = (y * result.getWidth() + x) * 4;
                pixels[pos] = color.r_u8(); // R
                pixels[pos + 1] = color.g_u8(); // G
                pixels[pos + 2] = color.b_u8(); // B
                pixels[pos + 3] = 255; // A
            }
        }
        SDL_UnlockTexture(image);

        SDL_SetRenderDrawColorFloat(renderer, 0.0f, 0.0f, 0.0f, 1.0f);
        SDL_RenderClear(renderer);
        SDL_RenderTexture(renderer, image, nullptr, nullptr);
        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}

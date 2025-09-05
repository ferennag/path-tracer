cmake_minimum_required(VERSION 3.5)
project(path-tracer)
include(FetchContent)
FetchContent_Declare(SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG release-3.2.22
)
FetchContent_MakeAvailable(SDL3)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/renderer/Renderer.h
        src/scene/Scene.cpp
        src/scene/Scene.h
        src/object/Object.h
        src/renderer/SimpleRenderer.cpp
        src/renderer/SimpleRenderer.h
        src/core/Vec3.cpp
        src/core/Vec3.h
        src/core/Point3.cpp
        src/core/Point3.h
        src/core/Color.cpp
        src/core/Color.h
        src/core/types.h
        src/core/Ray.h
        src/renderer/ImageBuffer.h
        src/object/Intersection.h
        src/object/Sphere.cpp
        src/object/Sphere.h
)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL3::SDL3)
target_include_directories(${PROJECT_NAME} PUBLIC src)
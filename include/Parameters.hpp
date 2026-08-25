#pragma once

namespace Param {
    constexpr double GRAVITY = 1000;

    constexpr int WIDTH = 800;
    constexpr int HEIGHT = 800;

    inline float XMIN = -800;
    inline float YMIN = -800;
    inline float XMAX = 800;
    inline float YMAX = 800;

    inline float XSCALE = WIDTH / (XMAX - XMIN);
    inline float YSCALE = HEIGHT / (YMAX - YMIN);

    constexpr double CAMERASPEED = 0.5;
    constexpr double ZOOM = 50;

    constexpr double PI = 3.14159265358979323846;
}
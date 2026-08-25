#include "Coords.hpp"

#include <SFML/Graphics.hpp>
#include "Parameters.hpp"

using namespace Param;

float sx(float x) {
    return (x - XMIN) * XSCALE;
}

float sy(float y) {
    return -(y - YMAX) * YSCALE;
}

void moveUp(float dt) {
    float ychange = (YMAX - YMIN) * CAMERASPEED * dt;
    YMIN += ychange;
    YMAX += ychange;
}

void moveDown(float dt) {
    float ychange = (YMAX - YMIN) * CAMERASPEED * dt;
    YMIN -= ychange;
    YMAX -= ychange;
}

void moveRight(float dt) {
    float xchange = (XMAX - XMIN) * CAMERASPEED * dt;
    XMIN += xchange;
    XMAX += xchange;
}

void moveLeft(float dt) {
    float xchange = (XMAX - XMIN) * CAMERASPEED * dt;
    XMIN -= xchange;
    XMAX -= xchange;
}

void zoomOut(float dt) {
    float xchange = (XMAX - XMIN) * ZOOM * dt;
    float ychange = (YMAX - YMIN) * ZOOM * dt;
    XMIN -= xchange;
    YMIN -= ychange;
    XMAX += xchange;
    YMAX += ychange;
    XSCALE = WIDTH / (XMAX - XMIN);
    YSCALE = HEIGHT / (YMAX - YMIN);
}

void zoomIn(float dt) {
    float xchange = (XMAX - XMIN) * ZOOM * dt;
    float ychange = (YMAX - YMIN) * ZOOM * dt;
    if (YMAX - YMIN < 2*ychange and XMAX - XMIN < 2*xchange) {
        return ;
    }
    XMIN += xchange;
    YMIN += ychange;
    XMAX -= xchange;
    YMAX -= ychange;
    XSCALE = WIDTH / (XMAX - XMIN);
    YSCALE = HEIGHT / (YMAX - YMIN);
}
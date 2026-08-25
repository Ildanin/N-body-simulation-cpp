#include "Star.hpp"

#include <cmath>
#include "Parameters.hpp"
#include "Coords.hpp"

Star::Star(double mass, double r, float x, float y, float x_v, float y_v) 
    : mass(mass), 
        r(r), 
        x(x), 
        y(y), 
        x_v(x_v), 
        y_v(y_v), 
        circle(r * Param::XSCALE)
{
    circle.setFillColor(sf::Color::Red);
}

void Star::update(float x_deltaV, float y_deltaV) {
    x_v += x_deltaV;
    y_v += y_deltaV;
}

void Star::move(float dt) {
    x += x_v * dt;
    y += y_v * dt;
}

sf::CircleShape Star::getShape() {
    circle.setRadius(r * Param::XSCALE);
    circle.setOrigin({circle.getRadius(), circle.getRadius()});
    circle.setPosition({sx(x), sy(y)});
    return circle;
}
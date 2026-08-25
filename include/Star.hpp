#pragma once

#include <SFML/Graphics.hpp>

class Star {
private:
    float x_v;
    float y_v;
    float x_a;
    float y_a;
    sf::CircleShape circle;

public:
    double mass;
    double r;
    float x;
    float y;

    Star(double mass, double r, float x, float y, float x_v = 0, float y_v = 0);

    void update(float x_deltaV, float y_deltaV);

    void move(float dt);

    sf::CircleShape getShape();
};
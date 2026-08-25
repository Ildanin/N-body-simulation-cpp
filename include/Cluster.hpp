#pragma once

#include "Star.hpp"
#include <SFML/Graphics.hpp>

class Cluster {
    private:
        std::vector<Star> stars;

    public:
        Cluster(std::initializer_list<Star> stars);

        void update(float dt);

        void draw(sf::RenderWindow& window);

        void append(Star star);
};
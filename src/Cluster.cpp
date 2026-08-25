#include "Cluster.hpp"

#include "Parameters.hpp"

Cluster::Cluster(std::initializer_list<Star> stars) : stars(stars) {}

void Cluster::update(float dt) {
    for (int i = 0; i < stars.size(); ++i) {
        for (int j = i+1; j < stars.size(); ++j) {
            Star star1 = stars[i];
            Star star2 = stars[j];

            float dx = star2.x - star1.x;
            float dy = star2.y - star1.y;
            float distance = sqrt(pow(dx, 2) + pow(dy, 2));
            float gravityFactor = Param::GRAVITY / pow(distance, 3) * dt;
            
            float xFactor = gravityFactor * dx;
            float yFactor = gravityFactor * dy;
            stars[i].update( xFactor * star2.mass,  yFactor * star2.mass);
            stars[j].update(-xFactor * star1.mass, -yFactor * star1.mass);
        }
    }
    for (Star& star : stars) {
        star.move(dt);
    }
}

void Cluster::draw(sf::RenderWindow& window) {
    for (Star star : stars) {
        window.draw(star.getShape());
    }
}

void Cluster::append(Star star) {
    stars.emplace_back(star);
}
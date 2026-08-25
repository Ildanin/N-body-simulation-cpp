#include "Utiles.hpp"

#include <random>

float randf(float start, float end) {
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::uniform_real_distribution<float> distribution(start, end);

    return distribution(generator);
}
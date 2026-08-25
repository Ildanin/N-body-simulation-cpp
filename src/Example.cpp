#include "Example.hpp"

#include <math.h>
#include "Star.hpp"
#include "Parameters.hpp"
#include "Utiles.hpp"

Cluster preset1(int n, double m, double r, double v) {
    Cluster cluster({});
    for (int i = 0; i < n; i++) {
        float angle = 2 * Param::PI * i / n;
        cluster.append(Star(m, 5, r * cos(angle), r * sin(angle), v * -sin(angle), v * cos(angle)));
    }
    return cluster;
}

Cluster preset2(int n, double sunM, double sunR, double systemR, double planetM, double planetR) {
    Cluster cluster({});
    cluster.append(Star(sunM, sunR, 0, 0));
    for (int i = 0; i < n; i++) {
        float r = randf(2*sunR, systemR);
        float angle = randf(0, 2*Param::PI);

        float v = sqrt(sunM * Param::GRAVITY / r) * randf(1, 2);

        cluster.append(Star(planetM * randf(0.1, 2), planetR * randf(0.5, 3), r * cos(angle), r * sin(angle), v * -sin(angle), v * cos(angle)));
    }

    return cluster;
}
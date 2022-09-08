//
// Created by kohei on 22/09/09.
//

#include "Particle.h"
Particle::Particle() {};
Particle::Particle(float x, float y, float z) : x(x), y(y), z(z){};

void Particle::set(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

std::tuple<float, float, float> Particle::get() {
    return std::make_tuple(x, y, z);
}
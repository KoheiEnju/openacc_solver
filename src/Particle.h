//
// Created by kohei on 22/09/09.
//

#ifndef OPENACC_SOLVER_PARTICLE_H
#define OPENACC_SOLVER_PARTICLE_H

#include<tuple>


class Particle {
public:
    float x = 0, y = 0, z = 0;
    Particle();
    Particle(float x, float y, float z);
    void set(float x, float y, float z);
    std::tuple<float, float, float> get();
};


#endif //OPENACC_SOLVER_PARTICLE_H

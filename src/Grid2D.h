//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_GRID2D_H
#define OPENACC_SOLVER_GRID2D_H

#include "common.h"
#include "Particle.h"
#include<vector>

using v2p = std::vector<std::vector<Particle>>;

class Grid2D {
public:
    v2p gridPosition;
    int N, H, W;
    Grid2D(v2p pos);
};


#endif //OPENACC_SOLVER_GRID2D_H

//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_GRID2D_H
#define OPENACC_SOLVER_GRID2D_H

#include "common.h"
#include<vector>

class Grid2D {
public:
    v2p gridPosition;
    int N, H, W;
    explicit Grid2D(v2p &pos);
};


#endif //OPENACC_SOLVER_GRID2D_H

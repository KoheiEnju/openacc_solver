//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_ODE_H
#define OPENACC_SOLVER_ODE_H

#include "common.h"
#include "Grid2D.h"

class ODE{
public:
    Grid2D grid;

    ODE(Grid2D grid);
    void calc_dxdt(float t, const v2p& x, v2p& dxdt);
};


#endif //OPENACC_SOLVER_ODE_H

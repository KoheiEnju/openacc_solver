//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_ODE_H
#define OPENACC_SOLVER_ODE_H

#include<vector>
#include "Grid2D.h"
using namespace std;

class ODE{
public:
    Grid2D grid;

    ODE(Grid2D grid);
    void calc_dxdt(float t, const vector<vector<float>>& x, vector<vector<float>>& dxdt);
};


#endif //OPENACC_SOLVER_ODE_H

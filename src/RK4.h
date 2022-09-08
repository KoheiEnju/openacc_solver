//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_RK4_H
#define OPENACC_SOLVER_RK4_H

#include<vector>
#include "ODE.h"
using namespace std;

class RK4 {
    ODE& ode;

    vector<vector<float>> k2;
    vector<vector<float>> k3;
    vector<vector<float>> k4;
    vector<vector<float>> xtemp;

    float c2 = 0.5;
    float c3 = 0.5;
    float c4 = 1.0;

    float a21 = 0.5;
    float a32 = 0.5;
    float a43 = 1.0;

    float b1 = 1.0/6.0;
    float b2 = 2.0/6.0;
    float b3 = 2.0/6.0;
    float b4 = 1.0/6.0;

public:
    RK4(ODE& ode);
    float integrate(const float t0, const float dt, const vector<vector<float>>& x0, vector<vector<float>>& x, const vector<vector<float>>& dxdt);
};


#endif //OPENACC_SOLVER_RK4_H

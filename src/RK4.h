//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_RK4_H
#define OPENACC_SOLVER_RK4_H

#include<common.h>
#include "ODE.h"

class RK4 {
    ODE& ode;

    v2p k2;
    v2p k3;
    v2p k4;

    v2p xtemp;
    v2p dxdttemp;

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
    float integrate(const float t0, const float dt, const v2p& x0, v2p& x, const v2p& dxdt);
    float integrate(const float t0, const float dt, const v2p& x0, v2p& x);
};


#endif //OPENACC_SOLVER_RK4_H

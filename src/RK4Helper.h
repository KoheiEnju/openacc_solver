//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_RK4HELPER_H
#define OPENACC_SOLVER_RK4HELPER_H
#include "common.h"
#include "Grid2D.h"

class RK4Helper {
public:
    static void calc(const v2p& x0, v2p& xdst, const float h, const v2p& dxdt);
    static void calc(const v2p& x0, v2p& xdst,
              const float h1, const v2p& k1,
              const float h2, const v2p& k2,
              const float h3, const v2p& k3,
              const float h4, const v2p& k4);
};


#endif //OPENACC_SOLVER_RK4HELPER_H

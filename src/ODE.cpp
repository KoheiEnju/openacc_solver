//
// Created by kohei on 22/09/08.
//

#include "ODE.h"
#include <math.h>

ODE::ODE(Grid2D grid): grid(grid){};

void ODE::calc_dxdt(float t, const v2p &x, v2p &dxdt) {
    // assert x.shape == dxdt.shape
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<this->grid.H;i++){
#pragma acc loop independent
        for(int j=0;j<this->grid.W;j++){
            // just an example
            dxdt[i][j].x = x[i][j].x - x[i][j].x * x[i][j].y;
            dxdt[i][j].y = x[i][j].x * x[i][j].y - x[i][j].y;
            dxdt[i][j].z = sin(t);
        }
    }
}

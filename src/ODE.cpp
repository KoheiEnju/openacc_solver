//
// Created by kohei on 22/09/08.
//

#include "ODE.h"
#include<cmath>

ODE::ODE(Grid2D &grid): grid(grid){
    // Do nothing
};

void ODE::calc_dxdt(float t, const v2p &x, v2p &dxdt) {
#pragma acc data copy(x, dxdt)
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<x.size();i++){
#pragma acc loop independent
        for(int j=0;j<x[0].size();j++){
            // just an example
            dxdt[i][j][0] = x[i][j][0] - x[i][j][0] * x[i][j][1];
            dxdt[i][j][1] = x[i][j][0] * x[i][j][1] - x[i][j][1];
            dxdt[i][j][2] = sin(t);
        }
    }
}

//
// Created by kohei on 22/09/08.
//
#include<common.h>
#include "RK4Helper.h"

void RK4Helper::calc(const v2p &x0, v2p &xdst, const float h,
                     const v2p &dxdt) {
    // assert x0.shape == xdst.shape
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<x0.size();i++){
#pragma acc loop independent
        for(int j=0;j<x0[0].size();j++){
            xdst[i][j].x = x0[i][j].x + h * dxdt[i][j].x;
            xdst[i][j].y = x0[i][j].y + h * dxdt[i][j].y;
            xdst[i][j].z = x0[i][j].z + h * dxdt[i][j].z;
        }
    }
}

void RK4Helper::calc(const v2p &x0, v2p &xdst, const float h1,
                     const v2p &k1, const float h2, const v2p &k2, const float h3,
                     const v2p &k3, const float h4, const v2p &k4) {
    // assert shape of x0, dst, k1, k2, k3, k4
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<x0.size();i++){
#pragma acc loop independent
        for(int j=0;j<x0[0].size();j++){
            xdst[i][j].x = x0[i][j].x + h1 * k1[i][j].x + h2 * k2[i][j].x + h3 * k3[i][j].x + h4 * k4[i][j].x;
            xdst[i][j].y = x0[i][j].y + h1 * k1[i][j].y + h2 * k2[i][j].y + h3 * k3[i][j].y + h4 * k4[i][j].y;
            xdst[i][j].z = x0[i][j].z + h1 * k1[i][j].z + h2 * k2[i][j].z + h3 * k3[i][j].z + h4 * k4[i][j].z;
        }
    }
}

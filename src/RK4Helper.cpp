//
// Created by kohei on 22/09/08.
//
#include<common.h>
#include "RK4Helper.h"

void RK4Helper::calc(const v2p &x0, v2p &xdst, const float h,
                     const v2p &dxdt) {
#pragma acc data copy(x0, dxdt, xdst)
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<x0.size();i++){
#pragma acc loop independent
        for(int j=0;j<x0[0].size();j++){
#pragma acc loop independent
            for(int k=0;k<3;k++){
                xdst[i][j][k] = x0[i][j][k] + h * dxdt[i][j][k];
            }
        }
    }
}

void RK4Helper::calc(const v2p &x0, v2p &xdst, const float h1,
                     const v2p &k1, const float h2, const v2p &k2, const float h3,
                     const v2p &k3, const float h4, const v2p &k4) {
#pragma acc data copy(x0, k1, k2, k3, k4, xdst)
#pragma acc kernels
#pragma acc loop independent
    for(int i=0;i<x0.size();i++){
#pragma acc loop independent
        for(int j=0;j<x0[0].size();j++){
#pragma acc loop independent
            for(int k=0;k<3;k++){
               xdst[i][j][k] = x0[i][j][k] + h1 * k1[i][j][k] + h2 * k2[i][j][k] + h3 * k3[i][j][k] + h4 * k4[i][j][k];
            }
        }
    }
}

//
// Created by kohei on 22/09/08.
//

#include "RK4Helper.h"
#include<vector>

void RK4Helper::calc(const vector<vector<float>> &x0, vector<vector<float>> &xdst, const float h,
                     const vector<vector<float>> &dxdt) {
    // assert x0.shape == xdst.shape
    for(int i=0;i<x0.size();i++){
        for(int j=0;j<x0[0].size();j++){
            xdst[i][j] = x0[i][j] + h * dxdt[i][j];
        }
    }
}

void RK4Helper::calc(const vector<vector<float>> &x0, vector<vector<float>> &xdst, const float h1,
                     const vector<vector<float>> &k1, const float h2, const vector<vector<float>> &k2, const float h3,
                     const vector<vector<float>> &k3, const float h4, const vector<vector<float>> &k4) {
    // assert shape of x0, dst, k1, k2, k3, k4
    for(int i=0;i<x0.size();i++){
        for(int j=0;j<x0[0].size();j++){
            xdst[i][j] = x0[i][j] + h1 * k1[i][j] + h2 * k2[i][j] + h3 * k3[i][j] + h4 * k4[i][j];
        }
    }
}

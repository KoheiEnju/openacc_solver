//
// Created by kohei on 22/09/08.
//

#include "ODE.h"
ODE::ODE(Grid2D grid): grid(grid){};

void ODE::calc_dxdt(float t, const vector<vector<float>> &x, vector<vector<float>> &dxdt) {
    // assert x.shape == dxdt.shape
    for(int i=0;i<this->grid.H;i++){
        for(int j=0;j<this->grid.W;j++){
            // hardcode. this part changes according to ODE
            dxdt[i][j] = 100 - x[i][j];
        }
    }
}

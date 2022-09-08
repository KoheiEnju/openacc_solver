//
// Created by kohei on 22/09/08.
//

#include<iostream>
#include<Grid2D.h>
#include "RK4.h"
#include "ODE.h"
using namespace  std;

int main(){
    vector<vector<float>> x0 = {
            {0, 1, 2, 3},
            {4, 5, 6, 7}
    };
    vector<vector<float>> x = {
            {0, 1, 2, 3},
            {4, 5, 6, 7}
    };
    vector<vector<float>> dxdt = {
            {0, 1, 2, 3},
            {4, 5, 6, 7}
    };
    Grid2D grid(x0);
    ODE ode(grid);
    RK4 solver(ode);

    float t0 = 0;
    float tend = 10;
    float dt = 0.01;
    float t = t0;

    while(t < tend) {
        ode.calc_dxdt(t, x0, dxdt);
        cout << x[0][0] << endl;
        solver.integrate(t, dt, x0, x, dxdt);
        x0 = x;
        t += dt;
        cout << x[0][0] << endl;
    }
}
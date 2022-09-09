//
// Created by kohei on 22/09/08.
//

#include"common.h"
#include<random>
#include"Grid2D.h"
#include "RK4.h"
#include "ODE.h"
using namespace  std;

int main(int argc, char* argv[]){
    int H = 256, W = 256;
    v2p x0(H, v2(W, Particle(3)));

    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_real_distribution<float> dist(-1.0, 1.0);

    for(auto&& line: x0){
        for(auto&& p: line){
            for(auto&& xi: p){
                xi = dist(engine);
            }
        }
    }

    v2p x;
    copy(x0.begin(), x0.end(), back_inserter(x));

    Grid2D grid(x0);
    ODE ode(grid);
    RK4 solver(ode);

    float t = 0;
    int stepN = 1 << 10;
    float dt = 0.0001;

    for(int i=0;i<stepN;i++) {
        solver.integrate(t, dt, x0, x);
        x0 = x;
        t += dt;
    }
}
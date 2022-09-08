//
// Created by kohei on 22/09/08.
//

#include"common.h"
#include<random>
#include"Grid2D.h"
#include "RK4.h"
#include "ODE.h"
#include "Particle.h"
using namespace  std;

int main(int argc, char* argv[]){
    int H = 512, W = 256;
    v2p x0(H, vector<Particle>(W));

    random_device seed_gen;
    mt19937 engine(seed_gen());
    uniform_real_distribution<float> dist(-1.0, 1.0);

    for(auto&& line: x0){
        for(auto&& p: line){
            p.x = dist(engine);
            p.y = dist(engine);
            p.z = dist(engine);
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

    int ri = 0;
    int rj = 0;
    if (argc > 1){
        ri = atoi(argv[1]);
    }
    if (argc > 2){
        rj = atoi(argv[2]);
    }

    // dataの転送をここで行う？
//#pragma data copy(x), copy(x0)
    for(int i=0;i<stepN;i++) {
        solver.integrate(t, dt, x0, x);
        x0 = x;
        t += dt;
        // cout << x[ri][rj].x << "," << x[ri][rj].y << "," << x[ri][rj].z << endl;
    }
}
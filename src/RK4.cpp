//
// Created by kohei on 22/09/08.
//

#include "RK4.h"
#include "RK4Helper.h"
#include <vector>
using namespace std;

RK4::RK4(ODE &ode): ode(ode){
    // do nothing
    this->xtemp.assign(this->ode.grid.H, vector<float>(this->ode.grid.W, 0));
    this->k2.assign(this->ode.grid.H, vector<float>(this->ode.grid.W, 0));
    this->k3.assign(this->ode.grid.H, vector<float>(this->ode.grid.W, 0));
    this->k4.assign(this->ode.grid.H, vector<float>(this->ode.grid.W, 0));
};

float RK4::integrate(const float t0, const float dt, const vector<vector<float>> &x0, vector<vector<float>>& x,
                     const vector<vector<float>> &dxdt) {
    RK4Helper::calc(x0, this->xtemp, this->a21*dt, dxdt);
    this->ode.calc_dxdt(t0 + c2 * dt, this->xtemp, k2);
    RK4Helper::calc(x0, this->xtemp, a32 * dt, k2);
    this->ode.calc_dxdt(t0 + c3 * dt, this->xtemp, k3);
    RK4Helper::calc(x0, this->xtemp, a43 * dt, k3);
    this->ode.calc_dxdt(t0 + c4 * dt, this->xtemp, k4);
    RK4Helper::calc(x0, x, b1 * dt, dxdt, b2 * dt, k2, b3 * dt, k3, b4 * dt, k4);

    return t0 + dt;

}

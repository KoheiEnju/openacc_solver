//
// Created by kohei on 22/09/08.
//
#include "common.h"
#include "RK4.h"
#include "RK4Helper.h"
#include<vector>

RK4::RK4(ODE &ode): ode(ode){
    // do nothing
    this->k2.resize(this->ode.grid.H, std::vector<Particle>(this->ode.grid.W));
    this->k3.resize(this->ode.grid.H, std::vector<Particle>(this->ode.grid.W));
    this->k4.resize(this->ode.grid.H, std::vector<Particle>(this->ode.grid.W));
    this->xtemp.resize(this->ode.grid.H, std::vector<Particle>(this->ode.grid.W));
    this->dxdttemp.resize(this->ode.grid.H, std::vector<Particle>(this->ode.grid.W));

};

float RK4::integrate(const float t0, const float dt, const v2p &x0, v2p& x,
                     const v2p &dxdt) {
    RK4Helper::calc(x0, this->xtemp, this->a21*dt, dxdt);
    this->ode.calc_dxdt(t0 + c2 * dt, this->xtemp, k2);
    RK4Helper::calc(x0, this->xtemp, a32 * dt, k2);
    this->ode.calc_dxdt(t0 + c3 * dt, this->xtemp, k3);
    RK4Helper::calc(x0, this->xtemp, a43 * dt, k3);
    this->ode.calc_dxdt(t0 + c4 * dt, this->xtemp, k4);
    RK4Helper::calc(x0, x, b1 * dt, dxdt, b2 * dt, k2, b3 * dt, k3, b4 * dt, k4);

    return t0 + dt;
}

float RK4::integrate(const float t0, const float dt, const v2p &x0, v2p &x) {
    this->ode.calc_dxdt(t0, x0, this->dxdttemp);
    return this->integrate(t0, dt, x0, x, this->dxdttemp);
}
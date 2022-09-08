//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_RK4HELPER_H
#define OPENACC_SOLVER_RK4HELPER_H
#include<vector>
using namespace std;


class RK4Helper {
public:
    static void calc(const vector<vector<float>>& x0, vector<vector<float>>& xdst, const float h, const vector<vector<float>>& dxdt);
    static void calc(const vector<vector<float>>& x0, vector<vector<float>>& xdst,
              const float h1, const vector<vector<float>>& k1,
              const float h2, const vector<vector<float>>& k2,
              const float h3, const vector<vector<float>>& k3,
              const float h4, const vector<vector<float>>& k4);
};


#endif //OPENACC_SOLVER_RK4HELPER_H

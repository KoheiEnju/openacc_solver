//
// Created by kohei on 22/09/08.
//

#ifndef OPENACC_SOLVER_GRID2D_H
#define OPENACC_SOLVER_GRID2D_H

#include<vector>
using namespace std;


class Grid2D {
public:
    vector<vector<float>> gridPosition;
    int N, H, W;
    Grid2D(vector<vector<float>> pos);
};


#endif //OPENACC_SOLVER_GRID2D_H

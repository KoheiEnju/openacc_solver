//
// Created by kohei on 22/09/08.
//

#include "Grid2D.h"
Grid2D::Grid2D(vector <vector<float>> pos){
    this->H = static_cast<int>(pos.size());
    this->W = static_cast<int>(pos[0].size());
    this->N = H * W;
    this->gridPosition.assign(H, vector<float>(W));
    for(auto i = 0;i<H;i++){
        for(auto j=0;j<W;j++){
            this->gridPosition[i][j] = pos[i][j];
        }
    }
}
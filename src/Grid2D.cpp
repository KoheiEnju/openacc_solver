//
// Created by kohei on 22/09/08.
//

#include "Grid2D.h"
#include "common.h"

Grid2D::Grid2D(v2p pos): gridPosition(pos){
    this->H = static_cast<int>(this->gridPosition.size());
    this->W = static_cast<int>(this->gridPosition[0].size());
    this->N = H * W;
}
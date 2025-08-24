#ifndef LOSS_H
#define LOSS_H

#include "dense.h"

float MSE(DenseLayer* l, float* target);
float* dMSE(DenseLayer* l, float* target);


#endif
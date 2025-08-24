#ifndef LOSS_H
#define LOSS_H

#include "dense.h"

float mean_squared_loss(DenseLayer* l);
float d_mean_squared_loss(DenseLayer* l);


#endif
#include "include/loss.h"
#include "dense.c"


float MSE(DenseLayer* l, float* target){
    float loss = 0.0f;
    for(int i = 0; i < l->out_dim; i++){
        float diff = l->out[i] - target[i];
        loss += diff * diff;
    }
    return loss / l->out_dim; 
}

float* dMSE(DenseLayer* l, float* target){
    float* grad = (float*)malloc(l->out_dim * sizeof(float));
    for(int i = 0; i < l->out_dim; i++){
        grad[i] = 2.0f * (l->out[i] - target[i]);
    }

    return grad;
}
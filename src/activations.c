#include "include/activations.h"
#include <math.h>

float relu(float x){
    if(x > 0) return x;
    return 0.0f;
}

float drelu(float x){
    if(x > 0) return 1;
    return 0.0f;
}

float tanh(float x){
    return tanhf(x);
}

float dtanh(float x){
    return 1.0f - pow(tanh(x), 2);
}

float sigmoid(float x){
    return 1.0f / (1.0f + exp(-x));
}

float dsigmoid(float x){
    return sigmoid(x) * (1.0f - sigmoid(x));
}
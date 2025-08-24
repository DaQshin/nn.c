#include "include/dense.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int in_dim, out_dim;
    float* weights;
    float* biases;
    float* dweights;
    float* dbiases;
    float* out;

} DenseLayer;

DenseLayer* init_layer(int in_dim, int out_dim){
    DenseLayer* layer = (DenseLayer*)malloc(sizeof(DenseLayer));
    if(!layer){
        perror("DenseLayer: allocation failed.");
        exit(1);
    }

    layer->in_dim = in_dim;
    layer->out_dim = out_dim;

    layer->weights = (float*)malloc(in_dim * out_dim * sizeof(float));
    layer->biases = (float*)malloc(out_dim * sizeof(float));
    layer->dweights = (float*)malloc(in_dim * out_dim * sizeof(float));
    layer->dbiases = (float*)malloc(out_dim * sizeof(float));
    layer->out = (float*)malloc(out_dim * sizeof(float));

    if(layer->weights || layer->biases || layer->dweights || layer->dbiases){
        perror("Paremeters: allocation failed.");
        exit(1);
    }

    for(int i = 0; i < in_dim * out_dim; i++){
        layer->weights[i] = ((float)rand() / RAND_MAX - 0.5f) * 0.01f;
        layer->dweights[i] = 0.0f;
    }

    for(int i = 0; i < out_dim; i++){
        layer->biases[i] = 0.0f;
        layer->dbiases[i] = 0.0f;
    }

    return layer;

}
#ifndef DENSE_H
#define DENSE_H

typedef struct DenseLayer DenseLayer;

DenseLayer* init_layer(int in_dim, int out_dim);
void free_layer(DenseLayer* l);
void forward(DenseLayer* l, const float* input);
void backward(DenseLayer* l, const float* input, const float* grad_out);
void update(DenseLayer* l, float lr);

#endif
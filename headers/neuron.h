#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#pragma once

uint16_t dot_product(const bool* a, const bool* b, const size_t length);

typedef enum activation_t {
    RELU,
    SIGMOID,
    TANH
} activation_t;

typedef struct neuron_t {
    bool* weights_bool;
    float* weight_float;
    activation_t activation;
    size_t n_weights;
} neuron_t;

typedef struct layer_t {
    neuron_t* neurons;
    size_t n_neurons;
} layer_t;

typedef struct bnn_t {
    layer_t* layers;
    size_t n_layers;
    bool initialized;
} bnn_t;

typedef struct bnn_train_config_t {
    size_t epochs;
    bool verbose;
} bnn_train_config_t;


typedef struct bnn_data_t {
    bool* data;
    bool* labels; 
    size_t n_samples;
    size_t n_features;
} bnn_data_t;
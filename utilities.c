#include "stdio.h"
#include <tgmath.h>
#include <assert.h>
#include "myFunctions.h"

double computeEntropy(size_t length, uint8_t byteArray[]) {
    size_t symbol[sizeof(uint8_t)] = {0};
    double result = 0.0;

    for (size_t i = 0; i < length; i++) {
        symbol[byteArray[i]]++;
    }

    for (size_t i = 0; i < sizeof(uint8_t); i++) {
        if (symbol[i] == 0) {
            continue;
        }
        double prob = 1.0 * symbol[i] / length;
        result += prob * log2(prob);
    }
    return -result;
}

int64_t reductorRed(color col) {
    return col.red;
}

int64_t reductorGreen(color col) {
    return col.green;
}

int64_t reductorBlue(color col) {
    return col.blue;
}

int64_t reductorTotal(color col) {
    int64_t result = (col.red <<16) + (col.green <<8) + (col.blue);
    return result;
}

uint8_t mod256(int64_t number) {
    int64_t temp = number % 256;
    if (temp < 0) {
        temp = 256 - temp;
    }
    return (uint8_t) (temp);
}

double runPredictionForReductor(color* colorMatrix, 
                                        size_t width, 
                                        size_t heigth,
                                        int64_t (*predictor)(int64_t, int64_t, int64_t), 
                                        int64_t (*reductor)(color)) {
    
    uint8_t byteArray[width * heigth];
    color black = {0, 0, 0};

    byteArray[0] = mod256(reductor(colorMatrix[0 * width + 0]));
    //Computing predictor values for the first row;
    for (size_t j = 1; j < width; j++) {
        byteArray[0 * width + j] = mod256(reductor(colorMatrix[0 * width + j]) - predictor(reductor(colorMatrix[0 * width + j - 1]), reductor(black), reductor(black)));
    }
    //Computing predictor valeus for the following rows;
    for (size_t i = 1; i < heigth; i++) {
        printf("i=%zu\n",i);
        byteArray[i * width + 0] = mod256(reductor(colorMatrix[i * width + 0]) - predictor(reductor(black), reductor(colorMatrix[(i - 1) * width + 0]), reductor(black)));
        for (size_t j = 1; j < width; j++) {
            assert(i * width + j < width * heigth);
            byteArray[i * width + j] = mod256(reductor(colorMatrix[i * width + j]) - predictor(reductor(colorMatrix[i * width + j - 1]), 
                                                reductor(colorMatrix[(i - 1) * width + 0]), 
                                                reductor(colorMatrix[(i - 1) * width + j - 1])));
        }
    }

    /*
    //replacing values with mod256 (for maximum optimization this can be done in the previous loop. Here separeted for the sake of clarity);
    for (size_t i = 0; i < width * heigth; i++) {
        byteArray[i] = 0;// mod256(byteArray[i]);
    }*/

    return computeEntropy(width * heigth, byteArray);
}

predictorResults runPrediction(color* byteMatrix, size_t width, size_t heigth, int64_t (*predictor)(int64_t, int64_t, int64_t)) {
    predictorResults results = {0,0,0,0};

    results.red = runPredictionForReductor(byteMatrix, width, heigth, predictor, reductorRed);
    results.green = runPredictionForReductor(byteMatrix, width, heigth, predictor, reductorGreen);
    results.blue = runPredictionForReductor(byteMatrix, width, heigth, predictor, reductorBlue);
    results.total = runPredictionForReductor(byteMatrix, width, heigth, predictor, reductorTotal);

    return results;
}

#include "stdio.h"
#include <tgmath.h>
#include <assert.h>
#include "myFunctions.h"

#define byteWidth 256
double computeEntropy(size_t length, const uint8_t byteArray[static length]) {
    
    size_t symbol[byteWidth] = {0};
    double result = 0.0;

    for (size_t i = 0; i < length; i++) {
        symbol[byteArray[i]]++;
    }

    for (size_t i = 0; i < byteWidth; i++) {
        if (symbol[i] == 0) {
            continue;
        }
        double prob = 1.0 * symbol[i] / length;
        result += prob * log2(prob);
    }
    return -result;
}
#undef byteWidth

/**
 * @brief Reduction functions that map color to red value;
 * 
 * @param col color
 * @return int64_t red value
 */
static int64_t reductorRed(color col) {
    return col.red;
}

/**
 * @brief Reduction functions that map color to green value;
 * 
 * @param col color
 * @return int64_t green value
 */
static int64_t reductorGreen(color col) {
    return col.green;
}

/**
 * @brief Reduction functions that map color to blue value;
 * 
 * @param col color
 * @return int64_t blue value
 */
static int64_t reductorBlue(color col) {
    return col.blue;
}

/**
 * @brief Reduction functions that map color to pixel value;
 * 
 * @param col color
 * @return int64_t pixel value
 */
static int64_t reductorTotal(color col) {
    int64_t result = (col.red <<16) + (col.green <<8) + (col.blue);
    return result;
}

static uint8_t mod256(int64_t number) {
    int64_t temp = number % 256;
    if (temp < 0) {
        temp = 256 - temp;
    }
    return (uint8_t) (temp);
}
/**
 * @brief Computes entropy for given predictor and reductor @see reductorRed.
 * Used for computing entropy for on single position
 * 
 * @param colorMatrix matrix of pixels (colors)
 * @param width matrix width
 * @param height matrix height
 * @param predictor predictor used for computing entropy
 * @param reductor reductor used for casting our color into int. 
 * using different predictors, one can compute entropy for different primary colors. 
 * @return double computed entropy
 */
static double runPredictionForReductor(const color* const colorMatrix, 
                                        size_t width, 
                                        size_t height,
                                        int64_t (*predictor)(int64_t, int64_t, int64_t), 
                                        int64_t (*reductor)(color)) {
    
    uint8_t byteArray[width * height];
    color black = {0, 0, 0};

    byteArray[0] = mod256(reductor(colorMatrix[0 * width + 0]));
    //Computing predictor values for the first row;
    for (size_t j = 1; j < width; j++) {
        byteArray[0 * width + j] = mod256(reductor(colorMatrix[0 * width + j]) - predictor(reductor(colorMatrix[0 * width + j - 1]), reductor(black), reductor(black)));
    }
    //Computing predictor valeus for the following rows;
    for (size_t i = 1; i < height; i++) {
        byteArray[i * width + 0] = mod256(reductor(colorMatrix[i * width + 0]) - predictor(reductor(black), reductor(colorMatrix[(i - 1) * width + 0]), reductor(black)));
        for (size_t j = 1; j < width; j++) {
            byteArray[i * width + j] = mod256(reductor(colorMatrix[i * width + j]) - predictor(reductor(colorMatrix[i * width + j - 1]), 
                                                reductor(colorMatrix[(i - 1) * width + 0]), 
                                                reductor(colorMatrix[(i - 1) * width + j - 1])));
        }
    }

    return computeEntropy(width * height, byteArray);
}

entropyValues runPrediction(const color* const pixelMatrix, size_t width, size_t height, int64_t (*predictor)(int64_t, int64_t, int64_t)) {
    entropyValues results = {0,0,0,0};

    results.red = runPredictionForReductor(pixelMatrix, width, height, predictor, reductorRed);
    results.green = runPredictionForReductor(pixelMatrix, width, height, predictor, reductorGreen);
    results.blue = runPredictionForReductor(pixelMatrix, width, height, predictor, reductorBlue);
    results.total = runPredictionForReductor(pixelMatrix, width, height, predictor, reductorTotal);

    return results;
}

/**
 * @brief Used for computing entropy for given primary color or pixel
 * 
 * @param pixelMatrix matrix of pixels
 * @param width width
 * @param height height
 * @param reductor reductor functino for casting color to int @see runPredictionForReductor
 * @return double 
 */
static double computeInputEntropyForReductor(const color* const pixelMatrix, size_t width, size_t height, int64_t (*reductor)(color col)) {
    uint8_t byteArray[width * height];
    for (size_t i = 0; i < width * height; i++) {
        byteArray[i] = mod256(reductor(pixelMatrix[i]));
    }
    return computeEntropy(width * height, byteArray);
}

entropyValues computeInputEntropy(const color* const pixelMatrix, size_t width, size_t height) {
    entropyValues results = {
        .red = computeInputEntropyForReductor(pixelMatrix, width, height, reductorRed), 
        .green = computeInputEntropyForReductor(pixelMatrix, width, height, reductorGreen),
        .blue = computeInputEntropyForReductor(pixelMatrix, width, height, reductorBlue),
        .total = computeInputEntropyForReductor(pixelMatrix, width, height, reductorTotal)
    };
    return results;
}

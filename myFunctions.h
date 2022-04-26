#pragma once
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Structure for our RGB int64_t
 * 
 */
typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} color;

typedef struct {
    double red;
    double green;
    double blue;
    double total;
} entropyValues;

double computeEntropy(size_t length, const uint8_t byteArray[static length]);

/**
 * @brief Compute entropy for primary colors and pixesl for given pixelMatrix and predictor
 * 
 * @param pixelMatrix image pixels
 * @param width image width
 * @param height image height
 * @param predictor used predictor
 * @return entropyValues results for respective entropies
 */
entropyValues runPrediction(const color* pixelMatrix, size_t width, size_t height, int64_t (*predictor)(int64_t, int64_t, int64_t));

/**
 * @brief compute initial entropy of an image
 * 
 * @param pixelMatrix matrix of pixels
 * @param width matrix width
 * @param height matrix height
 * @return entropyValues computed values for respective entropies
 */
entropyValues computeInputEntropy(const color* pixelMatrix, size_t width, size_t height);

/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t W
 */
int64_t predictor1(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t N
 */
int64_t predictor2(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t NW
 */
int64_t predictor3(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t N + W - NW
 */
int64_t predictor4(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t N + (N - NW) / 2
 */
int64_t predictor5(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t W + (N - NW) / 2
 */
int64_t predictor6(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t (N + W) / 2
 */
int64_t predictor7(int64_t W, int64_t N, int64_t NW);
/**
 * @brief predictor
 * 
 * @param W left pixel
 * @param N upper pixel
 * @param NW upper-left pixel
 * @return int64_t if NW > max(W, N) then Xb ← max(W, N)
                    else if NW 6 min(W, N) then Xb ← min(W, N)
                    else Xb ← W + N − NW
 */
int64_t predictor8(int64_t W, int64_t N, int64_t NW);



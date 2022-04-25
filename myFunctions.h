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
} predictorResults;

double computeEntropy(size_t length, uint8_t byteArray[static length]);

predictorResults runPrediction(color* byteMatrix, size_t width, size_t heigth, int64_t (*predictor)(int64_t, int64_t, int64_t));

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



#include "myFunctions.h"
#include <tgmath.h>

int64_t predictor1(int64_t W, int64_t N, int64_t NW) {
    return W;
}

int64_t predictor2(int64_t W, int64_t N, int64_t NW) {
    return N;
}

int64_t predictor3(int64_t W, int64_t N, int64_t NW) {
    return NW;
}

int64_t predictor4(int64_t W, int64_t N, int64_t NW) {
    return N + W - NW;
}

int64_t predictor5(int64_t W, int64_t N, int64_t NW) {
    return  N + (W - NW) / 2;
}

int64_t predictor6(int64_t W, int64_t N, int64_t NW) {
    return  W + (N - NW) / 2;
}

int64_t predictor7(int64_t W, int64_t N, int64_t NW) {
    return  (N + W) / 2;
}

int64_t predictor8(int64_t W, int64_t N, int64_t NW) {
    if (NW >= fmax(W, N)) {
        return fmax(W, N);
    }
    else if (NW <= fmin(W, N)) {
        return fmin(W, N);
    }
    else {
        return W + N - NW;
    }
}

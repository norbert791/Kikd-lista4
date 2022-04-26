#include <tga.h>
#include "myFunctions.h"

/**
 * @brief Used for updating best solution
 * 
 */
#define compareAsign(A, B, C, D) if ((A) < (B)) {B = A; D = C;}

int main(int argc, char** argv) {

    TGA *tga;
    TGAData data;
    size_t width = 0;
    size_t height = 0;
    
    if(argc < 2) {
        perror("Another parameter requierd: pls input filename as programm parameter\n");
        return EXIT_FAILURE;
    }

    //Otwieramy plik tga
    tga = TGAOpen(argv[1], "r");
    if (!tga || tga->last != TGA_OK) {
        perror("opening error\n");
        return EXIT_FAILURE;
    }
    
    //Wczytujemy dane
    data.flags = TGA_IMAGE_DATA | TGA_IMAGE_ID | TGA_RGB;
	if(TGAReadImage(tga, & data) != TGA_OK) {
	    perror("parsing error\n");
        return EXIT_FAILURE;
	}
    
    width = tga->hdr.width;
    height = tga->hdr.height;
    
    if (tga->hdr.depth != 24 && tga->hdr.map_t != 0 && tga->hdr.alpha > 0) {
        perror("The image does not meets requierd conditions:\n"
                "- there must not be a color map\n"
                "- alpha must be 0 bytes long\n"
                "- depth must be 24 bits (8 per color)\n");
                return EXIT_FAILURE;
    }
    
    TGAClose(tga);

    color array[width * height];

    for (size_t i = 0; i < width * height; i += 3) {
        array[i].red = (uint8_t) data.img_data[i];
        array[i].green = (uint8_t) data.img_data[i + 1];
        array[i].blue = (uint8_t) data.img_data[i + 2];
    }

    int64_t (*funs[8])(int64_t, int64_t, int64_t) = {predictor1, predictor2, predictor3, predictor4, predictor5, predictor6, predictor7, predictor8};

    size_t bestR = 1, bestG = 1, bestB = 1, bestT = 1;

    entropyValues temp = computeInputEntropy(array, width, height);

    printf("Initial entropies:\n"
            "for red: %lf\n"
            "for green %lf\n"
            "for blue %lf\n"
            "for pixel %lf\n\n", temp.red, temp.green, temp.blue, temp.total);

    entropyValues best = runPrediction(array, width, height, funs[0]);
    
    printf("Predictor no %zu results:\n"
        "Pixel entropy: %lf\n"
        "Red entropy %lf\n"
        "Green entropy %lf\n"
        "Blue entropy %lf\n\n", (size_t)1, best.total, best.red, best.green, best.blue);

    for (size_t i = 1; i < 8; i++) {
        temp = runPrediction(array, width, height, funs[i]);
        printf("Predictor no %zu results:\n"
                "Pixel entropy: %lf\n"
                "Red entropy %lf\n"
                "Green entropy %lf\n"
                "Blue entropy %lf\n\n", i + 1, temp.total, temp.red, temp.green, temp.blue);
        compareAsign(temp.red, best.red, i + 1, bestR);
        compareAsign(temp.green, best.green, i + 1, bestG);
        compareAsign(temp.blue, best.blue, i + 1, bestB);
        compareAsign(temp.total, best.total, i + 1, bestT);
    }

    printf("Best predictor:\n"
            "for pixel: %zu\n"
            "for red: %zu\n"
           "for green: %zu\n"
            "for blue: %zu\n", bestT, bestR, bestG, bestB);
}

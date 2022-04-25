#include <tga.h>
#include "myFunctions.h"

int main() {

    TGA *tga;
    TGAData data;
    size_t width = 0;
    size_t height = 0;
    size_t depth = 0;
    size_t colorType = 0;
    

    //Otwieramy plik tga
    tga = TGAOpen("testy4/example0.tga", "r");
    if (!tga || tga->last != TGA_OK) {
        perror("opening error\n");
        return 1;
    }
    
    //Wczytujemy dane
    data.flags = TGA_IMAGE_DATA | TGA_IMAGE_ID | TGA_RGB;
	if(TGAReadImage(tga, & data) != TGA_OK) {
	    perror("parsing error\n");
        return 1;
	}
    
    depth = tga->hdr.depth;
    width = tga->hdr.width;
    height = tga->hdr.height;
    colorType = tga->hdr.img_t;
    
    printf("Liczba bitow na kolor wynosi: %zu\n"
            "Dlugosc wynosi: %zu\n"
            "Wysokosc wynosi: %zu\n"
            "Typ obrazu to: %zu\n", depth, width, height, colorType);
    //Zamykamy plik tga
    TGAClose(tga);

    color* array = malloc(sizeof(*array) * width * height);

    for (size_t i = 0; i < width * height; i += 3) {
        array[i].red = (uint8_t) data.img_data[i];
        array[i].green = (uint8_t) data.img_data[i + 1];
        array[i].blue = (uint8_t) data.img_data[i + 2];
    }
    /*
    for (size_t i = 0; i < height; i++) {
        for(size_t j = 0; j < width; j++) {
            printf("(R,G,B)=(%c, %c, %c)", array[i * width + j].red, array[i * width + j].green, array[i * width + j].blue);
        }
    }*/

    predictorResults result = runPrediction(array, width, height, predictor1);
    printf("Wynik to: %lf\n", result.total);
}

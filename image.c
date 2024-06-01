#include <stdio.h>
#include <stdlib.h>
#include "image.h"

ImageGray *create_image_gray(){
    FILE *input_image_example_gray = fopen("C:\\Users\\jffil\\OneDrive\\Documentos\\ED1\\Trabalho_2_avaliacao\\trabalhoED1\\imagem_convertida_gray.txt", "r");

    if (input_image_example_gray == NULL){
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    ImageGray *img_gray = (ImageGray*)malloc(sizeof(ImageGray));
    if (img_gray == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        fclose(input_image_example_gray);
        return NULL;
    }

    fscanf(input_image_example_gray, "%d", &img_gray->dim.altura);
    fscanf(input_image_example_gray, "%d", &img_gray->dim.largura);

    img_gray->pixels = (PixelGray*)malloc((img_gray->dim.altura * img_gray->dim.largura) * sizeof(PixelGray));
    if (img_gray->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        fclose(input_image_example_gray);
        free(img_gray);
        return NULL;
    }

    for (int i = 0; i < img_gray->dim.altura; i++){
        for (int j = 0; j < img_gray->dim.largura; j++){
            fscanf(input_image_example_gray ,"%d,", &img_gray->pixels[i * img_gray->dim.largura + j].value);
        }
    }

    fclose(input_image_example_gray);
    return img_gray;
}

void print_image_gray(ImageGray *img_gray){
    int pix1,pix2,pix3;
    for (int i = 0; i < img_gray->dim.altura; i++){
        for (int j = 0; j < img_gray->dim.largura; j++){
            pix1 = img_gray->pixels[i*img_gray->dim.largura+j].value;
            pix2 = img_gray->pixels[i*img_gray->dim.largura+j].value;
            pix3 = img_gray->pixels[i*img_gray->dim.largura+j].value;
            printf("\033[38;2;%d;%d;%dm**\033[0m", pix1, pix2, pix3);
        }
        printf("\n");
    }
}

ImageRGB *create_image_rgb(){
    FILE *input_image_example_RGB = fopen("C:\\Users\\jffil\\OneDrive\\Documentos\\ED1\\Trabalho_2_avaliacao\\trabalhoED1\\imagem_convertida_rgb.txt", "r");

    if (input_image_example_RGB == NULL){
        perror("Erro ao abrir o arquivo");
        return NULL;
    }
    
    ImageRGB *img_rgb = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_rgb == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        fclose(input_image_example_RGB);
        return NULL;
    }

    fscanf(input_image_example_RGB, "%d", &img_rgb->dim.altura);
    fscanf(input_image_example_RGB, "%d", &img_rgb->dim.largura);

    img_rgb->pixels = (PixelRGB*)malloc((img_rgb->dim.altura * img_rgb->dim.largura) * sizeof(PixelRGB));
    if (img_rgb->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        fclose(input_image_example_RGB);
        free(img_rgb);
        return NULL;
    }
    for (int i = 0; i < img_rgb->dim.altura; i++){
        for (int j = 0; j < img_rgb->dim.largura; j++) {
            fscanf(input_image_example_RGB, "%d %d %d,", &img_rgb->pixels[i * img_rgb->dim.largura + j].red, &img_rgb->pixels[i * img_rgb->dim.largura + j].green, &img_rgb->pixels[i * img_rgb->dim.largura + j].blue);
        }
    }

    fclose(input_image_example_RGB);
    return img_rgb;
}

void printImagemRGB(ImageRGB *img_rgb){
    int r,g,b;
    for (int i = 0; i < img_rgb->dim.altura; i++){
        for (int j = 0; j < img_rgb->dim.largura; j++){
            r = img_rgb->pixels[i*img_rgb->dim.largura+j].red;
            g = img_rgb->pixels[i*img_rgb->dim.largura+j].green;
            b = img_rgb->pixels[i*img_rgb->dim.largura+j].blue;
            printf("\033[38;2;%d;%d;%dm**\033[0m", r, g, b);
        }
        printf("\n");
    }
}

ImageGray *flip_vertical_gray(ImageGray *img_gray){
    ImageGray *img_gray_vertical_flip = (ImageGray*)malloc(sizeof(ImageGray));
    if (img_gray_vertical_flip == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_gray_vertical_flip->dim.altura = img_gray->dim.altura;
    img_gray_vertical_flip->dim.largura = img_gray->dim.largura;

    img_gray_vertical_flip->pixels = (PixelGray*)malloc((img_gray->dim.altura * img_gray->dim.largura) * sizeof(PixelGray));
    if (img_gray_vertical_flip->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_gray_vertical_flip);
        return NULL;
    }

    for (int i = 0; i < img_gray->dim.altura; i++){
        for (int j = 0; j < img_gray->dim.largura; j++){
            img_gray_vertical_flip->pixels[i * img_gray->dim.largura + j].value = img_gray->pixels[(img_gray->dim.altura - i - 1) * img_gray->dim.largura + j].value;
        }
    }
    free(img_gray->pixels);
    free(img_gray);
    return img_gray_vertical_flip;
}

ImageGray *flip_horizontal_gray(ImageGray *img_gray) {
    ImageGray *img_gray_horizontal_flip = (ImageGray*)malloc(sizeof(ImageGray));
    if (img_gray_horizontal_flip == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_gray_horizontal_flip->dim.altura = img_gray->dim.altura;
    img_gray_horizontal_flip->dim.largura = img_gray->dim.largura;

    img_gray_horizontal_flip->pixels = (PixelGray*)malloc((img_gray_horizontal_flip->dim.altura * img_gray_horizontal_flip->dim.largura) * sizeof(PixelGray));
    if (img_gray_horizontal_flip->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_gray_horizontal_flip);
        return NULL;
    }

    for (int i = 0; i < img_gray_horizontal_flip->dim.altura; i++) {
        for (int j = 0; j < img_gray_horizontal_flip->dim.largura; j++) {
            img_gray_horizontal_flip->pixels[i * img_gray_horizontal_flip->dim.largura + j].value = img_gray->pixels[i * img_gray->dim.largura + (img_gray->dim.largura - j - 1)].value;
        }
    }
    free(img_gray->pixels);
    free(img_gray);

    return img_gray_horizontal_flip;
}
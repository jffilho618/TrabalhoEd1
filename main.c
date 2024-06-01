#include <stdio.h>
#include <stdlib.h>
#include "image.h"

// Função para copiar uma imagem RGB
ImageRGB* copy_image_rgb(ImageRGB* img) {
    ImageRGB* img_copy = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_copy == NULL) {
        printf("Erro ao alocar memória para a cópia da imagem RGB.\n");
        return NULL;
    }
    img_copy->dim.altura = img->dim.altura;
    img_copy->dim.largura = img->dim.largura;
    img_copy->pixels = (PixelRGB*)malloc(img_copy->dim.altura * img_copy->dim.largura * sizeof(PixelRGB));
    if (img_copy->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da cópia da imagem RGB.\n");
        free(img_copy);
        return NULL;
    }
    for (int i = 0; i < img_copy->dim.altura * img_copy->dim.largura; i++) {
        img_copy->pixels[i] = img->pixels[i];
    }
    return img_copy;
}

// Função para copiar uma imagem Gray
ImageGray* copy_image_gray(ImageGray* img) {
    ImageGray* img_copy = (ImageGray*)malloc(sizeof(ImageGray));
    if (img_copy == NULL) {
        printf("Erro ao alocar memória para a cópia da imagem Gray.\n");
        return NULL;
    }
    img_copy->dim.altura = img->dim.altura;
    img_copy->dim.largura = img->dim.largura;
    img_copy->pixels = (PixelGray*)malloc(img_copy->dim.altura * img_copy->dim.largura * sizeof(PixelGray));
    if (img_copy->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da cópia da imagem Gray.\n");
        free(img_copy);
        return NULL;
    }
    for (int i = 0; i < img_copy->dim.altura * img_copy->dim.largura; i++) {
        img_copy->pixels[i] = img->pixels[i];
    }
    return img_copy;
}

int main() {
    int op, op2, op3;
    ImageRGB* img_rgb = create_image_rgb();
    ImageGray* img_gray = create_image_gray();
    
    if (img_rgb == NULL || img_gray == NULL) {
        // Verifica se as imagens foram carregadas corretamente
        return 1;
    }
    
    do {
        printf("[1] Manipular imagem RGB\n");
        printf("[2] Manipular imagem Gray\n");
        printf("[0] Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        
        switch (op) {
            case 1: {
                ImageRGB *img_rgb_copia = copy_image_rgb(img_rgb);
                if (img_rgb_copia == NULL) break;
                print_image_rgb(img_rgb);
                do {
                    printf("[1] Vertical Flip\n");
                    printf("[2] Horizontal Flip\n");
                    printf("[0] Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &op2);
                    
                    switch (op2) {
                        case 1: {
                            img_rgb_copia = flip_vertical_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            break;
                        }
                        case 2: {
                            img_rgb_copia = flip_horizontal_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            break;
                        }
                    }
                } while (op2 != 0);
                free(img_rgb_copia->pixels);
                free(img_rgb_copia);
                break;
            }
                
            case 2: {
                ImageGray *img_gray_copia = copy_image_gray(img_gray);
                if (img_gray_copia == NULL) break;
                print_image_gray(img_gray_copia);
                do {
                    printf("[1] Vertical Flip\n");
                    printf("[2] Horizontal Flip\n");
                    printf("[0] Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &op3);
                    
                    switch (op3) {
                        case 1: {
                            img_gray_copia = flip_vertical_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            break;
                        }
                        case 2: {
                            img_gray_copia = flip_horizontal_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            break;
                        }
                    }
                } while (op3 != 0);
                free(img_gray_copia->pixels);
                free(img_gray_copia);
                break;
            }
        }
    } while (op != 0);

    free(img_rgb->pixels);
    free(img_rgb);
    free(img_gray->pixels);
    free(img_gray);

    return 0;
}

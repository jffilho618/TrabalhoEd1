#include <stdio.h>
#include <stdlib.h>
#include "image.h"

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
                    printf("[3] Transpose\n");
                    printf("[4] Clahe\n");
                    printf("[5] Median Blur\n");
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
                        case 3: {
                            img_rgb_copia = transpose_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            break;
                        }
                        case 5: {
                            img_rgb_copia = median_blur_rgb(img_rgb_copia);
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
                    printf("[3] Transpose\n");
                    printf("[4] Clahe\n");
                    printf("[5] Median Blur\n");
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
                        case 3: {
                            img_gray_copia = transpose_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            break;
                        }
                        case 4: {
                            img_gray_copia = clahe_gray(img_gray_copia);
                            print_image_gray(img_gray_copia); 
                            break;
                        }
                        case 5: {
                            img_gray_copia = median_blur_gray(img_gray_copia);
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

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
                No_duplo_rgb *hist = criar_lista_dupla_rgb();
                ImageRGB *aux0 = copy_image_rgb(img_rgb_copia);
                hist = Add_inicio_duplo_rgb(hist, aux0);
                //print_image_rgb(img_rgb);
                do {
                    printf("[1] Vertical Flip\n");
                    printf("[2] Horizontal Flip\n");
                    printf("[3] Transpose\n");
                    printf("[4] Clahe\n");
                    printf("[5] Median Blur\n");
                    printf("[6] Sepia\n");
                    printf("[7] Mosaico Pixel\n");
                    printf("[8] Historico de Alteracoes\n");
                    printf("[9] Operacoes randomicas\n");
                    printf("[0] Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &op2);
                    
                    switch (op2) {
                        case 1: {
                            img_rgb_copia = flip_vertical_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux1 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux1);
                            break;
                        }
                        case 2: {
                            img_rgb_copia = flip_horizontal_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux2 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux2);
                            break;
                        }
                        case 3: {
                            img_rgb_copia = transpose_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux3 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux3);
                            break;
                        }
                        case 4:{ 
                            img_rgb_copia = clahe_RGB(img_rgb_copia); 
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux4 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux4); 
                            break; 
                        }
                        case 5: {
                            img_rgb_copia = median_blur_rgb(img_rgb_copia);
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux5 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux5);
                            break;
                        }
                        case 6:{
                            img_rgb_copia = Filtro_Sepia(img_rgb_copia); 
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux6 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux6); 
                            break;
                        }
                        case 7:{
                            img_rgb_copia = FiltroMosaico_RGB(img_rgb_copia); 
                            print_image_rgb(img_rgb_copia);
                            ImageRGB *aux7 = copy_image_rgb(img_rgb_copia);
                            hist = Add_inicio_duplo_rgb(hist, aux7);
                            break; 
                        }
                        case 8:{
                            manipular_historico_rgb(hist);
                            break;
                        }
                        case 9:{
                            ImageRGB *aux8 = copy_image_rgb(img_rgb);
                            operacoes_randomicas_rgb(aux8);
                            break;
                        }
                    }
                } while (op2 != 0);
                free(img_rgb_copia->pixels);
                free(img_rgb_copia);
                free_hist_rgb(hist);
                break;
            }
                
            case 2: {
                ImageGray *img_gray_copia = copy_image_gray(img_gray);
                No_duplo_gray *hist = criar_lista_dupla_gray();
                if (img_gray_copia == NULL) break;
                //print_image_gray(img_gray_copia);
                ImageGray *aux0 = copy_image_gray(img_gray_copia);
                hist = Add_inicio_duplo_gray(hist, aux0);
                do {
                    printf("[1] Vertical Flip\n");
                    printf("[2] Horizontal Flip\n");
                    printf("[3] Transpose\n");
                    printf("[4] Clahe\n");
                    printf("[5] Median Blur\n");
                    printf("[6] Mosaico Pixel\n");
                    printf("[7] Historico de Alteracoes\n");
                    printf("[8] Operacoes randomicas\n");
                    printf("[0] Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &op3);
                    
                    switch (op3) {
                        case 1: {
                            img_gray_copia = flip_vertical_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            ImageGray *aux1 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux1);
                            break;
                        }
                        case 2: {
                            img_gray_copia = flip_horizontal_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            ImageGray *aux2 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux2);
                            break;
                        }
                        case 3: {
                            img_gray_copia = transpose_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            ImageGray *aux3 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux3);
                            break;
                        }
                        case 4: {
                            img_gray_copia = clahe_gray(img_gray_copia);
                            print_image_gray(img_gray_copia); 
                            ImageGray *aux4 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux4);
                            break;
                        }
                        case 5: {
                            img_gray_copia = median_blur_gray(img_gray_copia);
                            print_image_gray(img_gray_copia);
                            ImageGray *aux4 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux4);
                            break;
                        }
                        case 6:{
                            img_gray_copia = FiltroMosaico_Gray(img_gray_copia); 
                            print_image_gray(img_gray_copia);
                            ImageGray *aux5 = copy_image_gray(img_gray_copia);
                            hist = Add_inicio_duplo_gray(hist, aux5);
                            break; 
                        }
                        case 7:{
                            manipular_historico_gray(hist);
                            break;
                        }
                        case 8:{
                            ImageGray *aux6 = copy_image_gray(img_gray);
                            operacoes_randomicas_gray(aux6);
                            break;
                        }
                    }
                } while (op3 != 0);
                free(img_gray_copia->pixels);
                free(img_gray_copia);
                free_hist_gray(hist);
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

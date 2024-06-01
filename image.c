#include <stdio.h>
#include <stdlib.h>
#include "image.h"

ImageGray *create_image_gray(){
    FILE *input_image_example_gray = fopen("C:\\Users\\jffil\\OneDrive\\Documentos\\ED1\\Trabalho_2_avaliacao\\TrabalhoEd1\\imagem_convertida_gray.txt", "r");

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
    FILE *input_image_example_RGB = fopen("C:\\Users\\jffil\\OneDrive\\Documentos\\ED1\\Trabalho_2_avaliacao\\TrabalhoEd1\\imagem_convertida_rgb.txt", "r");

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

void print_image_rgb(ImageRGB *img_rgb){
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

ImageRGB *flip_vertical_rgb(ImageRGB *img_rgb){
    ImageRGB *img_rgb_vertical_flip = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_rgb_vertical_flip == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_rgb_vertical_flip->dim.altura = img_rgb->dim.altura;
    img_rgb_vertical_flip->dim.largura = img_rgb->dim.largura;

    img_rgb_vertical_flip->pixels = (PixelRGB*)malloc((img_rgb->dim.altura * img_rgb->dim.largura) * sizeof(PixelRGB));
    if (img_rgb_vertical_flip->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_rgb_vertical_flip);
        return NULL;
    }

    for (int i = 0; i < img_rgb->dim.altura; i++){
        for (int j = 0; j < img_rgb->dim.largura; j++){
            img_rgb_vertical_flip->pixels[i * img_rgb->dim.largura + j].red = img_rgb->pixels[(img_rgb->dim.altura - i - 1) * img_rgb->dim.largura + j].red;
            img_rgb_vertical_flip->pixels[i * img_rgb->dim.largura + j].green = img_rgb->pixels[(img_rgb->dim.altura - i - 1) * img_rgb->dim.largura + j].green;
            img_rgb_vertical_flip->pixels[i * img_rgb->dim.largura + j].blue = img_rgb->pixels[(img_rgb->dim.altura - i - 1) * img_rgb->dim.largura + j].blue;
        }
    }
    free(img_rgb->pixels);
    free(img_rgb);
    return img_rgb_vertical_flip;
}

ImageRGB *flip_horizontal_rgb(ImageRGB *img_rgb){
    ImageRGB *img_rgb_horizontal_flip = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_rgb_horizontal_flip == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_rgb_horizontal_flip->dim.altura = img_rgb->dim.altura;
    img_rgb_horizontal_flip->dim.largura = img_rgb->dim.largura;

    img_rgb_horizontal_flip->pixels = (PixelRGB*)malloc((img_rgb->dim.altura * img_rgb->dim.largura) * sizeof(PixelRGB));
    if (img_rgb_horizontal_flip->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_rgb_horizontal_flip);
        return NULL;
    }

    for (int i = 0; i < img_rgb->dim.altura; i++){
        for (int j = 0; j < img_rgb->dim.largura; j++){
            img_rgb_horizontal_flip->pixels[i * img_rgb->dim.largura + j].red = img_rgb->pixels[i * img_rgb->dim.largura + (img_rgb->dim.largura - j - 1)].red;
            img_rgb_horizontal_flip->pixels[i * img_rgb->dim.largura + j].green = img_rgb->pixels[i * img_rgb->dim.largura + (img_rgb->dim.largura - j - 1)].green;
            img_rgb_horizontal_flip->pixels[i * img_rgb->dim.largura + j].blue = img_rgb->pixels[i * img_rgb->dim.largura + (img_rgb->dim.largura - j - 1)].blue;
        }
    }
    free(img_rgb->pixels);
    free(img_rgb);
    return img_rgb_horizontal_flip;
}

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

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivô
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void OrdenaVetor(int *tempvetor, int cont) {
    quickSort(tempvetor, 0, cont - 1);
}


int Mediana(int *temp_vetor, int cont) {
   
   OrdenaVetor(temp_vetor, cont);

   int meio = cont / 2;

   if (cont % 2 == 0) {
      return (temp_vetor[meio - 1] + temp_vetor[meio]) / 2;
   } else {
      return temp_vetor[meio];
   }
}

int pixelmediana_Gray(ImageGray *img_gray, int posicao_atual) {
    int *temp_vetor, cont, mediana;
    
    // Determina o tamanho do vetor temporário
    int max_vizinhos = 225; // 15x15

    temp_vetor = malloc(max_vizinhos * sizeof(int));
    if (temp_vetor == NULL) {
        printf("Falha na alocacao");
        exit(1);
    }

    cont = 0;
    
    // Varre a área 15x15 ao redor do pixel atual
    for (int i = -7; i <= 7; i++) {
        for (int j = -7; j <= 7; j++) {
            int nx = (posicao_atual % 500) + j;
            int ny = (posicao_atual / 500) + i;
            if (nx >= 0 && nx < 500 && ny >= 0 && ny < 500) {
                int posicao_vizinho = ny * 500 + nx;
                temp_vetor[cont++] = img_gray->pixels[posicao_vizinho].value;
            }
        }
    }

    mediana = Mediana(temp_vetor, cont);
    free(temp_vetor);

    return mediana;
}

int pixelmediana_RGB(ImageRGB *img_rgb, int posicao_atual, int n) {
    int *temp_vetor, cont, mediana;
    
    // Determina o tamanho do vetor temporário
    int max_vizinhos = 225; // 15x15

    temp_vetor = malloc(max_vizinhos * sizeof(int));
    if (temp_vetor == NULL) {
        printf("Falha na alocacao");
        exit(1);
    }

    cont = 0;
    
    // Varre a área 15x15 ao redor do pixel atual
    for (int i = -7; i <= 7; i++) {
        for (int j = -7; j <= 7; j++) {
            int nx = (posicao_atual % 500) + j;
            int ny = (posicao_atual / 500) + i;
            if (nx >= 0 && nx < 500 && ny >= 0 && ny < 500) {
                int posicao_vizinho = ny * 500 + nx;
                if(n == 1){
                   temp_vetor[cont++] = img_rgb->pixels[posicao_vizinho].blue; 
                }
                if(n == 2){
                   temp_vetor[cont++] = img_rgb->pixels[posicao_vizinho].green; 
                }
                if(n == 3){
                   temp_vetor[cont++] = img_rgb->pixels[posicao_vizinho].red; 
                }
            }
        }
    }

    mediana = Mediana(temp_vetor, cont);
    free(temp_vetor);

    return mediana;
}


ImageGray *median_blur_gray(ImageGray *img_gray){ 
    ImageGray *img_gray_medium_blur = (ImageGray*)malloc(sizeof(ImageGray)); 
    int posicao_atual; 
    if(img_gray_medium_blur == NULL){
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_gray_medium_blur->dim.altura = img_gray->dim.altura; 
    img_gray_medium_blur->dim.largura = img_gray->dim.largura;
    
    img_gray_medium_blur->pixels = (PixelGray*)malloc((img_gray_medium_blur->dim.altura * img_gray_medium_blur->dim.largura) * sizeof(PixelGray));
    if (img_gray_medium_blur == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_gray_medium_blur);
        return NULL;
    }
   

    for (int i = 0; i < img_gray->dim.altura; i++){
        for (int j = 0; j < img_gray->dim.largura; j++){
           posicao_atual = (i * img_gray->dim.largura) + j;  
           img_gray_medium_blur->pixels[posicao_atual].value =  pixelmediana_Gray(img_gray, posicao_atual);     
        }
    }

    free(img_gray->pixels);
    free(img_gray);
    return img_gray_medium_blur; 

} 



ImageRGB *median_blur_rgb(ImageRGB *img_rgb){ 
    
    ImageRGB *img_RGB_median_blur = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_RGB_median_blur == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_RGB_median_blur->dim.altura = img_rgb->dim.altura; 
    img_RGB_median_blur->dim.largura = img_rgb->dim.largura;
    
    img_RGB_median_blur->pixels = (PixelRGB*)malloc((img_RGB_median_blur->dim.altura * img_RGB_median_blur->dim.largura) * sizeof(PixelRGB));
    if (img_RGB_median_blur->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_RGB_median_blur);
        return NULL;
    }

    for (int i = 0; i < img_rgb->dim.altura; i++){
        for (int j = 0; j < img_rgb->dim.largura; j++){
           int posicao_atual = (i * img_rgb->dim.largura) + j; 
           img_RGB_median_blur->pixels[posicao_atual].blue = pixelmediana_RGB(img_rgb, posicao_atual, 1); 
           img_RGB_median_blur->pixels[posicao_atual].green = pixelmediana_RGB(img_rgb, posicao_atual, 2);  
           img_RGB_median_blur->pixels[posicao_atual].red = pixelmediana_RGB(img_rgb, posicao_atual, 3);   
        }
    }
    free(img_rgb->pixels);
    free(img_rgb);
    return img_RGB_median_blur; 
}

ImageGray *transpose_gray(ImageGray *img_gray) {
    ImageGray *img_gray_transpose = (ImageGray*)malloc(sizeof(ImageGray));
    if (img_gray_transpose == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_gray_transpose->dim.altura = img_gray->dim.largura;
    img_gray_transpose->dim.largura = img_gray->dim.altura;

    img_gray_transpose->pixels = (PixelGray*)malloc((img_gray_transpose->dim.altura * img_gray_transpose->dim.largura) * sizeof(PixelGray));

    if (img_gray_transpose->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_gray_transpose);
        return NULL;
    }

    for (int i = 0; i < img_gray->dim.altura; i++) {
        for (int j = 0; j < img_gray->dim.largura; j++) {
            img_gray_transpose->pixels[i * img_gray_transpose->dim.largura + j].value = img_gray->pixels[j * img_gray->dim.largura + i].value;
        }
    }

    free(img_gray->pixels);
    free(img_gray);
    
    return img_gray_transpose;
}

ImageRGB *transpose_rgb(ImageRGB *img_gray) {
    ImageRGB *img_rgb_transpose = (ImageRGB*)malloc(sizeof(ImageRGB));
    if (img_rgb_transpose == NULL) {
        printf("Erro ao alocar memória para a imagem.\n");
        return NULL;
    }

    img_rgb_transpose->dim.altura = img_gray->dim.largura;
    img_rgb_transpose->dim.largura = img_gray->dim.altura;

    img_rgb_transpose->pixels = (PixelRGB*)malloc((img_rgb_transpose->dim.altura * img_rgb_transpose->dim.largura) * sizeof(PixelRGB));

    if (img_rgb_transpose->pixels == NULL) {
        printf("Erro ao alocar memória para os pixels da imagem.\n");
        free(img_rgb_transpose);
        return NULL;
    }

    for (int i = 0; i < img_gray->dim.altura; i++) {
        for (int j = 0; j < img_gray->dim.largura; j++) {
            img_rgb_transpose->pixels[i * img_rgb_transpose->dim.largura + j].red = img_gray->pixels[j * img_gray->dim.largura + i].red;
            img_rgb_transpose->pixels[i * img_rgb_transpose->dim.largura + j].green = img_gray->pixels[j * img_gray->dim.largura + i].green;
            img_rgb_transpose->pixels[i * img_rgb_transpose->dim.largura + j].blue = img_gray->pixels[j * img_gray->dim.largura + i].blue;
        }
    }

    free(img_gray->pixels);
    free(img_gray);
    
    return img_rgb_transpose;
}

#ifndef IMAGE_H
#define IMAGE_H

typedef struct dimensoes {
    int altura, largura;
} Dimensoes;

typedef struct pixelRGB {
    int red, blue, green;
} PixelRGB;

typedef struct pixelGray {
    int value;
} PixelGray;

typedef struct imageGray {
    Dimensoes dim;
    PixelGray *pixels;
} ImageGray;

typedef struct imageRGB {
    Dimensoes dim;
    PixelRGB *pixels;
} ImageRGB;

typedef struct {
    int *Vetor_Bloco;
    int posicao;
}Bloco_Gray;

typedef struct {
    int *Vetor_Bloco_Green;
    int *Vetor_Bloco_Red;
    int *Vetor_Bloco_Blue;
    int posicao;
}Bloco_RGB;

typedef struct {
    int *valores_originais_green;
    int *valores_originais_red;
    int *valores_originais_blue;

    int *frequencias_orig_green;
    int *frequencias_orig_red; 
    int *frequencias_orig_blue;

    int *valores_equalizados_green;
    int *valores_equalizados_red;
    int *valores_equalizados_blue;

    int *frequencias_CDF_green;
    int *frequencias_CDF_red;
    int *frequencias_CDF_blue;

} Histograma_RGB;

typedef struct {
    int *valores_originais;
    int *frequencias;
    int *valores_equalizados;
    int *frequencias_CDF;
}Histograma_Gray;

typedef struct no_duplo_gray{
    ImageGray *img_gray;
    struct no_duplo_gray *prox;
    struct no_duplo_gray *ant;
}No_duplo_gray;

typedef struct no_duplo_rgb{
    ImageRGB *img_rgb;
    struct no_duplo_rgb *prox;
    struct no_duplo_rgb *ant;
}No_duplo_rgb;

typedef struct no_simples_gray{
    ImageGray *img_gray;
    struct no_simples_gray *prox;
}No_simples_gray;

typedef struct no_simples_rgb{
    ImageRGB *img_rgb;
    struct no_simples_rgb *prox;
}No_simples_rgb;

// Funções de criação e liberação
ImageGray *create_image_gray();
void free_image_gray(ImageGray *img_gray);
void print_image_gray(ImageGray *img_gray);

ImageRGB *create_image_rgb();
void free_image_rgb(ImageRGB *img_rgb);
void print_image_rgb(ImageRGB *img_rgb);

// Operações para ImageGray
ImageGray *flip_vertical_gray(ImageGray *img_gray);
ImageGray *flip_horizontal_gray(ImageGray *img_gray);
ImageGray *transpose_gray(ImageGray *img_gray);

// Operações para ImageRGB
ImageRGB *flip_vertical_rgb(ImageRGB *img_rgb);
ImageRGB *flip_horizontal_rgb(ImageRGB *img_rgb);
ImageRGB *transpose_rgb(ImageRGB *image);

// Manipulação por pixel para ImageGray
//ImageGray *clahe_gray(const ImageGray *image, int tile_width, int tile_height);
ImageGray *clahe_gray(ImageGray *img_gray);
ImageGray *median_blur_gray(ImageGray *img_gray);
// Manipulação por pixel para ImageRGB
//ImageRGB *clahe_rgb(const ImageRGB *image, int tile_width, int tile_height);
ImageRGB *clahe_RGB(ImageRGB *img_rgb);
ImageRGB *median_blur_rgb(ImageRGB *img_rgb);

ImageGray* copy_image_gray(ImageGray* img);
ImageRGB* copy_image_rgb(ImageRGB* img);

void OrdenaVetor(int *tempvetor, int cont);
int Mediana(int *temp_vetor, int cont);
int pixelmediana_Gray(ImageGray *img_gray, int posicao_atual);
int pixelmediana_RGB(ImageRGB *img_rgb, int posicao_atual, int cor); 

ImageRGB *Filtro_Sepia(ImageRGB *img_rgb);
ImageRGB *FiltroMosaico_RGB(ImageRGB *img_rgb);
ImageGray *FiltroMosaico_Gray(ImageGray *img_gray); 

No_duplo_gray *criar_lista_dupla_gray();
No_duplo_gray *Add_inicio_duplo_gray(No_duplo_gray *Lista, ImageGray *img_gray);
void manipular_historico_gray(No_duplo_gray *hist);

No_duplo_rgb *criar_lista_dupla_rgb();
No_duplo_rgb *Add_inicio_duplo_rgb(No_duplo_rgb *Lista, ImageRGB *img_rgb);
void manipular_historico_rgb(No_duplo_rgb *hist);

void free_hist_gray(No_duplo_gray *hist);
void free_hist_rgb(No_duplo_rgb *hist);

void operacoes_randomicas_gray(ImageGray *img_gray);
No_simples_gray *criar_lista_simples_gray();
No_simples_gray *Add_inicio_simples_gray(No_simples_gray *Lista, ImageGray *img_gray);
No_simples_gray *elemento_anterior_simples_gray(No_simples_gray *Lista, No_simples_gray *hist);
void free_hist_simples_gray(No_simples_gray *hist);


void operacoes_randomicas_rgb(ImageRGB *img_rgb);
No_simples_rgb *criar_lista_simples_rgb();
No_simples_rgb *Add_inicio_simples_rgb(No_simples_rgb *Lista, ImageRGB *img_rgb);
No_simples_rgb *elemento_anterior_simples_rgb(No_simples_rgb *Lista, No_simples_rgb *hist);
void free_hist_simples_rgb(No_simples_rgb *hist);
#endif // IMAGE_H

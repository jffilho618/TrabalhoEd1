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
ImageGray *clahe_gray(const ImageGray *image, int tile_width, int tile_height);
ImageGray *median_blur_gray(ImageGray *img_gray);
// Manipulação por pixel para ImageRGB
ImageRGB *clahe_rgb(const ImageRGB *image, int tile_width, int tile_height);
ImageRGB *median_blur_rgb(ImageRGB *img_rgb);

ImageGray* copy_image_gray(ImageGray* img);
ImageRGB* copy_image_rgb(ImageRGB* img);

void OrdenaVetor(int *tempvetor, int cont);
int Mediana(int *temp_vetor, int cont);
int pixelmediana_Gray(ImageGray *img_gray, int posicao_atual);
int pixelmediana_RGB(ImageRGB *img_rgb, int posicao_atual, int cor);
#endif // IMAGE_H

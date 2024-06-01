#include "image.h"

int main(){
    ImageGray *img_gray = create_image_gray();
    print_image_gray(img_gray);

    ImageRGB *img_rgb = create_image_rgb();
    print_image_rgb(img_rgb);

    img_gray = flip_vertical_gray(img_gray);
    print_image_gray(img_gray);

    img_gray = flip_horizontal_gray(img_gray);
    print_image_gray(img_gray);
    return 0;

}
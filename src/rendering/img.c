#include "../cub3D.h"

void    pxl_put(mlx_image_t *img, int x, int y, uint32_t color)
{
    if (x < 0 || y < 0 || x >= img->width || y >= img->height)
        return;
    img->pixels[x + y * img->width] = color;
}
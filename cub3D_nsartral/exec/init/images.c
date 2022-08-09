#include "inc/cub3d.h"

void	init_images(t_game *zz)
{
	zz->data.img = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	zz->data.addr = (int *)mlx_get_data_addr(zz->data.img, &zz->data.
			bits_per_pixel, &zz->data.line_length, &zz->data.endian);
	zz->data.img2 = mlx_new_image(zz->data.mlx_ptr, zz->rx, zz->ry);
	zz->data.addr2 = (int *)mlx_get_data_addr(zz->data.img2, &zz->
			data.bits_per_pixel, &zz->data.line_length, &zz->data.endian);
}
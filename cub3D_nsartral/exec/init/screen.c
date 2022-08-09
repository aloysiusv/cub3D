#include "inc/cub3d.h"

void	init_screen(t_game *zz)
{
	mlx_get_screen_size(zz->data.mlx_ptr, &zz->screenx, &zz->screeny);
	if (zz->rx > zz->screenx)
		zz->rx = zz->screenx;
	if (zz->ry > zz->screeny)
		zz->ry = zz->screeny;
}

#include "inc/cub3d.h"

void	init_moves(t_game *zz)
{
	zz->data.forward = 0;
	zz->data.back = 0;
	zz->data.left = 0;
	zz->data.right = 0;
	zz->data.rotate_right = 0;
	zz->data.rotate_left = 0;
	zz->ray.posx = (double)zz->dx + 0.5;
	zz->ray.posy = (double)zz->dy + 0.5;
	zz->ray.dirx = 0;
	zz->ray.diry = 0;
	zz->ray.planx = 0;
	zz->ray.plany = 0;
}
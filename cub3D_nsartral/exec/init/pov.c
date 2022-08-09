#include "inc/cub3d.h"

void	init_pov(t_game *zz)
{
	if (zz->depart == 'N')
		zz->ray.dirx = -1;
	if (zz->depart == 'S')
		zz->ray.dirx = 1;
	if (zz->depart == 'E')
		zz->ray.diry = 1;
	if (zz->depart == 'W')
		zz->ray.diry = -1;
	if (zz->depart == 'N')
		zz->ray.plany = 0.66;
	if (zz->depart == 'S')
		zz->ray.plany = -0.66;
	if (zz->depart == 'E')
		zz->ray.planx = 0.66;
	if (zz->depart == 'W')
		zz->ray.planx = -0.66;
}

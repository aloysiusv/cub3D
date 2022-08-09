#include "inc/cub3d.h"

void	incrementing(t_game *zz)
{
	while (zz->ray.hit == 0)
	{
		if (zz->ray.sidedistx < zz->ray.sidedisty)
		{
			zz->ray.sidedistx += zz->ray.deltadistx;
			zz->ray.mapx += zz->ray.stepx;
			zz->ray.side = 0;
		}
		else
		{
			zz->ray.sidedisty += zz->ray.deltadisty;
			zz->ray.mapy += zz->ray.stepy;
			zz->ray.side = 1;
		}
		if (zz->map[zz->ray.mapx][zz->ray.mapy] == '1')
			zz->ray.hit = 1;
	}
}

void	calculating(t_game *zz)
{
	if (zz->ray.side == 0)
		zz->ray.perpwalldist = ((double)zz->ray.mapx - \
				zz->ray.posx + (1 - (double)zz->ray.
				stepx) / 2) / zz->ray.raydirx;
	else
		zz->ray.perpwalldist = ((double)zz->ray.mapy - \
				zz->ray.posy + (1 - (double)zz->ray.
				stepy) / 2) / zz->ray.raydiry;
	zz->ray.lineheight = (int)(zz->ry / zz->ray.perpwalldist);
	zz->ray.drawstart = -zz->ray.lineheight / 2 + zz->ry / 2;
	if (zz->ray.drawstart < 0)
		zz->ray.drawstart = 0;
	zz->ray.drawend = zz->ray.lineheight / 2 + zz->ry / 2;
	if (zz->ray.drawend >= zz->ry || zz->ray.drawend < 0)
		zz->ray.drawend = zz->ry - 1;
}
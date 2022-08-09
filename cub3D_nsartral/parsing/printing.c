#include "inc/cub3d.h"

void	printing_parsing(t_game *zz)
{
	int i;

	if (zz->map_name)
		printf("map_name is : %s\n", zz->map_name);
	if (zz->rx)
		printf("rx is : %d\n", zz->rx);
	if (zz->ry)
		printf("ry is : %d\n", zz->ry);
	if (zz->ground_color)
		printf("ground_color is : %d\n", zz->ground_color);
	if (zz->sky_color)
		printf("sky_color is : %d\n", zz->sky_color);
	if (zz->r)
		printf("r is : %d\n", zz->r);
	if (zz->g)
		printf("g is : %d\n", zz->g);
	if (zz->b)
		printf("b is : %d\n", zz->b);
	if (zz->no)
		printf("no is : %s\n", zz->no);
	if (zz->so)
		printf("so is : %s\n", zz->so);
	if (zz->we)
		printf("we is : %s\n", zz->we);
	if (zz->ea)
		printf("ea is : %s\n", zz->ea);		
	if (zz->ylines)
		printf("ylines is : %d\n", zz->ylines);
	if (zz->xlines)
		printf("xlines is : %d\n", zz->xlines);
	i = -1;
	if (zz->map)
	{
		printf("map is :\n");
		while(++i < zz->ylines)
			printf("%s\n", zz->map[i]);
	}	
	if (zz->dx)
		printf("dx is : %d\n", zz->dx);
	if (zz->dy)
		printf("dy is : %d\n", zz->dy);
	if (zz->depart)
		printf("depart is : %c\n", zz->depart);
}
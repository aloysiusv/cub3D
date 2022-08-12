#include "../inc/cub3d.h"

void	printing_parsing(t_game *zz)
{
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
	if (zz->no)
		printf("no is : %s\n", zz->no);
	if (zz->so)
		printf("so is : %s\n", zz->so);
	if (zz->we)
		printf("we is : %s\n", zz->we);
	if (zz->ea)
		printf("ea is : %s\n", zz->ea);		
	if (zz->map)
	{
		printf("map is :\n");
		print_tab(zz->map);
	}
	if (zz->dx)
		printf("dx is : %d\n", zz->dx);
	if (zz->dy)
		printf("dy is : %d\n", zz->dy);
	if (zz->depart)
		printf("depart is : %c\n", zz->depart);
}
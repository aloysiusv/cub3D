#include "../inc/cub3d.h"

void	check_map_infos(t_game *zz)
{
	if (check_walls(zz) == 1)
		exiting("Map non entouree de 1\n", zz);
	if (zz->depart == 'Z')
		exiting("Pas de joueur\n", zz);
}

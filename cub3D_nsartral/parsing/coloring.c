#include "inc/cub3d.h"

void 	check_format(char *str, t_game *zz)
{
	int i;
	int m;
	int n;
	i = 1;
	m = 0;
	n = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] < '0' && str[i] > '9'))
		exiting("  ", zz);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] == ' ' || str[i] == ',')
	{
		if (str[i] == ',')
			m++;
		i++;
	}
	if (str[i] && str[i] < '0' && str[i] > '9')
		exiting("  ", zz);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
	{
		if (str[i] == ',')
			n++;
		i++;
	}
	if (str[i] && str[i] < '0' && str[i] > '9')
		exiting("  ", zz);
	if (m != 1 || n != 1)
		exiting("  ", zz);
	while (str[i])
		{
			if (str[i] == ',')
				exiting("  ", zz);
			i++;
		}
}	

int 	color_formating(char *str, t_game *zz)
{
	int i;
	if (str[1] != ' ')
		exiting("  ", zz);
	check_format(str, zz);
	i = 1;
	zz->r = 0;
	zz->g = 0;
	zz->b = 0;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		zz->r = (zz->r * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		zz->g = (zz->g * 10) + (str[i] - '0');
		i++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		zz->b = (zz->b * 10) + (str[i] - '0');
		i++;
	}
	if (zz->r > 255 || zz->g > 255 || zz->b > 255)
		exiting("  ", zz);
	return ((zz->r & 0xff) << 16) + ((zz->g & 0xff) << 8) + (zz->b & 0xff);
}

/*
** mlx_loop_hook.c for MiniLibX in 
** 
** Made by Charlie zz
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie zz
** Last update Fri Feb 23 17:11:39 2001 Charlie zz
*/


#include	"mlx_int.h"




int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param)
{
  xvar->loop_hook = funct;
  xvar->loop_param = param;
}

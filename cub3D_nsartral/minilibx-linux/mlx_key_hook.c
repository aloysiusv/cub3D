/*
** mlx_key_hook.c for MiniLibX in 
** 
** Made by Charlie zz
** Login   <ol@epitech.net>
** 
** Started on  Thu Aug  3 11:49:06 2000 Charlie zz
** Last update Fri Feb 23 17:10:09 2001 Charlie zz
*/


#include	"mlx_int.h"




int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param)
{
  win->hooks[KeyRelease].hook = funct;
  win->hooks[KeyRelease].param = param;
  win->hooks[KeyRelease].mask = KeyReleaseMask;
}

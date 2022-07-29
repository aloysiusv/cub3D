/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 23:01:00 by lrandria          #+#    #+#             */
/*   Updated: 2022/07/29 18:08:20 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "error_msgs.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
# define BUFFER_SIZE	4096

typedef struct		s_texture
{
	int				texdir;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_texture;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planx;
	double			plany;
	double			raydirx;
	double			raydiry;
	double			camerax;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;

	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				x;
	int				texture;
}					t_ray;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	int				minimapechelle;
	int				width;
	int				height;
	void			*img2;
	int				*addr2;
}					t_data;

typedef struct		s_game
{
	char			*map_name;
	int				rx;
	int				ry;
	int 			ground_color;
	int 		 	sky_color;
	int 			r;
	int 			g;
	int 			b;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				ylines;
	int				xlines;
	char			**map;
	char			depart;
	int				dx;
	int				dy;
	int				screenx;
	int				screeny;
	int				count;
	t_data			texture[4];
	t_data			data;
	t_ray			ray;
	t_texture		t;
}					t_game;

//COLORING 
void			check_format(char *str, t_game *zz);
int				color_formating(char *str, t_game *zz);
//CUB3D 
bool			check_arguments(int argc, char **argv, char **envp);
//EXITING 
int				exiting(t_game *zz, char *str);
//GNL_UTIlS 
int				ft_strlenz(char *str);
char			*ft_strchrz(char *str);
char			*ft_strdupz(char *str);
char			*ft_strjoinz(char *s1, char *s2);
//GNL 
char			*read_fdz(int fd, char *buffer);
char			*get_the_linez(char *buffer);
char			*new_bufferz(char *buffer);
char			*get_next_linez(int fd);
//init_PARSING 
void			init_parsing(char **argv, t_game *zz);
//init_RAYCASTING 
void			init_moves(t_game *zz);
void			init_pov(t_game *zz);
//KEYING 
int				keying(int keycode, t_game *zz);
int				key_releasing(int keycode, t_game *zz);
//MOVING 
void			moving_front_back(t_game *zz);
void			moving_left_right(t_game *zz);
void			rotating_left_right(t_game *zz);
void			rotating_left(t_game *zz, double olddirx);
//PARSING_ONE
int				check_map(t_game *zz);
int				pathing_texture(char *str, char **texture, t_game *zz, int j);
bool			line_type(char *line, t_game *zz);
bool			correct_map_infos(t_game *zz);
bool			fill_map_line(char *line, int i, t_game *zz);
int				ft_parsing(t_game *zz);
//PARSING_TWO
void			check_map_infos(t_game *zz);
//RAYCASTING_TOOLS
void			stepsidedist(t_game *zz);
void			incrementing_ray(t_game *zz);
void			wall_limit(t_game *zz);
void			change_frame(t_game *zz);
//RAYCASTING 
int				raycasting_loop(t_game *zz);
int				ft_mlx(t_game *zz);
//TEXTURING 
void			init_texture(t_game *zz);
void			coloring_wall(t_game *zz);
void			displaying_texture(t_game *zz, int x, int y);
void			get_texture(t_game *zz);
void			get_adress_texture(t_game *zz);
//TOOLS 
int				ft_strlen2(char *str);
bool			ft_charinstr(char *str, char c);
bool			beginning(char c, t_game *zz, int i, int j);
bool			check_walls(t_game *zz);
bool			is_whitespace(char c);
bool			empty_line(char *str);
bool			is_map_char(char c);
bool			ft_is_map(char *str);
bool			ft_check_resolution(const char *str);
void			ft_resolution(const char *str, t_game *zz);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
//UPDATING_RAYCASTING
void			updating_delta(t_game *zz);
void			updating_ray(t_game *zz);

#endif

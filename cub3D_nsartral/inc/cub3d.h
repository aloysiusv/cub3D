/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:38:41 by ebourdit          #+#    #+#             */
/*   Updated: 2022/08/09 11:26:16 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========================================================================= //
//                                   Library                                 //
// ========================================================================= //

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "error_msgs.h"

# define ALL_SPACES	" 	\x20\x08\x09\x0a\x0b\x0c\x0d"
# define SPACE_TAB	" 	"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W_Z	119
# define BACK_S_S		115
# define RIGHT_D_D		100
# define LEFT_A_Q		97
# define BUFFER_SIZE	4096

// ========================================================================= //
//                                Structures                                 //
// ========================================================================= //

typedef struct		s_node
{
	char			*stock;
	struct s_node	*next;
}					t_node;

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
	t_node			*my_file;
	t_data			texture[4];
	t_data			data;
	t_ray			ray;
	t_texture		t;
}					t_game;

// ========================================================================= //
//                                    Enum                                   //
// ========================================================================= //

// ========================================================================= //
//                                Executing                                  //
// ========================================================================= //

//exec/hooking/exiting.c
int			exiting(char *str, t_game *zz);
//exec/hooking/keying.c
int			keying(int keycode, t_game *zz);
//exec/hooking/releasing.c
int			releasing(int keycode, t_game *zz);
//exec/init/images.c
void		init_images(t_game *zz);
//exec/init/moves.c
void		init_moves(t_game *zz);
//exec/init/pov.c
void		init_pov(t_game *zz);
//exec/init/screen.c
void		init_screen(t_game *zz);
//exec/init/textures.c
void		init_textures(t_game *zz);
// void	get_textures(t_game *zz);
// void	get_adress_texture(t_game *zz);
//exec/raycasting/init_ray.c
void		init_ray(t_game *zz);
void		init_deltadist(t_game *zz);
void		init_sidedist(t_game *zz);
//exec/raycasting/moving.c
void		moving_front_back(t_game *zz);
void		moving_left_right(t_game *zz);
void		rotating_left_right(t_game *zz);
//exec/raycasting/processing_ray.c
void		incrementing(t_game *zz);
void		calculating(t_game *zz);
//exec/raycasting/raycasting.c
int			raycasting(t_game *zz);
//exec/raycasting/texturing_scene.c
void		texturing_scene(t_game *zz);

// ========================================================================= //
//                                 Parsing                                   //
// ========================================================================= //

bool		check_arguments(int argc, char **argv, char **envp);
void 		check_format(char *str, t_game *zz);
int 		color_formating(char *str, t_game *zz);
int			ft_strlenz(char *str);
char		*ft_strchrz(char *str);
char		*ft_strdupz(char *str);
char		*ft_strjoinz(char *s1, char *s2);
char		*custom_gnl(int fd);
void		init_parsing(char **argv, t_game *zz);
int			check_map(t_game *zz);
int			pathing_texture(char *str, char **texture, t_game *zz, int j);
bool		line_type(char *line, t_game *zz);
bool		correct_map_infos(t_game *zz);
bool		fill_map_line(char *line, int i, t_game *zz);
int			ft_parsing(t_game *zz);
void		check_map_infos(t_game *zz);
void		printing_parsing(t_game *zz);
int			ft_strlen2(char *str);
bool		ft_charinstr(char *str, char c);
bool		beginning(char c, t_game *zz, int i, int j);
bool		check_walls(t_game *zz);
bool		is_whitespace(char c);
bool		empty_line(char *str);
bool		is_map_char(char c);
bool		ft_is_map(char *str);
bool		ft_check_resolution(const char *str);
void		ft_resolution(const char *str, t_game *zz);

/* check_file.c */
void		check_file(t_game *zz);

// ========================================================================= //
//                                 Utils                                     //
// ========================================================================= //

/* utils_free.c */
void		free_all(t_game *zz);
void		free_tab(char **tab);
void		oops_crash(t_game *zz, char *msg);
void		clean_error_exit(t_game *zz, char *line, int fd, char *error_msg);

/* utils_str.c */
char		*trim_spaces(char *str);
bool		is_only_blanks(char *str);
size_t		count_chars(char *str, char c);

/* utils_tab.c */
size_t		get_tab_size(char **tab);

/* utils_nodes.c */
t_node	*create_node(char *line);
t_node	*add_next_node(t_node *current_last, char *line);
void	delete_node(t_node *to_del);
void	delete_lst(t_node *head);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:25:50 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 22:56:51 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "src/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SZ 64
# define MOUSE_SENSITIVITY 0.005
# define WIDTH 1000
# define HEIGHT 500
# define NUM_RAYS (WIDTH / 1)
# define FOV (60 * (M_PI / 180))
# define SCALE 70
# define MINI_SCALE 0.15

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_player
{
	double			distance_to_plane;
	double			xInwindow;
	double			yInwindow;
	double 			side_direction;
	double 			turn_direction;
	double 			walk_direction;
	double 			rotationangle;
	double 			rayangle;
	double 			move_speed;
	double 			rotation_speed;
	double			move_step;
	double			posXinmap;
	double			posYinmap;
}					t_player;

typedef struct s_ray
{
	double			x_hor;
	double			y_hor;
	double			x_ver;
	double			y_ver;
	double			angle;
	double			xIntercept_H;
	double			yIntercept_H;
	double			xIntercept_V;
	double			yIntercept_V;
	double			dis_H;
	double			dis_V;
	double			x_Step_H;
	double			y_Step_H;
	double			x_Step_V;
	double			y_Step_V;
	double			x_Wallhit;
	double			y_Wallhit;
	int				rayUp;
	int				rayDown;
	int				rayLeft;
	int				rayRight;
	int				vertical;
}					t_ray;

typedef struct s_cub
{
	int				i;
	int				j;
	int				v;
	int				o;
	int				p;
	int				line;
	int				len;
	int				fd;
	int				wall;
	char			**all_map;
	char			**text;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	char			**map;
	char			**copie;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				pos_i;
	int				pos_j;
	void			*mlx;
	void			*mlx_window;
	int				up;
	int				down;
	int				right;
	int				left;
	double			x_new;
	double			y_new;
	int door_state;
	t_img			img;
	t_img			east_img;
	t_img			west_img;
	t_img			south_img;
	t_img			north_img;
	t_player		player;
	t_ray			*rayData;

	// textures
	unsigned int	*east_table;
	unsigned int	*west_table;
	unsigned int	*south_table;
	unsigned int	*north_table;
}					t_cub;

/////////////////
//...<Utils>...//
/////////////////

void				printerror_message(char *str);
void				ft_putstr(char *s);
int					ft_strlen(char *str);
int					ft_atoi(char *str);
int					ft_strcmp(const char *str1, const char *str2);
char				*ft_strjoin(char *s1, char *s2);
int					ft_str_line(char *str);
char				**ft_free(char **p);
char				**ft_split(char const *s, char c);
void				initial_variable(t_cub *cub);

/////////////////
//..<Parsing>..//
/////////////////

void				parse(t_cub *cub, char *file);
void				check_extension(char *str);
void				check_opening(char *file);
void				count_map(t_cub *cub, char *file);
void				press_map(t_cub *cub, char *file);
void				check_duplicate(t_cub *cub, char *str);
void				duplicate(t_cub *cub);
void				check_color(char *str);
void				check_texture_color(t_cub *cub);
void				new_map(t_cub *cub);
char				*charge_space(char c, int len);
void				check_char(t_cub *cub);
void				check_not_char(t_cub *cub);
void				copie_with_spaces(t_cub *cub);
void				check_wall(t_cub *cub);

/////////////////
//<RenderM_map>//
/////////////////

void				own_mlx_pixel_put(t_cub *cub, int x, int y, int color);
void				ft_put_color(t_cub *cub, int x, int y, int color);
void				render_minimap(t_cub *cub);

//////////////////
//<RenderPlayer>//
//////////////////

void				render_player(t_cub *cub, int rayon);
void				player_position(t_cub *cub);
void				drowLine(t_cub *cub);
int					myExit_prs(t_cub *cub);
int					keyReleases(int code, t_cub *cub);
int					keyPress(int code, t_cub *cub);
void				rotationAngle(t_cub *cub);
void				moveWalkPlayer(t_cub *cub);
void				moveSidePlayer(t_cub *cub);
int					render(t_cub *cub);

//////////////////
//.<Raycasting.>//
//////////////////

void				CastRays(t_cub *cub);
void				CheckWall__Ver(t_ray *rayData, t_cub *cub);
void				convert_into_mapV(t_ray *rayData, t_cub *cub);
void				CheckWall__Hor(t_ray *rayData, t_cub *cub);
void				setDirections(t_ray *rayData);
void				drowLineRay(t_cub *cub, double x1, double y1);
double				normalizingAngle(double angle);
double				distance(double x, double y, double x1, double y1);
void				closest_dis(t_ray *rayData, t_cub *cub);

////// draw all ////
unsigned int		*get_table(t_cub *cub, int x);
double				hitVer(t_ray *ray);
void				draw_floor_ceiling(t_cub *cub, int start, int end, int x);
void				draw_wall_with_textures(t_cub *cub, int start, int end,
						double height, int x);
void				parse_texture_path(t_cub *cub, char *line);
int					handleMouse(int x, int y, t_cub *cub);
void				init_textures(t_cub *cub);

#endif
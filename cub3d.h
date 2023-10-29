/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:25:50 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/29 20:56:27 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "src/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SZ 64
# define MOUSE_SENSITIVITY 0.005
# define WIDTH 1000
# define HEIGHT 500
# define NUM_RAYS WIDTH
# define MINI_SCALE 0.15
# define VISIBLE_RANGE_THRESHOLD 50

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	void			*sprits[12];		
}					t_img;

typedef struct s_player
{
	double			distance_to_plane;
	double			x_inwindow;
	double			y_inwindow;
	double			side_direction;
	double			turn_direction;
	double			walk_direction;
	double			rotation_angle;
	double			rayangle;
	double			move_speed;
	double			rotation_speed;
	double			move_step;
	double			posx_inmap;
	double			posy_inmap;
}					t_player;

typedef struct s_ray
{
	double			x_hor;
	double			y_hor;
	double			x_ver;
	double			y_ver;
	double			angle;
	double			x_intercept_h;
	double			y_intercept_h;
	double			x_intercept_v;
	double			y_intercept_v;
	double			dis_h;
	double			dis_v;
	double			x_step_h;
	double			y_step_h;
	double			x_step_v;
	double			y_step_v;
	int				ray_up;
	int				ray_down;
	int				ray_left;
	int				ray_right;
	int				vertical;
	int				flags;
	int				flags_hor;
	bool			door_opened;
	int				flags_ver;
}					t_ray;

typedef struct s_cub
{
	int				size;
	int				l;
	int				xx;
	int				yy;
	char			*str;
	double			y_v1;
	double			x_v1;
	double			x0;
	double			y0;
	double			inx;
	double			iny;
	int				step;
	double			x;
	double			y;
	int				i;
	int				j;
	int				v;
	int				o;
	int				p;
	int				line;
	int				len;
	int				fd;
	int				wall;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	int				pos_i;
	int				pos_j;
	int				pos_door_x;
	int				pos_door_y;
	int				up;
	int				down;
	int				right;
	int				left;
	int				start;
	int				end;
	double			x_new;
	double			y_new;
	double			distance;
	double			new_dis;
	double			alpha;
	double			fov;
	char			**all_map;
	char			**text;
	char			*north_texture_path;
	char			*south_texture_path;
	char			*west_texture_path;
	char			*east_texture_path;
	char			*path_d;
	char			**map;
	char			**copie;
	void			*mlx;
	void			*mlx_window;
	t_img			img;
	t_img			east_img;
	t_img			west_img;
	t_img			south_img;
	t_img			north_img;
	t_img			door_img;
	t_img			sprite_img;
	t_player		player;
	t_ray			*ray_data;
	int				has_door;
	unsigned int	color_floor;
	unsigned int	color_ceiling;
	unsigned int	*east_table;
	unsigned int	*west_table;
	unsigned int	*south_table;
	unsigned int	*north_table;
	int				door_states;
	int				*door_pos;
	unsigned int	*door_closed_texture;
	unsigned int	*door_open_texture;
	unsigned int	*table;
	int				num_doors;
	int				**door_positions;
	int				sprite;
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
void				doors_aloc(t_cub *cub);

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
void				set_rotation(t_cub *cub);
void				check_not_char(t_cub *cub);
void				copie_with_spaces(t_cub *cub);
void				check_wall(t_cub *cub);
int					check_wall_door(t_cub *cub);

/////////////////
////<parsbonus>//
/////////////////

int					check_doors(t_cub *cub);
double				distance(double x, double y, double x1, double y1);

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
void				drow_line(t_cub *cub);
int					my_exit_prs(t_cub *cub);
int					key_releases(int code, t_cub *cub);
int					key_press(int code, t_cub *cub);
void				rotation_angle(t_cub *cub);
void				move_walk_player(t_cub *cub);
void				move_side_player(t_cub *cub);
int					render(t_cub *cub);

//////////////////
//.<Raycasting.>//
//////////////////

void				cast_rays(t_cub *cub);
void				check_wall__ver(t_ray *ray_data, t_cub *cub);
void				convert_into_map_v(t_ray *ray_data, t_cub *cub);
void				check_wall__hor(t_ray *ray_data, t_cub *cub);
void				set_directions(t_ray *ray_data);
void				drow_line_ray(t_cub *cub, double x1, double y1);
double				normalizing_angle(double angle);
double				distance(double x, double y, double x1, double y1);
void				closest_dis(t_ray *ray_data, t_cub *cub);

////// draw all ////

unsigned int		*get_table(t_cub *cub, int x);
double				hit_ver(t_ray *ray);
void				draw_floor_ceiling(t_cub *cub, int start, int end, int x);
void				draw_wall_with_textures(t_cub *cub, double height, int x);
void				parse_texture_path(t_cub *cub, char *line);
int					handle_mouse(int x, int y, t_cub *cub);
void				init_textures(t_cub *cub);
void				parse_texture_color(t_cub *cub, char *line);
char				*ft_strdup(const char *s1);
int					rgb_to_int(int r, int g, int b);
void				free_splite(char **split);
int					ft_isdigit(int c);
void				parse_line_color(char *str);
int					check_door_walk(t_cub *cub);
void				draw_floor_ceiling(t_cub *cub, int start, int end, int x);
int					check_doors(t_cub *cub);
int					calculate_number_of_doors(t_cub *cub);
void				doors_aloc(t_cub *cub);
void				free_map(t_cub *cub);
void				ft_get_table_door(t_cub *cub, int flags);

//////////////////
///..<Spray>...///
//////////////////

void				spray(t_cub *cub);
void				init_img(t_cub *cub);


#endif
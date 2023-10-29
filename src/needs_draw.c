/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:35:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/29 18:37:00 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_table_door(t_cub *cub, int flags)
{
	if (flags)
	{
		if (cub->map[(int)(cub->player.posx_inmap / 64)
			+ 1][(int)(cub->player.posy_inmap / 64)] == 'D')
			cub->map[(int)(cub->player.posx_inmap / 64)
				+ 1][(int)(cub->player.posy_inmap / 64)] = 'd';
		if (cub->map[(int)(cub->player.posx_inmap / 64)
			- 1][(int)(cub->player.posy_inmap / 64)] == 'D')
			cub->map[(int)(cub->player.posx_inmap / 64)
				- 1][(int)(cub->player.posy_inmap / 64)] = 'd';
		if (cub->map[(int)(cub->player.posx_inmap
				/ 64)][(int)(cub->player.posy_inmap / 64) + 1] == 'D')
			cub->map[(int)(cub->player.posx_inmap
					/ 64)][(int)(cub->player.posy_inmap / 64) + 1] = 'd';
		if (cub->map[(int)(cub->player.posx_inmap
				/ 64)][(int)(cub->player.posy_inmap / 64) - 1] == 'D')
			cub->map[(int)(cub->player.posx_inmap
					/ 64)][(int)(cub->player.posy_inmap / 64) - 1] = 'd';
	}
	else
	{
		if (cub->map[(int)(cub->player.posx_inmap / 64)
			+ 1][(int)(cub->player.posy_inmap / 64)] == 'd')
			cub->map[(int)(cub->player.posx_inmap / 64)
				+ 1][(int)(cub->player.posy_inmap / 64)] = 'D';
		if (cub->map[(int)(cub->player.posx_inmap / 64)
			- 1][(int)(cub->player.posy_inmap / 64)] == 'd')
			cub->map[(int)(cub->player.posx_inmap / 64)
				- 1][(int)(cub->player.posy_inmap / 64)] = 'D';
		if (cub->map[(int)(cub->player.posx_inmap
				/ 64)][(int)(cub->player.posy_inmap / 64) + 1] == 'd')
			cub->map[(int)(cub->player.posx_inmap
					/ 64)][(int)(cub->player.posy_inmap / 64) + 1] = 'D';
		if (cub->map[(int)(cub->player.posx_inmap
				/ 64)][(int)(cub->player.posy_inmap / 64) - 1] == 'd')
			cub->map[(int)(cub->player.posx_inmap
					/ 64)][(int)(cub->player.posy_inmap / 64) - 1] = 'D';
	}
}

unsigned int	*get_table(t_cub *cub, int x)
{
	if (cub->ray_data[x].flags)
	{
		return (cub->door_closed_texture);
	}
	else if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].ray_right)
		return (cub->east_table);
	else if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].ray_left)
		return (cub->west_table);
	else if (cub->ray_data[x].vertical == 0 && cub->ray_data[x].ray_up)
		return (cub->north_table);
	else
		return (cub->south_table);
}

double	hit_ver(t_ray *ray)
{
	double	distance;

	if (ray->dis_h < ray->dis_v)
	{
		distance = ray->dis_h;
		ray->vertical = 0;
	}
	else
	{
		distance = ray->dis_v;
		ray->vertical = 1;
	}
	return (distance);
}

void	draw_wall_with_textures(t_cub *cub, double height, int x)
{
	int		y;
	int		h;
	double	tex_x;
	double	texture_step;
	double	texture_pos;

	if (cub->ray_data[x].vertical)
		tex_x = fmod(cub->ray_data[x].y_ver, cub->north_img.height);
	else
		tex_x = fmod(cub->ray_data[x].x_hor, cub->north_img.height);
	cub->table = get_table(cub, x);
	texture_step = (double)cub->north_img.height / height;
	texture_pos = ((cub->start - (HEIGHT / 2) + (height / 2)) * texture_step);
	texture_pos = fmin(fmax(texture_pos, 0), cub->north_img.height - 1);
	y = cub->start;
	while (y < cub->end)
	{
		h = ((int)texture_pos * cub->north_img.height) + (tex_x);
		own_mlx_pixel_put(cub, x, y, cub->table[h]);
		texture_pos += texture_step;
		y++;
	}
}

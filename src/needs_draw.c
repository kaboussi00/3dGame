/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:35:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 14:51:10 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	*get_table(t_cub *cub, int x)
{
	if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].rayRight)
		return (cub->east_table);
	else if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].rayLeft)
		return (cub->west_table);
	else if (cub->ray_data[x].vertical == 0 && cub->ray_data[x].rayUp)
		return (cub->north_table);
	else
		return (cub->south_table);
}

double	hit_ver(t_ray *ray)
{
	double	distance;

	if (ray->dis_H < ray->dis_V)
	{
		distance = ray->dis_H;
		ray->vertical = 0;
	}
	else
	{
		distance = ray->dis_V;
		ray->vertical = 1;
	}
	return (distance);
}

void	draw_floor_ceiling(t_cub *cub, int start, int end, int x)
{
	int	y;

	y = 0;
	while (y <= start)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_ceiling);
		y++;
	}
	y = end;
	while (y < HEIGHT)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_floor);
		y++;
	}
}

void	draw_wall_with_textures(t_cub *cub, double height, int x)
{
	int				y;
	int				h;
	double			tex_x;
	double			texture_step;
	double			texture_pos;

	cub->table = get_table(cub, x);
	texture_step = (float)cub->north_img.height / height;
	texture_pos = (cub->start - (HEIGHT / 2) + (height / 2)) * texture_step;
	if (cub->ray_data[x].vertical)
		tex_x = fmod(cub->ray_data[x].y_ver, 64);
	else
		tex_x = fmod(cub->ray_data[x].x_hor, 64);
	y = cub->start;
	while (y < cub->end)
	{
		h = ((int)texture_pos * cub->north_img.height) + (tex_x
				* (cub->north_img.width / 64));
		own_mlx_pixel_put(cub, x, y, cub->table[h]);
		texture_pos += texture_step;
		y++;
	}
}

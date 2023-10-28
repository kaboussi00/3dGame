/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:35:34 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/28 12:43:46 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int	*ft_get_table_door(t_cub *cub)
{
	int		i;
	int		map_x;
	int		map_y;
	double	dist;

	dist = 0.0;
	i = 0;
	map_x = 0;
	map_y = 0;
	while (i < cub->num_doors)
	{
		map_x = cub->door_positions[i][0];
		map_y = cub->door_positions[i][1];
		dist = distance(cub->player.posXinmap, cub->player.posYinmap, map_x
				* SZ, map_y * SZ);
		if (dist <= CLOSE_DISTANCE_THRESHOLD && check_door_walk(cub))
			return (cub->map[map_x][map_y] = 'C', cub->door_closed_texture);
		else if (dist > CLOSE_DISTANCE_THRESHOLD
			&& cub->map[map_x][map_y] == 'C')
			return (cub->map[map_x][map_y] = 'D', cub->door_closed_texture);
		i++;
	}
	return (cub->door_closed_texture);
}

unsigned int	*get_table(t_cub *cub, int x)
{
	if (cub->ray_data[x].flags)
	{
		return (ft_get_table_door(cub));
	}
	else if (cub->ray_data[x].vertical == 1 && cub->ray_data[x].rayRight)
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

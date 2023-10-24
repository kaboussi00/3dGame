/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/23 22:56:57 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_rays_minimap(t_cub *cub)
{
	int		i;
	double	newX;
	double	newY;

	i = 0;
	while (i < NUM_RAYS)
	{
		newX = 100 + cos(cub->ray_data[i].angle) * 20;
		newY = 75  + sin(cub->ray_data[i].angle) * 20;
		drow_line_ray(cub, newX, newY);
		i++;
	}
}

void	draw_cub3d(t_cub *cub)
{
	int		x;
	double	height;

	x = 0;
	while (x < WIDTH)
	{
		cub->alpha = normalizing_angle(cub->ray_data[x].angle
				- cub->player.rotation_angle);
		cub->distance = hit_ver(&cub->ray_data[x]);
		cub->new_dis = cub->distance * cos(cub->alpha);
		height = (500 / cub->new_dis) * 110;
		cub->start = (HEIGHT / 2) - (height / 2);
		cub->end = cub->start + height;
		if (cub->end > HEIGHT)
			cub->end = HEIGHT;
		if (cub->start < 0)
			cub->start = 0;
		draw_floor_ceiling(cub, cub->start, cub->end, x);
		draw_wall_with_textures(cub, height, x);
		x++;
	}
}

int	render(t_cub *cub)
{
	mlx_clear_window(cub->mlx, cub->mlx_window);
	cast_rays(cub);
	draw_cub3d(cub);
	render_minimap(cub);
	render_player(cub, SZ / 4);
	draw_rays_minimap(cub);
	free(cub->ray_data);
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return (0);
}
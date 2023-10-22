/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/22 14:46:44 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int	i;

	i = 0;
	mlx_clear_window(cub->mlx, cub->mlx_window);
	cast_rays(cub);
	draw_cub3d(cub);
	render_minimap(cub);
	render_player(cub, SZ / 4);
	while (i < NUM_RAYS)
	{
		if (cub->ray_data[i].dis_H > cub->ray_data[i].dis_V)
			drow_line_ray(cub, cub->ray_data[i].x_ver, cub->ray_data[i].y_ver);
		else
			drow_line_ray(cub, cub->ray_data[i].x_hor, cub->ray_data[i].y_hor);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return (0);
}

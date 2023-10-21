/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 17:09:32 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_cub3d(t_cub *cub)
{
	int		x;
	double	alpha;
		double distance;
	double	new_dis;
	double	height;
	int		start;
	int		end;

	x = 0;
	while (x < WIDTH)
	{
		alpha = normalizingAngle(cub->rayData[x].angle
			- cub->player.rotationangle);
		distance = hitVer(&cub->rayData[x]);
		new_dis = distance * cos(alpha);
		height = (500 / new_dis) * 110;
		start = (HEIGHT / 2) - (height / 2);
		end = start + height;
		if (end > HEIGHT)
			end = HEIGHT;
		if (start < 0)
			start = 0;
		draw_floor_ceiling(cub, start, end, x);
		draw_wall_with_textures(cub, start, end, height, x);
		x++;
	}
}

int	render(t_cub *cub)
{
	int i = 0;
	mlx_clear_window(cub->mlx, cub->mlx_window);
	CastRays(cub);
	draw_cub3d(cub);
	render_minimap(cub);
	render_player(cub, SZ / 4);
	while (i < NUM_RAYS)
	{
		if (cub->rayData[i].dis_H > cub->rayData[i].dis_V)
			drowLineRay(cub, cub->rayData[i].x_ver, cub->rayData[i].y_ver);
		else
			drowLineRay(cub, cub->rayData[i].x_hor, cub->rayData[i].y_hor);
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_window, cub->img.img, 0, 0);
	return (0);
}
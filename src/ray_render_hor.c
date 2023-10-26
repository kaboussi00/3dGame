/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/26 22:36:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	convert_into_map_h(t_ray *ray_data, t_cub *cub)
{
	double	y;

	while (ray_data->x_hor >= 0 && ray_data->x_hor <= (cub->line - 6) * SZ
		&& ray_data->y_hor >= 0 && ray_data->y_hor <= cub->len * SZ)
	{
		y = ray_data->y_hor;
		if (ray_data->rayUp)
			y = ray_data->y_hor - 1;
		if (cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != '1'
			&& cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != ' ' \
            && cub->map[(int)(ray_data->x_hor / SZ)][(int)(y / SZ)] != 'D')
		{
			ray_data->x_hor += ray_data->x_Step_H;
			ray_data->y_hor += ray_data->y_Step_H;
		}
		else
			break ;
	}
}

void	check_wall__hor(t_ray *ray_data, t_cub *cub)
{
	ray_data->x_hor = cub->player.xInwindow;
	ray_data->y_hor = cub->player.yInwindow;
	ray_data->yIntercept_H = floor(ray_data->y_hor / SZ) * SZ;
	if (ray_data->rayDown)
		ray_data->yIntercept_H += SZ;
	ray_data->xIntercept_H = ray_data->x_hor + ((ray_data->yIntercept_H
				- ray_data->y_hor) / tan(ray_data->angle));
	ray_data->y_Step_H = SZ;
	if (ray_data->rayUp)
		ray_data->y_Step_H *= -1;
	ray_data->x_Step_H = SZ / tan(ray_data->angle);
	if ((ray_data->rayLeft && ray_data->x_Step_H > 0) || (ray_data->rayRight
			&& ray_data->x_Step_H < 0))
		ray_data->x_Step_H *= -1;
	ray_data->x_hor = ray_data->xIntercept_H;
	ray_data->y_hor = ray_data->yIntercept_H;
	convert_into_map_h(ray_data, cub);
}

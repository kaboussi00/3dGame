/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:42:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/29 02:44:11 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(double x, double y, double x1, double y1)
{
	double	distance;

	distance = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
	return (distance);
}

void	closest_dis(t_ray *ray_data, t_cub *cub)
{
	double	x;
	double	y;
	double	x_h1;
	double	y_h1;

	x = cub->player.x_inwindow;
	y = cub->player.y_inwindow;
	x_h1 = ray_data->x_hor;
	y_h1 = ray_data->y_hor;
	cub->x_v1 = ray_data->x_ver;
	cub->y_v1 = ray_data->y_ver;
	ray_data->dis_h = distance(x, y, x_h1, y_h1);
	ray_data->dis_v = distance(x, y, cub->x_v1, cub->y_v1);
	if (ray_data->dis_h < ray_data->dis_v)
		ray_data->flags = ray_data->flags_hor;
	else
		ray_data->flags = ray_data->flags_ver;
}

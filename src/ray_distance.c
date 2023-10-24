/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:42:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/24 15:04:23 by rel-isma         ###   ########.fr       */
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
	double	x_v1;
	double	y_v1;

	x = cub->player.xInwindow;
	y = cub->player.yInwindow;
	x_h1 = ray_data->x_hor;
	y_h1 = ray_data->y_hor;
	x_v1 = ray_data->x_ver;
	y_v1 = ray_data->y_ver;
	ray_data->dis_H = distance(x, y, x_h1, y_h1);
	ray_data->dis_V = distance(x, y, x_v1, y_v1);
}

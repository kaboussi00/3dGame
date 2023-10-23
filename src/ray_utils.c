/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:11:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/23 23:06:36 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	normalizing_angle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	drow_line_ray(t_cub *cub, double x1, double y1)
{
	double	x0;
	double	y0;
	double	inx;
	double	iny;
	int		step;
	double	x;
	double	y;

	// draw line
	x0 = 100;
	y0 = 75;
	x = x1 - x0;
	y = y1 - y0;
	if (fabs(x) > fabs(y))
		step = fabs(x);
	else
		step = fabs(y);
	inx = x / step;
	iny = y / step;
	cub->v = 0;
	while (cub->v < step)
	{
		own_mlx_pixel_put(cub, (int)round(x0), (int)round(y0),  0xf5756c);
		x0 += inx;
		y0 += iny;
		cub->v++;
	}
}


void	down_right(t_ray *ray_data)
{
	ray_data->rayUp = 0;
	ray_data->rayLeft = 0;
	ray_data->rayRight = 1;
	ray_data->rayDown = 1;
}

void	down_left(t_ray *ray_data)
{
	ray_data->rayUp = 0;
	ray_data->rayLeft = 1;
	ray_data->rayRight = 0;
	ray_data->rayDown = 1;
}

void	set_directions(t_ray *ray_data)
{
	double ra;
	double x;

	x = 1;
	ra = ray_data->angle;
	if (ra >= 0 && ra < M_PI_2)
		down_right(ray_data);
	else if (ra >= M_PI_2 && ra < M_PI)
		down_left(ray_data);
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
	{
		ray_data->rayUp = 1;
		ray_data->rayLeft = 1;
		ray_data->rayRight = 0;
		ray_data->rayDown = 0;
	}
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
	{
		ray_data->rayUp = 1;
		ray_data->rayLeft = 0;
		ray_data->rayRight = 1;
		ray_data->rayDown = 0;
	}
}
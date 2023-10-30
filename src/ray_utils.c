/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:11:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 11:30:39 by rel-isma         ###   ########.fr       */
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
	cub->x0 = 100;
	cub->y0 = 75;
	cub->x = x1 - cub->x0;
	cub->y = y1 - cub->y0;
	if (fabs(cub->x) > fabs(cub->y))
		cub->step = fabs(cub->x);
	else
		cub->step = fabs(cub->y);
	cub->inx = cub->x / cub->step;
	cub->iny = cub->y / cub->step;
	cub->v = 0;
	while (cub->v < cub->step)
	{
		own_mlx_pixel_put(cub, ((int)round(cub->x0) + 5),
			((int)round(cub->y0) + 5),
			0xf5756c);
		cub->x0 += cub->inx;
		cub->y0 += cub->iny;
		cub->v++;
	}
}

void	down_right(t_ray *ray_data)
{
	ray_data->ray_up = 0;
	ray_data->ray_left = 0;
	ray_data->ray_right = 1;
	ray_data->ray_down = 1;
}

void	down_left(t_ray *ray_data)
{
	ray_data->ray_up = 0;
	ray_data->ray_left = 1;
	ray_data->ray_right = 0;
	ray_data->ray_down = 1;
}

void	set_directions(t_ray *ray_data)
{
	double	ra;
	double	x;

	x = 1;
	ra = ray_data->angle;
	if (ra >= 0 && ra < M_PI_2)
		down_right(ray_data);
	else if (ra >= M_PI_2 && ra < M_PI)
		down_left(ray_data);
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
	{
		ray_data->ray_up = 1;
		ray_data->ray_left = 1;
		ray_data->ray_right = 0;
		ray_data->ray_down = 0;
	}
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
	{
		ray_data->ray_up = 1;
		ray_data->ray_left = 0;
		ray_data->ray_right = 1;
		ray_data->ray_down = 0;
	}
}

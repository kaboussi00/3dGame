/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:11:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/18 10:54:17 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double normalizingAngle(double angle)
{
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    return angle;
}

void drowLineRay(t_cub *cub, double x1, double y1)
{
	// draw line
	double x0;
	double y0;
	double inx;
	double iny;
	int step;

	x0 = cub->player.xInwindow;
	y0 = cub->player.yInwindow;
	double x = x1 - x0;
	double y = y1 - y0;
	if (fabs(x) > fabs(y))
		step = fabs(x);
	else
		step = fabs(y);
	inx = x / step;
	iny = y / step;
	cub->v = 0;
	while (cub->v < step)
	{
		own_mlx_pixel_put(cub, (int)round(y0), (int)round(x0), 0xf5756c);
		x0 += inx;
		y0 += iny;
		cub->v++;
	}
}

void down_right(t_ray *rayData)
{
	rayData->rayUp = 0;
	rayData->rayLeft = 0;
	rayData->rayRight = 1;
	rayData->rayDown = 1;
}

void	down_left(t_ray	*rayData)
{
	rayData->rayUp = 0;
	rayData->rayLeft = 1;
	rayData->rayRight = 0;
	rayData->rayDown = 1;
}


void setDirections(t_ray *rayData)
{
	double ra;
	double x;

	x = 1;
	ra = rayData->angle;
	if (ra >= 0 && ra < M_PI_2)
		down_right(rayData);
	else if (ra >= M_PI_2 && ra < M_PI)
		down_left(rayData);
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
	{
		rayData->rayUp = 1;
		rayData->rayLeft = 1;
		rayData->rayRight = 0;
		rayData->rayDown = 0;
	}
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
	{
		rayData->rayUp = 1;
		rayData->rayLeft = 0;
		rayData->rayRight = 1;
		rayData->rayDown = 0;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/08 14:41:22 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double normalizingAngle(double angle)
{
	// specific range between 0 and 360 degress
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
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

void setDirections(t_ray rayData)
{
	double ra;
	double x;

	x = 1;
	ra = rayData.angle;
	if (ra >= 0 && ra < M_PI_2)
	{
		rayData.rayUp = 0;
		rayData.rayLeft = 0;
		rayData.rayRight = 1;
		rayData.rayDown = 1;
	}
	else if (ra >= M_PI_2 && ra < M_PI)
	{
		rayData.rayUp = 1;
		rayData.rayLeft = 0;
		rayData.rayRight = 1;
		rayData.rayDown = 0;
	}
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
	{
		rayData.rayUp = 1;
		rayData.rayLeft = 1;
		rayData.rayRight = 0;
		rayData.rayDown = 0;
	}
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
	{
		rayData.rayUp = 0;
		rayData.rayLeft = 1;
		rayData.rayRight = 0;
		rayData.rayDown = 1;
	}
}

void CheckWall__Hor(t_ray rayData, t_cub *cub)
{
	int x_inmap;
	int y_inmap;

	rayData.x_hor = cub->player.xInwindow;
	rayData.y_hor = cub->player.yInwindow;
	rayData.yIntercept_H = floor(rayData.y_hor / SZ) * SZ;
	if (rayData.rayDown)
		rayData.yIntercept_H += SZ;
	rayData.xIntercept_H = rayData.x_hor + ((rayData.yIntercept_H - rayData.y_hor) / tan(rayData.angle));
	rayData.y_Step_H = SZ;
	if (rayData.rayUp)
		rayData.y_Step_H *= -1;
	rayData.x_Step_H = SZ / tan(rayData.angle);
	rayData.x_hor = rayData.xIntercept_H;
	rayData.y_hor = rayData.yIntercept_H;
	while (rayData.x_hor >= 0 && rayData.x_hor <= (cub->line - 6) * SZ
		&& rayData.y_hor >= 0 && rayData.y_hor <= cub->len * SZ)
	{
		if (cub->map[(int)(rayData.x_hor / SZ)][(int)(rayData.y_hor / SZ)] != '1'
			&& cub->map[(int)(rayData.x_hor / SZ)][(int)(rayData.y_hor / SZ)] != ' ')
		{
			rayData.x_hor += rayData.x_Step_H;
			rayData.y_hor += rayData.y_Step_H;
		}
		else
			break;
	}
	drowLineRay(cub, rayData.x_hor, rayData.y_hor);
}

void CastRays(t_cub *cub)
{
	int i = 0;
	cub->rayData = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->rayData)
		return;
	cub->player.rayangle = cub->player.rotationangle - (FOV / 2);
	while (i < NUM_RAYS)
	{
		cub->player.rayangle = normalizingAngle(cub->player.rayangle);
		cub->rayData[i].angle = cub->player.rayangle;
		setDirections(cub->rayData[i]);
		// check horizontal and vertical
		CheckWall__Hor(cub->rayData[i], cub);
		cub->player.rayangle += FOV / NUM_RAYS;
		i++;
	}
}

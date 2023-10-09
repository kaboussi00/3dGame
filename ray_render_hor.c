/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/08 19:04:36 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void CheckWall__Hor(t_ray *rayData, t_cub *cub)
{
	int	y;

	rayData->x_hor = cub->player.xInwindow;
	rayData->y_hor = cub->player.yInwindow;
	rayData->yIntercept_H = floor(rayData->y_hor / SZ) * SZ;
	if (rayData->rayDown)
		rayData->yIntercept_H += SZ;
	rayData->xIntercept_H = rayData->x_hor + ((rayData->yIntercept_H - rayData->y_hor) / tan(rayData->angle));
	rayData->y_Step_H = SZ;
	if (rayData->rayUp)
		rayData->y_Step_H *= -1;
	rayData->x_Step_H = SZ / tan(rayData->angle);
	if ((rayData->rayLeft && rayData->x_Step_H > 0) || (rayData->rayRight && rayData->x_Step_H < 0))
		rayData->x_Step_H *= -1;
	rayData->x_hor = rayData->xIntercept_H;
	rayData->y_hor = rayData->yIntercept_H;
	while (rayData->x_hor >= 0 && rayData->x_hor <= (cub->line - 6) * SZ
		&& rayData->y_hor >= 0 && rayData->y_hor <= cub->len * SZ)
	{
		y = rayData->y_hor;
		if (rayData->rayUp)
			y = rayData->y_hor - 1;
		if (cub->map[(int)(rayData->x_hor / SZ)][(int)(y / SZ)] != '1'
			&& cub->map[(int)(rayData->x_hor / SZ)][(int)(y / SZ)] != ' ')
		{
			rayData->x_hor += rayData->x_Step_H;
			rayData->y_hor += rayData->y_Step_H;
		}
		else
			break;
	}
}

double	distance(double x, double y, double x1, double y1)
{
	double distance;

	distance = sqrt(pow(x1 - x, 2)+ pow(y1 - y, 2));
	return (distance);
}

void closest_dis(t_ray *rayData, t_cub *cub)
{
	double x;
	double y;
	double xH1;
	double yH1;
	double xV1;
	double yV1;

	x = cub->player.xInwindow;
	y = cub->player.yInwindow;
	xH1 = rayData->x_hor;
	yH1 = rayData->y_hor;
	xV1 = rayData->x_ver;
	yV1 = rayData->y_ver;
	rayData->dis_H = distance(x, y, xH1, yH1);
	rayData->dis_V = distance(x, y, xV1, yV1);
	if (rayData->dis_H > rayData->dis_V)
	{
		// printf("in ver\n");
		drowLineRay(cub, rayData->x_ver, rayData->y_ver);
	}
	else
	{
		// printf("in hor\n");
		drowLineRay(cub, rayData->x_hor, rayData->y_hor);
	}
}

void CastRays(t_cub *cub)
{
	int i = 0;
	cub->rayData = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->rayData)
		return ;
	cub->player.rayangle = cub->player.rotationangle - (FOV / 2);
	while (i < NUM_RAYS)
	{
		cub->player.rayangle = normalizingAngle(cub->player.rayangle);
		cub->rayData[i].angle = cub->player.rayangle;
		setDirections(&cub->rayData[i]);
		CheckWall__Hor(&cub->rayData[i], cub);
		CheckWall__Ver(&cub->rayData[i], cub);
		closest_dis(&cub->rayData[i], cub);
		cub->player.rayangle += FOV / NUM_RAYS;
		i++;
	}
}

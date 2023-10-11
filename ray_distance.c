/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:42:12 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/11 23:27:11 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	// if (rayData->dis_H > rayData->dis_V)
	// 	drowLineRay(cub, rayData->x_ver, rayData->y_ver);
	// else
	// 	drowLineRay(cub, rayData->x_hor, rayData->y_hor);
}
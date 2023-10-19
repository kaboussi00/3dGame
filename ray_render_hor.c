/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/19 15:36:19 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	convert_into_mapH(t_ray *rayData, t_cub *cub)
{
	double y;

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

void CheckWall__Hor(t_ray *rayData, t_cub *cub)
{
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
	convert_into_mapH(rayData, cub);
}

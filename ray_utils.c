/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:11:27 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/05 13:39:41 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotationIndexX(t_cub *cub)
{
	double ra;
	double x;
		
	x = 1;
	ra = cub->rayData->angle;
	if (ra >= 0 && ra < M_PI_2)
		x *= 1;
	else if (ra >= M_PI_2 && ra < M_PI)
		x *= -1;
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
		x *= -1;
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
		x *= 1;
	return (x);
}

int	rotationIndexY(t_cub *cub)
{
	double ra;
	double y;

	y = 1;
	ra = cub->rayData->angle;
	if (ra >= 0 && ra < M_PI_2)
		y *= -1;
	else if (ra >= M_PI_2 && ra < M_PI)
		y *= -1;
	else if (ra >= M_PI && ra < 3 * M_PI / 2)
		y *= 1;
	else if (ra >= 3 * M_PI / 2 && ra < 2 * M_PI)
		y *= 1;
	return (y);
}
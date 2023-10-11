/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 07:04:47 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/11 10:36:14 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:38:53 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/05 13:16:18 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double    normalizingAngle(double angle)
{
    // specific range between 0 and 360 degress
    angle = fmod(angle ,(2 * M_PI)); 
    if (angle < 0)
        angle = (2 * M_PI) + angle;
    return (angle);
}

void    checkHorizantal(t_cub *cub)
{
    cub->rayData->yIntersection= //;
    cub->rayData->xIntersection= //;
}

void    checkVertical(t_cub *cub)
{
    cub->rayData->yIntersection= //;
    cub->rayData->xIntersection= //;
}

void renderRay(t_cub *cub) 
{
    int i = 0;
    cub->rayData = malloc(sizeof(t_ray) * NUM_RAYS);
	if (!cub->rayData)
        return ;
    cub->player.rayangle = cub->player.rotationangle - (FOV / 2); 
    cub->rayData->x = cub->player.xInwindow + NUM_RAYS * cos(cub->player.rayangle);
    cub->rayData->y = cub->player.yInwindow + NUM_RAYS * sin(cub->player.rayangle);
    printf("ray datax : %f\nray datay : %f\n ", cub->rayData->x, cub->rayData->y);
     while (i < NUM_RAYS) 
    {
        cub->rayData->angle = cub->player.rayangle;
        // ray.cast()
        cub->player.rayangle += FOV / NUM_RAYS;
        i++;
    }
}
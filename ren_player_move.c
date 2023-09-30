/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   REN_Playermove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:45:42 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/30 11:01:09 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double rotationAngle(t_cub *cub)
{
	//update rotation angle
	double angleChange;
	
	cub->player.rotationangle += cub->player.turn_direction * cub->player.rotation_speed;
	// if (cub->player.rotationangle >= 360 * (M_PI / 180))
	// 	cub->player.rotationangle -= 360 * (M_PI / 180);
	// else if (cub->player.rotationangle < 0)
	// 	cub->player.rotationangle += 360 * (M_PI / 180);
	return (cub->player.rotationangle);
}

void	movePlayer(t_cub *cub)
{
	double	dx;
	double	dy;
	cub->player.move_step = cub->player.walk_direction * cub->player.move_speed;
	cub->player.xInwindow += cos(cub->player.rotationangle) * cub->player.move_step;
	cub->player.yInwindow += sin(cub->player.rotationangle) * cub->player.move_step;
}
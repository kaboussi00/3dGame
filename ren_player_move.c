/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:45:42 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/01 10:43:37 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double rotationAngle(t_cub *cub)
{
	//update rotation angle
	
	cub->player.rotationangle += cub->player.turn_direction * cub->player.rotation_speed;
	// if (cub->player.rotationangle >= 360 * (M_PI / 180))
	// 	cub->player.rotationangle -= 360 * (M_PI / 180);
	// else if (cub->player.rotationangle < 0)
	// 	cub->player.rotationangle += 360 * (M_PI / 180);
	return (cub->player.rotationangle);
}

void	moveWalkPlayer(t_cub *cub)
{
	cub->player.move_step = cub->player.walk_direction * cub->player.move_speed;
	cub->player.posXinmap = cub->player.xInwindow + cos(cub->player.rotationangle) * cub->player.move_step;
	cub->player.posYinmap = cub->player.yInwindow + sin(cub->player.rotationangle) * cub->player.move_step;
	if (cub->map[(int)((cub->player.posXinmap) / SZ)][(int)((cub->player.posYinmap) / SZ)] != '1' \
	&& cub->map[(int)((cub->player.posXinmap) / SZ)][(int)((cub->player.posYinmap) / SZ)] != ' ')
	{
		cub->player.move_step = cub->player.walk_direction * cub->player.move_speed;
		puts("3");
		cub->player.xInwindow += cos(cub->player.rotationangle) * cub->player.move_step;
		cub->player.yInwindow += sin(cub->player.rotationangle) * cub->player.move_step;
	}
}

void	moveSidePlayer(t_cub *cub)
{
	cub->player.move_step = cub->player.side_direction * cub->player.move_speed;
	cub->player.posXinmap = cub->player.xInwindow + cos(cub->player.rotationangle + M_PI_2) * cub->player.move_step;
	cub->player.posYinmap = cub->player.yInwindow + sin(cub->player.rotationangle + M_PI_2) * cub->player.move_step;
	if (cub->map[(int)((cub->player.posXinmap) / SZ)][(int)((cub->player.posYinmap) / SZ)] != '1' \
	&& cub->map[(int)((cub->player.posXinmap) / SZ)][(int)((cub->player.posYinmap) / SZ)] != ' ')
	{
		cub->player.move_step = cub->player.side_direction * cub->player.move_speed;
		cub->player.xInwindow += cos(cub->player.rotationangle + M_PI_2) * cub->player.move_step;
		cub->player.yInwindow += sin(cub->player.rotationangle + M_PI_2) * cub->player.move_step;
	}
}
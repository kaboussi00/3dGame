/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:45:42 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/18 11:58:39 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotationAngle(t_cub *cub)
{
    // printf("Rotation Angle: %f\n", cub->player.rotationangle);
	cub->player.rotationangle += cub->player.turn_direction * cub->player.rotation_speed;
	if (cub->player.rotationangle >= 360 * (M_PI / 180))
		cub->player.rotationangle -= 360 * (M_PI / 180);
	if (cub->player.rotationangle < 0)
		cub->player.rotationangle += 360 * (M_PI / 180);
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

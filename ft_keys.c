/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:23:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/25 16:39:30 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	myExit_prs(t_cub *cub)
{
	(void)cub;
	exit(0);
}

int	move_player(t_cub *cub, int code)
{
	if (code == 13)
		cub->player.walk_direction = 1;
	if (code == 0)
		cub->player.walk_direction = -1;
	if (code == 1)
		cub->player.turn_direction = 1;
	if (code == 2)
		cub->player.turn_direction = -1;
	return (0);
}

int key_releases(t_cub	*cub, int code)
{
	if (code == 13)
		cub->player.walk_direction = 0;
	if (code == 0)
		cub->player.walk_direction = 0;
	if (code == 1)
		cub->player.turn_direction = 0;
	if (code == 2)
		cub->player.turn_direction = 0;
	return (0);
}

int	key_prs(int code, t_cub *cub)
{
	int line_p;

	if (code == 53)
		exit(0);
	if (code == 13 && !move_player(cub, code))
	{
    	// cub->x = cub->x + cos(cub->player.rotationangle) * 30;
    	// cub->y = cub->y + sin(cub->player.rotationangle) * 30;
	}
	if (code == 0 && !move_player(cub, code))
	{
		//
	}
	if (code == 1 && !move_player(cub, code))
	{
		//
	}
	if (code == 2 && !move_player(cub, code))
	{
		//
	}
	return (0);
}

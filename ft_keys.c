/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:23:06 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/27 17:09:48 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	myExit_prs(t_cub *cub)
{
	(void)cub;
	exit(0);
}

int	keyPress(int code, t_cub *cub)
{
	if (code == 53)
		exit (0);
	if (code == 13)
	{
		cub->player.walk_direction = 1;
		
	}
	if (code == 0)
	{
		cub->player.walk_direction = -1;
		
	}
	if (code == 1)
		cub->player.side_direction = 1;
	if (code == 2)
		cub->player.side_direction = -1;
	if (code == 123)
	{
		cub->player.turn_direction = -1;
		rotationAngle(cub);
	}
	if (code == 124)
	{
		cub->player.turn_direction = 1;
		rotationAngle(cub);
	}
	render(cub);
	return (0);
}

int key_releases(int code, t_cub *cub)
{
	if (code == 13)
		cub->player.walk_direction = 0;
	if (code == 0)
		cub->player.walk_direction = 0;
	if (code == 123)
		cub->player.turn_direction = 0;
	if (code == 124)
		cub->player.turn_direction = 0;
	render(cub);
	return (0);
}


// {
// 	initial_variable(cub);
// 	if (code == 123)
		
// 	if (code == 124)
// }

// int	key_prs(int code, t_cub *cub)
// {
// 	int line_p;

// 	if (code == 53)
// 		exit(0);
// 	if (code == 13 && !keyMovePlayer(cub, code))
// 	{
    	
// 	}
// 	if (code == 0 && !keyMovePlayer(cub, code))
// 	{
		
// 	}
// 	if (code == 1 && !keyMovePlayer(cub, code))
// 	{
// 		//
// 	}
// 	if (code == 2 && !keyMovePlayer(cub, code))
// 	{
// 		//
// 	}
// 	return (0);
// }

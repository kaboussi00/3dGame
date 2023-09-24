/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:29:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/24 21:07:36 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_position(t_cub *cub)
{
    // in window
    cub->pos_i = cub->pos_i * SZ + (SZ / 2);
    cub->pos_j = cub->pos_j * SZ + (SZ / 2);
}

void render_player(t_cub *cub, int rayon)
{
    double  i;
    double  degr;
    double  new_y;
    double  new_x;

    i = 0;
    while(i < rayon)
    {
        degr = 0;
        while(degr < 360)
        {
            new_x = i * cos(degr * M_PI / 180);
            new_y = i * sin(degr * M_PI / 180);
            own_mlx_pixel_put(cub, cub->pos_j + new_y, cub->pos_i + new_x, 0xf5756c);
            degr++;
        }
        i++;
    }
}

int	move_player(t_cub *cub, int code)
{
	cub->i = cub->pos_i;
	cub->j = cub->pos_j;
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
	cub->i = cub->pos_i;
	cub->j = cub->pos_j;
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
	cub->x = cub->pos_i;
	cub->y = cub->pos_j;
	if (code == 53)
		exit(0);
	if (code == 13 && !move_player(cub, code))
	{
		//cub->x = cub->x + 
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
 


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_player_drow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:52:09 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/28 21:29:41 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_position(t_cub *cub)
{
	cub->player.x_inwindow = cub->pos_i * SZ + (SZ / 2);
	cub->player.y_inwindow = cub->pos_j * SZ + (SZ / 2);
}

void	render_player(t_cub *cub, int rayon)
{
	double	i;
	double	degr;
	double	new_y;
	double	new_x;

	rayon = 6;
	i = 0;
	while (i < rayon)
	{
		degr = 0;
		while (degr < 360)
		{
			new_x = i * cos(degr * M_PI / 180);
			new_y = i * sin(degr * M_PI / 180);
			own_mlx_pixel_put(cub, (100 + new_y), (75 + new_x), 0xFF0000);
			degr++;
		}
		i++;
	}
}

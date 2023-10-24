/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:47:18 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/24 14:32:20 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	own_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		pixel = cub->img.addr + (y * cub->img.line_length + x
			* (cub->img.bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	ft_put_color(t_cub *cub, int x, int y, int color)
{
	int	i;
	int	j;

	i = x;
	while (i < x + SZ)
	{
		j = y;
		while (j < y + SZ)
		{
			if (i % SZ == 0 || j % SZ == 0)
				own_mlx_pixel_put(cub, j, i, 0x000000);
			else
				own_mlx_pixel_put(cub, j, i, color);
			j++;
		}
		i++;
	}
}


unsigned int	get_color(t_cub *cub, double start_x, double start_y)
{
	unsigned int color;

	color = 0x703a0a;
	int i = (int)(start_x / 64);
	int j = (int)(start_y / 64);
	if ((i >= 0 && i < cub->line - 6) && (j >= 0 && j < cub->len))
	{
		if (cub->map[i][j] == '0' || cub->map[i][j] == 'W' ||
			cub->map[i][j] == 'E' || cub->map[i][j] == 'S' ||
			cub->map[i][j] == 'N')
			color = 0xFFFFFF;
			return (color);
	}
	return (color);
}

void	render_minimap(t_cub *cub)
{
	unsigned int	color;
	double			start_x;
	double			start_y;
	int 			e;
	int 			f;

	start_x = (int)(cub->player.xInwindow) - 100;
	e = 0;
	while (e < 200)
	{
	    start_y = (int)(cub->player.yInwindow) - 75;
		f = 0;
		while (f < 150)
		{
			color = get_color(cub, start_x, start_y);
			own_mlx_pixel_put(cub, e + 5 , f + 5, color);
			start_y++;
			f++;
		}
		start_x++;
		e++;
	}
}

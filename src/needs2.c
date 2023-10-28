/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:42 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/28 21:47:23 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len_str;
	char	*scpy;

	len_str = ft_strlen((char *)s1);
	scpy = malloc((len_str + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

int	check_door_walk(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.x_inwindow + cos(cub->player.rotation_angle)
		* cub->player.move_step;
	y = cub->player.y_inwindow + sin(cub->player.rotation_angle)
		* cub->player.move_step;
	if ((cub->map[(int)((x) / SZ)][(int)((y) / SZ)] != 'D' && cub->map[(int)((x)
				/ SZ)][(int)((y) / SZ)] != ' ')
		&& ((int)(cub->map[(int)cub->player.x_inwindow
				/ SZ][(int)y / SZ] != 'D')
			&& cub->map[(int)x / SZ][(int)cub->player.y_inwindow / SZ] != 'D'))
		return (1);
	return (0);
}

void	draw_floor_ceiling(t_cub *cub, int start, int end, int x)
{
	int	y;

	y = 0;
	while (y <= start)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_ceiling);
		y++;
	}
	y = end;
	while (y < HEIGHT)
	{
		own_mlx_pixel_put(cub, x, y, cub->color_floor);
		y++;
	}
}

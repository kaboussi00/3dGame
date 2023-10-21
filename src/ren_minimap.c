/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:47:18 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 17:33:41 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void own_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
    char *pixel;

    if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
    {
        pixel = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
        *(unsigned int*)pixel = color;
    }
}

void    ft_put_color(t_cub *cub, int x, int y, int color)
{
    int i;
    int j;

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

void render_minimap(t_cub *cub)
{
    int pixel_color;
    int x;
    int y;

    cub->i = 0;
    while (cub->i < cub->line - 6)
    {
        cub->j = 0;
        while (cub->j < cub->len)
        {
            if (cub->map[cub->i][cub->j] == '1')
                pixel_color = 0x5D5447;
            else if (cub->map[cub->i][cub->j] == '0')
                pixel_color = 0xFFFDEB;
            y = (cub->i * SZ);
            while (y++ < (cub->i * SZ) + SZ)
            {
                x = (cub->j * SZ);
                while (x++ < (cub->j * SZ) + SZ)
                    own_mlx_pixel_put(cub, x * MINI_SCALE, y * MINI_SCALE, pixel_color);
            }
            cub->j++;
        }
        cub->i++;
    }
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ren_minimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 10:47:18 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/21 16:17:30 by rel-isma         ###   ########.fr       */
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
    cub->i = 0;
    while (cub->i < cub->line - 6)
    {
        cub->j = 0;
        while (cub->j < cub->len)
        {
            int pixel_color;
            if (cub->map[cub->i][cub->j] == '1')
                pixel_color = 0x1f0b09;
            else if (cub->map[cub->i][cub->j] == '0')
                pixel_color = 0x63413f;
            else if (cub->map[cub->i][cub->j] == 'W')
                pixel_color = 0x63413f;

            // Scale up the pixel size by a factor of 10
            int scaled_i = cub->i * SZ;
            int scaled_j = cub->j * SZ;

            // Draw a 10x10 square for each pixel of the minimap
            for (int y = scaled_i; y < scaled_i + SZ; y++)
            {
                for (int x = scaled_j; x < scaled_j + SZ; x++)
                {
                    own_mlx_pixel_put(cub, x * MINI_SCALE, y * MINI_SCALE, pixel_color);
                }
            }

            cub->j++;
        }
        cub->i++;
    }
}


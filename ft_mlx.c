#include "cub3d.h"

void own_mlx_pixel_put(t_cub *cub, int x, int y, int color)
{
    char *pixel;

    pixel = cub->img.addr + (y * cub->img.line_length + x * (cub->img.bits_per_pixel / 8));
    *(unsigned int*)pixel = color;
}

void    ft_put_color(t_cub *cub, int x, int y, int color)
{
    int i;
    int j;
    int c;

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

int	render_minimap(t_cub *cub)
{
	cub->i = -1;
	while (++cub->i < cub->line - 6)
	{
		cub->j = -1;
		while (++cub->j < cub->len)
		{
			if (cub->map[cub->i][cub->j] == '1')
                ft_put_color(cub, cub->i * SZ, cub->j * SZ, 0x1f0b09);
			if (cub->map[cub->i][cub->j] == '0')
				ft_put_color(cub, cub->i * SZ, cub->j * SZ, 0x63413f);
			if (cub->map[cub->i][cub->j] == 'W')
				ft_put_color(cub, cub->i * SZ, cub->j * SZ, 0x63413f);
		}
	}
    render_player(cub, SZ/4);
	return (0);
}
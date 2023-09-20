#include "cub3d.h"

void own_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)pixel = color;
}

void    ft_put_color(t_cub *cub, int x, int y, int color)
{
    int i;
    int j;

    i = x;
    while (i < x + 10)
    {
        j = y;
        while (j < y + 10)
        {
            own_mlx_pixel_put(cub->img.img, i, j, color);
            j++;
        }
        i++;
    }
}

int	render(t_cub *cub)
{
	cub->i = -1;
	while (++cub->i < cub->line - 6)
	{
		cub->j = -1;
		while (++cub->j < cub->len)
		{
			if (cub->map[cub->i][cub->j] == '1')
                ft_put_color(cub, cub->i, cub->j, 0xFF0000);
			if (cub->map[cub->i][cub->j] == '0')
				ft_put_color(cub, cub->i, cub->j, 0x00FF00);
			if (cub->map[cub->i][cub->j] == ' ')
				ft_put_color(cub, cub->i, cub->j, 0x0000FF);
			if (cub->map[cub->i][cub->j] == 'W')
				ft_put_color(cub, cub->i, cub->j, 0xFFFF00);
		}
	}
	return (0);
}
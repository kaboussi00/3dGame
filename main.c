/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/19 17:07:32 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void own_mlx_pixel_put(t_img *img, int x, int y, int color)
{
    char *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int*)pixel = color;
}


int main(int ac, char **av)
{
    t_cub   cub;
    t_img   img;

    if (ac != 2)
        printerror_message("invalid arg\n");
    parse(&cub, av[1]);
    cub.mlx = mlx_init();
    cub.mlx_window = mlx_new_window(cub.mlx, 2000, 1900, "my map <3");
    img.img = mlx_new_image(cub.mlx, 200, 200);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
    &img.line_length,&img.endian);
    own_mlx_pixel_put(img.img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(cub.mlx, cub.mlx_window, img.img, 0, 0);
    mlx_xpm_to_image();
    mlx_loop(cub.mlx);
}

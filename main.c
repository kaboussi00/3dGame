/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/20 19:50:49 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub   cub;

    if (ac != 2)
        printerror_message("invalid arg\n");
    parse(&cub, av[1]);
    cub.mlx = mlx_init();
    cub.mlx_window = mlx_new_window(cub.mlx, 1920, 1080, "my map <3");
    cub.img.img = mlx_new_image(cub.mlx, 10*cub.len, 10*(cub.line-6));
    cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, \
    &cub.img.line_length, &cub.img.endian);
    render(&cub);
    mlx_put_image_to_window(cub.mlx, cub.mlx_window, cub.img.img, 0, 0);
    mlx_loop(cub.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/24 21:05:31 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	myExit(t_cub *cub)
{
	(void)cub;
	exit(0);
}

int main(int ac, char **av)
{
    t_cub   cub;

    if (ac != 2)
        printerror_message("invalid arg\n");
    puts("1");
    initial_variable(&cub);
    parse(&cub, av[1]);
    cub.mlx = mlx_init();
    cub.mlx_window = mlx_new_window(cub.mlx, 1000, 500, "my map <3");
    cub.img.img = mlx_new_image(cub.mlx, SZ*cub.len, SZ*(cub.line-6));
    cub.img.addr = mlx_get_data_addr(cub.img.img, &cub.img.bits_per_pixel, \
    &cub.img.line_length, &cub.img.endian);
    player_position(&cub);
    render_minimap(&cub);
    mlx_put_image_to_window(cub.mlx, cub.mlx_window, cub.img.img, 0, 0);
    mlx_hook(cub.mlx_window, 02, 0L, key_prs, &cub);
	mlx_hook(cub.mlx_window, 17, 0L, myExit, &cub);
	mlx_hook(cub.mlx_window, 03, 0L, key_releases, &cub);
    mlx_loop(cub.mlx);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/27 17:03:51 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub   *cub;

    cub = malloc(sizeof(t_cub));
	if (!cub)
        return (0);
    if (ac != 2)
        printerror_message("invalid arg\n");
    initial_variable(cub);
    parse(cub, av[1]);
    player_position(cub);
    cub->mlx = mlx_init();
    cub->mlx_window = mlx_new_window(cub->mlx, 1000, 500, "my map <3");
    cub->img.img = mlx_new_image(cub->mlx, SZ*cub->len, SZ*(cub->line-6));
    cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, \
    &cub->img.line_length, &cub->img.endian);
    render(cub);
    // mlx_loop_hook(cub->mlx, &render, cub);
    mlx_hook(cub->mlx_window, 2, 0L, &keyPress, cub);
	mlx_hook(cub->mlx_window, 17, 0L, &myExit_prs, cub);
	mlx_hook(cub->mlx_window, 3, 0L, &key_releases, cub);
    mlx_loop(cub->mlx);
    return (0);
}
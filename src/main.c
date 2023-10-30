/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:17 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 02:37:54 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fu(void)
{
	system("leaks cub3d");
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	// atexit(fu);
	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (0);
	if (ac != 2)
		printerror_message("invalid arg\n");
	initial_variable(cub);
	parse(cub, av[1]);
	player_position(cub);
	cub->mlx = mlx_init();
	cub->mlx_window = mlx_new_window(cub->mlx, WIDTH, HEIGHT, "my map <3");
	cub->img.img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
		&cub->img.line_length, &cub->img.endian);
	init_textures(cub);
	init_img(cub);
	render(cub);
	mlx_hook(cub->mlx_window, 17, 0L, &my_exit_prs, cub);
	mlx_hook(cub->mlx_window, 3, 0L, &key_releases, cub);
	mlx_hook(cub->mlx_window, 2, 0L, &key_press, cub);
	mlx_hook(cub->mlx_window, 6, 0, &handle_mouse, cub);
	mlx_loop(cub->mlx);
	return (0);
}

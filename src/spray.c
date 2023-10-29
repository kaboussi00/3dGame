/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:42:43 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/29 20:49:22 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	spray(t_cub *cub)
{
	static int	update;

	if (update % 2)
	{
		cub->sprite++;
		cub->sprite %= 12;
	}
	update++;
}

void	imgs(t_cub *cub)
{
	cub->img.sprits[0] = mlx_xpm_file_to_image (cub->mlx, "./sprite/hold.xpm", \
	&cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[1] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame00.x\
	pm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[2] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame01.xpm"\
	, &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[3] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame02.xpm"\
	, &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[4] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame03.xpm"\
	, &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[5] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame04.xpm"\
	, &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	// if (!(img->hold || img->f0 || img->f1 || img->f2 || img->f3 || \
	// img->f4))
	// 	printerror_message("error");
}

void	init_img(t_cub *cub)
{
	imgs(cub);
	cub->img.sprits[6] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame05.\
	xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[7] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame06.\
	xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[8] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame07.\
	xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[9] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame08.\
	xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[10 ] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame0\
	9.xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	cub->img.sprits[11] = mlx_xpm_file_to_image (cub->mlx, "./sprite/frame10\
	.xpm", &cub->sprite_img.bits_per_pixel, &cub->sprite_img.line_length);
	// if (!(img->f5 || img->f6 || img->f7 || img->f8 || img->f9 || \
	// img->f10))
		// printerror_message("error");
}

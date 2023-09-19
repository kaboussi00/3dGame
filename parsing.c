/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:46 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/19 15:08:49 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse(t_cub *cub, char *file)
{
	check_extension(file);
    check_opening(file);
    count_map(cub, file);
    press_map(cub, file);
    check_texture_color(cub);
    new_map(cub);
    check_char(cub);
    check_not_char(cub);
    copie_with_spaces(cub);
    check_wall(cub);
}
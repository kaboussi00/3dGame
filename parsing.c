/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:46 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/23 13:54:01 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse(t_cub *cub, char *file)
{
	check_extension(file);
    puts("10");
    check_opening(file);
    puts("9");
    count_map(cub, file);
    puts("8");
    press_map(cub, file);
    puts("7");
    check_texture_color(cub);
    puts("6");
    new_map(cub);
    puts("5");
    check_char(cub);
    puts("4");
    check_not_char(cub);
    puts("3");
    copie_with_spaces(cub);
    puts("2");
    check_wall(cub);
}
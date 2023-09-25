/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:46 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/25 18:48:04 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse(t_cub *cub, char *file)
{
	check_extension(file);
    // printf("{after exten len ; %d, line ; %d}", cub->len, cub->line);
    // puts("10");
    check_opening(file);
    // printf("{aftr openning len ; %d, line ; %d}", cub->len, cub->line);
    // puts("9");
    count_map(cub, file);
    // printf("{after count len ; %d, line ; %d}", cub->len, cub->line);
    // puts("8");
    press_map(cub, file);
    // printf("{aftr press len ; %d, line ; %d}", cub->len, cub->line);
    // puts("7");
    check_texture_color(cub);
    // printf("{after texture len ; %d, line ; %d}", cub->len, cub->line);
    // puts("6");
    new_map(cub);
    // // printf("{after new map len ; %d, line ; %d}", cub->len, cub->line);
    // puts("5");
    check_char(cub);
    // printf("{after char len ; %d, line ; %d}", cub->len, cub->line);
    // puts("4");
    check_not_char(cub);
    // printf("{after not char len ; %d, line ; %d}", cub->len, cub->line);
    // puts("3");
    copie_with_spaces(cub);
    // printf("{after copie len ; %d, line ; %d}", cub->len, cub->line);
    // puts("2");
    check_wall(cub);
    // printf("{after walls len ; %d, line ; %d}", cub->len, cub->line);
}
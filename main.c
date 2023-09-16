/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/16 14:49:47 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void copy_map(t_cub *cub)
// {
//     cub->i = 6;
//     cub->j = 0;
//     int size;
//     cub->map = malloc(sizeof(char) * (cub->line - 5));
//     puts("here");
//     if (!cub->map)
//         return ; 
//     while (cub->all_map[cub->i])
//     {
//         puts("here2");
//         cub->map[cub->j] = malloc(sizeof(char) * (cub->len + 1));
//         cub->map[cub->j] = cub->all_map[cub->i];
//         cub->i++;
//         cub->j++;
//     }
//     cub->all_map[cub->i] = NULL;
// }

int main(int ac, char **av)
{
    t_cub cub;

    if (ac != 2)
        printerror_message("invalid arg\n");
    check_extension(av[1]);
    check_opening(av[1]);
    count_map(&cub, av[1]);
    press_map(&cub, av[1]);
    check_texture_color(&cub);
    puts("1");
    copy_map(&cub);
    puts("2");
    // while (cub->map[i])
    // {
    //     puts("e");
    //     printf("map : %s\n", cub.map[i]);
    //     i++;
    //     puts("v");
    // }
    int i = 0;
    while(cub.map[i])
    {
        printf("%s\n", cub.map[i++]);
    }
}

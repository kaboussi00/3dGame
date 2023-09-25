/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:37 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/25 16:30:29 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*charge_space(char c, int len)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc((len + 1) * sizeof(char));
	if (!p || len == 0)
		return (NULL);
	while (i < len)
		p[i++] = c;
	p[i] = '\0';
	return (p);
}

void	new_map(t_cub *cub)
{
    int size;
    int l;
    int x;
    int y;
    char *str;

    cub->i = 6;
    cub->j = 0;
    // printf("line befpre : %d\n", cub->line);
    cub->map = malloc(sizeof(char *) * (cub->line - 5));
    if (!cub->map)
        return ;
    // printf("len : %d\n", cub->len);
    // printf("line : %d\n", cub->line);
    while (cub->i < cub->line)
    {
        cub->map[cub->j] = malloc(sizeof(char) * (cub->len + 1));
        size = ft_str_line(cub->all_map[cub->i]);
        x = 0;
        y = 0;
        l = cub->len - size;
        while (cub->all_map[cub->i][x] && cub->all_map[cub->i][x] != '\n')
        {
            cub->map[cub->j][y++] = cub->all_map[cub->i][x++];
        }
        cub->map[cub->j][y] = '\0';
        // printf("map a: {%s}\n", cub->map[cub->j]);
        if (size < cub->len)
        {
            str = charge_space(' ', l);
            cub->map[cub->j] = ft_strjoin(cub->map[cub->j], str);
            free (str);
            str = NULL;
        }
        // printf("map b: {%s}\n", cub->map[cub->j]);
        cub->i++;
        cub->j++;
    }
    cub->map[cub->j] = NULL;
}
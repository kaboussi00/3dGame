/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_my_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:37 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/27 20:34:29 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	new_map(t_cub *c)
{
	c->i = 5;
	c->j = 0;
	c->map = malloc(sizeof(char *) * (c->line - 5));
	if (!c->map)
		return ;
	while (++c->i < c->line)
	{
		c->map[c->j] = malloc(sizeof(char) * (c->len + 1));
		c->size = ft_str_line(c->all_map[c->i]);
		c->xx = 0;
		c->yy = 0;
		c->l = c->len - c->size;
		while (c->all_map[c->i][c->xx] && c->all_map[c->i][c->xx] != '\n')
			c->map[c->j][c->yy++] = c->all_map[c->i][c->xx++];
		c->map[c->j][c->yy] = '\0';
		if (c->size < c->len)
		{
			c->str = charge_space(' ', c->l);
			c->map[c->j] = ft_strjoin(c->map[c->j], c->str);
			free(c->str);
			c->str = NULL;
		}
		c->j++;
	}
	c->map[c->j] = NULL;
}

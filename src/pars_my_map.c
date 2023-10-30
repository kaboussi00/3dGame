/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_my_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:08:37 by kaboussi          #+#    #+#             */
/*   Updated: 2023/10/30 00:11:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i] != NULL)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
	i = 0;
	while (cub->copie[i] != NULL)
	{
		free(cub->copie[i]);
		i++;
	}
	free(cub->copie);
	i = 0;
	while (cub->all_map[i] != NULL)
	{
		free(cub->all_map[i]);
		i++;
	}
	free(cub->all_map);
}

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
	c->i = 6;
	c->j = 0;
	c->map = malloc(sizeof(char *) * (c->line - 5));
	if (!c->map)
		return ;
	while (c->i < c->line)
	{
		c->map[c->j] = malloc(sizeof(char) * (c->len + 1));
		if (!c->map[c->j])
			printerror_message("malloc");
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
			if (!c->str)
				return;
			c->map[c->j] = ft_strjoin(c->map[c->j], c->str);
			if (!c->map[c->j])
				return;
			free(c->str);
			c->str = NULL;
		}
		c->j++;
		c->i++;
	}
	c->map[c->j] = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:43:56 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/25 22:45:20 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	parse_line_color(char *str)
{
	int	i;

	i = 0;
	if (str[0] == ',')
		printerror_message("Invalid color!\n");
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == '\0')
			printerror_message("Invalid color!\n");
		else if (str[i + 1] && str[i] == ',' && str[i + 1] == ',')
			printerror_message("Invalid color!\n");
		else if (str[i] == ',' || ft_isdigit(str[i]))
			i++;
		else
			printerror_message("Invalid color!\n");
	}
}

void	free_splite(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

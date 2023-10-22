/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:32:42 by rel-isma          #+#    #+#             */
/*   Updated: 2023/10/22 17:33:07 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len_str;
	char	*scpy;

	len_str = ft_strlen((char *)s1);
	scpy = malloc((len_str + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

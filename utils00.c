/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:09:10 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/19 15:09:12 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	printerror_message(char *str)
{
	write (1, "Error\n", 6);
	ft_putstr(str);
	exit(0);
}

void	ft_putstr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int			i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	int		s;
	long	n;

	s = 1;
	i = 0;
	n = 0;
    if (!str)
    {
        printerror_message("invalid color\n");
    }
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] < 48 || str[i] > 57)
		printerror_message("invalid color\n");
	while (str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + str[i++] - 48;
    if ((str[i] < 48 || str[i] > 57) && str[i])
		printerror_message("invalid color\n"); 
	return ((n * s));
}

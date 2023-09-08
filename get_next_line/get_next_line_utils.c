/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:39:41 by kaboussi          #+#    #+#             */
/*   Updated: 2023/03/21 15:44:42 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	ptr = (char *)str;
	if (ch == 0)
		return (ptr + ft_str_len(ptr));
	while (ptr[i] != '\0')
	{
		if (ptr[i] == (char)ch)
			return (ptr + i);
		i++;
	}
	return (0);
}

char	*ft_sub_str(char const *s, int start, int len)
{
	char			*p;
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_str_len(s))
	{
		if (ft_str_len(s) < len)
			len = ft_str_len(s);
		p = malloc((len + 1) * sizeof(char));
		if (!p)
			return (NULL);
		while (i < len)
			p[i++] = s[start++];
	}
	else
		p = malloc(1);
	if (!p)
		return (p);
	p[i] = '\0';
	return (p);
}

char	*ft_str_join(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	len1;
	size_t	len2;
	char	*p;	

	if (!s1)
		s1 = stdup("");
	i = 0;
	len1 = ft_str_len(s1);
	len2 = ft_str_len(s2);
	p = malloc((len1 + len2 + 1) * sizeof(char));
	if (!p)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		p[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		p[j++] = s2[i++];
	p[j] = 0;
	free(s1);
	return (p);
}

char	*stdup(const char *str)
{
	size_t	len;
	char	*p;
	int		i;

	len = ft_str_len(str);
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

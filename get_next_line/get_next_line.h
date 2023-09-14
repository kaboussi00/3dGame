/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:39:44 by kaboussi          #+#    #+#             */
/*   Updated: 2023/04/06 20:14:53 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1

# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

int			ft_str_len(const char *str);
char		*stdup(const char *str);
char		*ft_strchr(const char *str, int ch);
char		*ft_sub_str(char const *s, int start, int len);
char		*ft_str_join(char *s1, char *s2);
char		*get_line(char *buf);
char		*rest_line(char *buf);
char		*get_next_line(int fd);

#endif
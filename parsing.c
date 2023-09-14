/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:56:15 by kaboussi          #+#    #+#             */
/*   Updated: 2023/09/14 12:03:03 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i] != 'b')
		printerror_message("extension error\n");
	if (str[i - 1] != 'u')
		printerror_message("extension error\n");
	if (str[i -2] != 'c' )
		printerror_message("extension error\n");
	if (str[i - 3] != '.')
		printerror_message("extension error\n");
}

void	check_opening(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		printerror_message("can't open file1\n");
    close(fd);
}

void    count_map(t_cub *cub, char *file)
{
    char* line_readed;

    cub->fd=open(file, O_RDWR);
    if (cub->fd < 0)
        printerror_message("can't open file\n");
    line_readed = get_next_line(cub->fd);
    while (line_readed)
    {
        if (!line_readed)
            printerror_message("empty file\n");
        else
        {
            if (line_readed[0] != '\n') 
                cub->line++;
        }
        free(line_readed);
        line_readed = get_next_line(cub->fd);
    }
    close(cub->fd);
}

void press_map(t_cub *cub, char *file)
{
    char *read_line;

    cub->fd=open(file, O_RDWR);
    if (cub->fd < 0)
        printerror_message("can't open file\n");
    cub->all_map = malloc((sizeof(char *)) * (cub->line + 1));
    if  (!cub->all_map)
        return ;
    cub->i = 0;
    read_line = get_next_line(cub->fd);
    while (read_line)
    {
        if (read_line[0] != '\n')
            cub->all_map[cub->i++] = read_line;
		if (cub->i >= 6)
		{
			if (cub->len <= ft_str_line(read_line))
				cub->len = ft_str_line(read_line);
		}
        read_line=get_next_line(cub->fd);
    }
    cub->all_map[cub->i] = NULL;
}

void	check_duplicate(t_cub	*cub, char *text)
{
	if (!ft_strcmp(text, "NO"))
		cub->no += 1;
	if (!ft_strcmp(text, "SO"))
		cub->so += 1;
	if (!ft_strcmp(text, "WE"))
		cub->we += 1;
	if (!ft_strcmp(text, "EA"))
		cub->ea += 1;
	if (!ft_strcmp(text, "C"))
		cub->c += 1;
	if (!ft_strcmp(text, "F"))
		cub->f += 1;
}

void	check_color(char *str)
{
	int i;
	int n;
	char **s;

	i = 0;
	// printf("str : {%s}\n", str);
	s = ft_split(str, ',');
	// printf("str1 : {%s}\n", s[0]);
	// printf("str2 : {%s}\n", s[1]);
	// printf("str3 : {%s}\n", s[2]);
	if (s[0]== NULL || s[1] == NULL || s[2]== NULL || s[3] != NULL)
		printerror_message("invalid color\n");
	// puts("33");
	while (i <= 2)
	{
		n = ft_atoi(s[i]);
		if (n < 0 || n > 255)
			printerror_message("invalid color\n");
		i++;
	}
}

void	duplicate(t_cub	*cub)
{
	// printf("no : %d\n", cub->no);
	// printf("so : %d\n", cub->so);
	// printf("we : %d\n", cub->we);
	// printf("ea : %d\n", cub->ea);
	// printf("f : %d\n", cub->f);
	// printf("c : %d\n", cub->c);
	if (cub->no != 1 || cub->so != 1 || cub->we != 1 || cub->ea != 1 \
	|| cub->c != 1 || cub->f != 1)
		printerror_message("invalid texture7!\n");
}

void	check_texture_color(t_cub *cub)
{
	int i = 0;
	cub->no = 0;
	cub->so = 0;
	cub->we = 0;
	cub->ea = 0;
	cub->c = 0;
	cub->f = 0;
	while (i < 6)
	{
		cub->text = ft_split(cub->all_map[i], ' ');
		if (cub->text[2] != NULL || (ft_strcmp(cub->text[0] , "NO") && ft_strcmp(cub->text[0] , "SO") &&\
		 ft_strcmp(cub->text[0] , "WE") && ft_strcmp(cub->text[0] ,"EA") &&\
		  ft_strcmp(cub->text[0] , "C") && ft_strcmp(cub->text[0] , "F")))
		 	printerror_message("invalid texture!\n");
		check_duplicate(cub, cub->text[0]);
		if (!ft_strcmp(cub->text[0] , "C") || !ft_strcmp(cub->text[0] , "F"))
		{
			printf("color : {%s}\n", cub->text[1]);
			check_color(cub->text[1]);
		}
		else
			check_opening(cub->text[1]);
		i++;
	}
	duplicate(cub);
}

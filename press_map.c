#include "cub3d.h"

void    count_map(t_cub *cub, char *file)
{
    char* line_readed;

    cub->fd=open(file, O_RDWR);
    if (cub->fd < 0)
        printerror_message("can't open file\n");
    line_readed = get_next_line(cub->fd);
	if (!line_readed)
        printerror_message("empty file\n");
    while (line_readed)
    {
        if (line_readed[0] != '\n') 
            cub->line++;
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
		if (cub->i > 6)
		{
			if (cub->len <= ft_str_line(read_line))
				cub->len = ft_str_line(read_line);
		}
        read_line=get_next_line(cub->fd);
    }
    cub->all_map[cub->i] = NULL;
}

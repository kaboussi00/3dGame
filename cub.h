#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mlx.h>
#include <ftcntl.h>
#include <math.h>

typdef struct s_cub
{
    int i;
    int j;
    int line;
    int len;
    int fd;
    char **map;
}   t_cub;

#endif
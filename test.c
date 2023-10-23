// void	draw_rays_minimap(t_cub *cub)
// {
// 	int	i;
// 	double newX, newY;

// 	i = 0;
// 	while (i < NUM_RAYS)
// 	{
// 		newX = 100 + cos(cub->ray_data[i].angle) * 30;// replace 30 by distance of ray
// 		newY = 75  + sin(cub->ray_data[i].angle) * 30;
// 		drow_line_ray(cub, newX, newY);
// 		i++;
// 	}
// }
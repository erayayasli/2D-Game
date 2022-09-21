#include "so_long.h"

void	delete_game(t_map *map)
{
	mlx_destroy_image(map->mlx, map->img->collectible);
	mlx_destroy_image(map->mlx, map->img->player);
	mlx_destroy_image(map->mlx, map->img->exit);
	mlx_destroy_image(map->mlx, map->img->wall);
	free(map->img);

	int i = 0;
	while (map->lines[i])
		free(map->lines[i++]);
	free(map->lines);
	free(map);
	exit(0);
}

int	carpi(t_map *map)
{
	delete_game(map);
	return (0);
}
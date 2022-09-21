#include "so_long.h"

int main(int argc, char **argv)
{
    t_map	*map;

	if (argc != 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		exit(0);
    map->countmoves = 0;
	map->collectibles = 0;
	map->exits = 0;
	map->players = 0;

	read_map(map,argv[1]);
	components_okey(map);
	is_map_rectangle(map);

	
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx, map->weight * 64, map->height * 64, "2D-GAME");
	image(map);

	paste_comp(map,0,0);
	//ft_printf("%d\n", map->collectibles);

	mlx_hook(map->window, 2, 1L << 0, &organizer_move, map);
	mlx_hook(map->window, 17, 1, &carpi, map);


	mlx_loop(map->mlx);

	return (0);
}

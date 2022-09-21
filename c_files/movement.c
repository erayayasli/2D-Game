#include "so_long.h"

void	move(t_map *map, int changey, int changex)
{
	if (map->lines[map->player_y + changey][map->player_x + changex] == 'E' ||\
			map->lines[map->player_y + changey][map->player_x + changex] == 'C' || \
			map->lines[map->player_y + changey][map->player_x + changex] == '0')
	{
		if (map->lines[map->player_y + changey][map->player_x + changex] == 'C')
			map->collectibles--;
		if (map->lines[map->player_y + changey][map->player_x + changex] == 'E')
		{

			if (map->collectibles == 0)
			{
				mlx_destroy_window(map->mlx, map->window);
				delete_game(map);
			}
			else
				return ;
		}
		map->lines[map->player_y][map->player_x] = '0';
		mlx_clear_window(map->mlx, map->window);
		map->lines[map->player_y + changey][map->player_x + changex] = 'P';
		map->player_y += changey;
		map->player_x += changex;
		paste_comp(map, 0, 0);
	}
}

int	organizer_move(int key, t_map *map)
{

	if (key == UP)
		move(map, -1, 0);

	if (key == LEFT)
		move(map, 0, -1);
	
	if (key == DOWN)
		move(map, +1, 0);
	
	if (key == RIGHT)	
		move(map, 0, +1);

	else if (key == ESCAPE)
	{
		mlx_destroy_window(map->mlx, map->window);
		delete_game(map);
	}
	return (0);
}
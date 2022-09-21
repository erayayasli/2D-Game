#include "so_long.h"

void    image(t_map *map)
{
    int x;
    int y;

    map->img = malloc(sizeof(t_image));

    map->img->collectible = mlx_xpm_file_to_image(map->mlx,TAKE,&x,&y);
    map->img->player = mlx_xpm_file_to_image(map->mlx,USER,&x,&y);
    map->img->exit= mlx_xpm_file_to_image(map->mlx,EXIT,&x,&y);
    map->img->wall = mlx_xpm_file_to_image(map->mlx,WALL,&x,&y);

}

void paste_img(t_map *map,void *item,int x,int y)
{
    mlx_put_image_to_window(map->mlx,map->window,item,x * 64,y *64);
}

void paste_comp(t_map *map, int x, int y)
{
    int i = 0;
    int j = 0;
    if (map->countmoves > 0)
		ft_printf("Oynanan hamle sayısı:%d\n", map->countmoves);
    int c = 0;

    while(map->lines[i])
    {
        while(map->lines[i][j])
        {

            if (map->lines[i][j] == '1')
                paste_img(map,map->img->wall,x,y);
            if (map->lines[i][j] == '0')
                ;
            if (map->lines[i][j] == 'C')
            {
                paste_img(map,map->img->collectible,x,y);
                c++;
            }
            if (map->lines[i][j] == 'E')
                paste_img(map,map->img->exit,x,y);

            if (map->lines[i][j] == 'P')
            {
                paste_img(map,map->img->player,x,y);
                map->player_x = j;
                map->player_y = i;
            }
            x += 1;
            j++;
        }
        y+=1;
        x = 0;
        j = 0;
        i++;
    }
    map->collectibles = c;
    map->countmoves++;
}

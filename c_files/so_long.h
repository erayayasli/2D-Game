#ifndef SO_LONG_H
# define SO_LONG_H
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include "/home/eayasli/Desktop/deneme/inc/libft/libft.h"
# include "/home/eayasli/Desktop/deneme/inc/gnl/get_next_line.h"
# include "/home/eayasli/Desktop/deneme/inc/printf/ft_printf.h"
# include "/home/eayasli/Desktop/deneme/inc/mlx/mlx.h"

# define USER "./img/oyuncu.xpm"
# define EXIT "./img/exit.xpm"
# define WALL "./img/duvar.xpm"
# define TAKE "./img/take.xpm"

# define ESCAPE 65307
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361

typedef struct s_img
{
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
}t_image;


typedef struct s_map
{
    char    *map;
    void    *mlx;
    void    *window;
    char    **lines;
    int     weight;
    int     height;
    int     player_x;
    int     player_y;
    int     countmoves;
    int     players;
    int     exits;
    int     collectibles;
    t_image *img;
}t_map;

void    read_map(t_map *map, char *wholemap);
void components_okey(t_map *map);
void is_map_rectangle(t_map *map);
void    image(t_map *map);
void paste_img(t_map *map,void *item,int x,int y);
void paste_comp(t_map *map, int x, int y);

int	carpi(t_map *map);
void	delete_game(t_map *map);

void	move(t_map *map, int movey, int movex);
int	organizer_move(int key, t_map *map);


#endif

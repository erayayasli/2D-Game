#include "so_long.h"

void is_map_rectangle(t_map *map)
{
    int i = 0;

    while(map->lines[i])
    {
        if(map->weight != ft_strlen(map->lines[i]))
        {
            printf("Error\nMap dikdörtgen değil.");
            exit(0);
        }
        i++;
    }
}


void components_okey(t_map *map)
{
    int i = 0;
    int j = 0;

    int p = 0;
    int c = 0;
    int e = 0;
    int p2 = 0;
    while(map->lines[i])
    {
        while(map->lines[i][j])
        {
            //ft_printf("*");
            if(map->lines[i][j] == 'P' )
            {
                p = 1;
                p2++;
            }
            else if(map->lines[i][j] == 'C')
                c = 1;
            else if(map->lines[i][j] == 'E')
                e = 1;           
            else if(map->lines[i][j] == '1')
                ;
            else if(map->lines[i][j] == '0')
                ;
            else
            {
                printf("Error\nMapte farklı karakterler var.");
                exit(0);
            }
            j++;    
        }
        j = 0;
        i++;
    }
    if(p == 0 || c == 0|| e == 0 || p2 != 1 ) 
    {
        printf("Error\nP, C veya E 'de bir sorun var.");
        exit(0);
    }
}
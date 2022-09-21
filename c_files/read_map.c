#include "so_long.h"
void    read_map(t_map *map, char *wholemap)
{
    char *line;
    int fd;

    fd = open(wholemap,O_RDONLY);

	char *result = ft_strdup("");


	int lines_counter = 0;
    while(1) 
	{
		
		line = get_next_line(fd);
		if (!line)
			break;
		result = ft_strjoin(result,line);
		free(line);
		lines_counter++;
	}
	map->lines = ft_split(result,'\n');
	map->height = lines_counter;
	map->weight = ft_strlen(map->lines[0]);
	free(result);
}
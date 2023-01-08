#include"so_long.h"

void	read_everyting(int fd,char **save)
{
	int		i;
	char	*next_read;

	i = 1;
	next_read = malloc(BUFFER_SIZE + 1);
	if (!next_read)
		return ;
	while (i > 0)
	{
		i = read(fd, next_read, BUFFER_SIZE);
		if (i == -1)
		{
			free (*save);
			save = NULL;
			break ;
		}
		if (i == 0)
			break ;
		next_read[i] = '\0';
		*save = ft_strjoin(*save, next_read);
	}
	free(next_read);
	next_read = NULL;
}

char **ft_read(char **av)
{
    int fd;
	char *readmap;
	int i;
    char **map;
	
	readmap = NULL;
	fd = open (av[1], O_RDWR,0777);
	read_everyting(fd, &readmap);
	if(!readmap)
		return (ft_printf("Error in read error or file doesn't exist\n"),NULL);
	i = 0;
	while(readmap[i])
	{
		if((readmap[i] == '\n' && readmap[i + 1] == '\n') ||
			 (readmap[0] == '\n') || (readmap[ft_strlen(readmap) - 1] == '\n'))
		{
			ft_printf("Error\nempty ligne in map\n");
			return (free(readmap),readmap = NULL, NULL);
		}
		i++;
	}
    map = ft_split(readmap, '\n');
	free(readmap);
	readmap = NULL;
    return map;
}
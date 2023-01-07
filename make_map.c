#include"so_long.h"

char *read_everyting(int fd)
{
	char	*buff;
	char	*ret;
	int	c;

	buff = malloc(1);
	ret = malloc(1);
	if (!buff || !ret)
		return (NULL);
	c = 1;
	while (c > 0)
	{
		c = read(fd, buff, 1);
		if (c == -1)
			return (free(buff), NULL);
		buff[c] = '\0';
		ret = ft_strjoin(ret, buff);
	}
	return (free(buff), ret);
}

char **ft_read(char **av)
{
    int fd;
	char *readmap;
	int i;
    char **map;
	
	fd = open (av[1], O_RDWR,0777);
	readmap = read_everyting(fd);
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
	if(!map)
        return (free(readmap),readmap = NULL,NULL);
    return map;
}
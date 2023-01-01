// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   so_long1.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/01/01 06:00:53 by mserrouk          #+#    #+#             */
// /*   Updated: 2023/01/01 06:39:02 by mserrouk         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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

char *ft_read(char **av)
{
    int fd;
	char *readmap;
	int i;

	fd = open (av[1], O_CREAT | O_RDWR,0777);
	readmap = read_everyting(fd);
	if(!readmap)
		return NULL;

	i = 0;
	while(readmap[i])
	{
		if((readmap[i] == '\n' && readmap[i + 1] == '\n') || (readmap[0] == '\n'))
			return (free(readmap),readmap = NULL,NULL);
		i++;
	}
    return readmap;
}

int so_long(char **av)
{
    char **map;
    int i;
    char *readmap;

    readmap = ft_read(av);
    map = ft_split(readmap, '\n');
	if(!map)
        return (free(readmap),readmap = NULL,0 );
	free(readmap);
	readmap = NULL;
    i = map_make(map);
    if(i == 0)
        return (0);
    return (1);
}

int main (int ac, char **av)
{
	int i;
	if (ac != 2)
		return (1);
    i = 0;
	i = so_long(av);
	if (i == 1)
		printf("good map");
	else
		printf("bad map");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:37:45 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 00:11:14 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	read_everyting(int fd, char **save)
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

char	**ft_read(char **av)
{
	int		fd;
	char	*read;
	int		i;
	char	**map;

	read = NULL;
	fd = open (av[1], O_RDWR, 0777);
	read_everyting(fd, &read);
	close(fd);
	if (!read)
		return (ft_printf("Error\nerror in read or file doesn't exist\n"), NULL);
	i = -1;
	while (read[++i])
	{
		if ((read[i] == '\n' && read[i + 1] == '\n') || (read[0] == '\n')
			|| (read[ft_strlen(read) - 1] == '\n'))
		{
			ft_printf("Error\nempty ligne in map\n");
			return (free(read), read = NULL, NULL);
		}
	}
	map = ft_split(read, '\n');
	free(read);
	read = NULL;
	return (map);
}

#include "so_long.h"

char	*read_line(int fd, char *save)
{
	int		i;
	char	*next_read;

	i = 1;
	next_read = malloc(BUFFER_SIZE + 1);
	if (!next_read)
		return (free(save), save = NULL, NULL);
	while (!ft_strchr(save,'\n') && i > 0)
	{
		i = read(fd, next_read, BUFFER_SIZE);
		if (i == -1)
		{
			free (save);
			save = NULL;
			break ;
		}
		if (i == 0)
			break ;
		next_read[i] = '\0';
		save = ft_strjoin(save, next_read);
	}
	free(next_read);
	next_read = NULL;
	return (save);
}

char	*ft_get_line(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	str = malloc (i + 1);
	if (!str)
		return (free(save), save = NULL, NULL);
	while (save[j] && save[j] != '\n')
	{
		str[j] = save[j];
		j++;
	}
	if (save[j] == '\n')
		str[j++] = '\n';
	str[j] = '\0';
	return (str);
}

char	*adjust_next_line(char *save)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (save[i] == '\0')
		return (free(save), save = NULL, NULL);
	j = ft_strlen(save + i);
	str = malloc(j + 1);
	if (!str)
		return (free(save), save = NULL, NULL);
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	save = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 10240)
		return (NULL);
	save[fd] = read_line(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	if (!line)
		return (NULL);
	save[fd] = adjust_next_line(save[fd]);
	return (line);
}
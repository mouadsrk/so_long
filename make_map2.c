#include "so_long.h"

// char	*read_everyting(int fd, char *s)
// {
// 	int		i;
// 	char	*n;

// 	i = 1;
// 	n = malloc(BUFFER_SIZE + 1);
// 	if (!n)
// 		return (free(s), s = NULL, NULL);
// 	while (i > 0)
// 	{
// 		i = read(fd, n, BUFFER_SIZE);
// 		if (i == -1)
// 			return(free (s), s = NULL, free(n), n = NULL, NULL);
// 		if (i == 0)
// 			break ;
// 		n[i] = '\0';
// 		s = ft_strjoin(s, n);
// 	}
// 	return (free(n),n = NULL,s);
// }

int map_alphabet(char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'E' || map[i][j] == 'C' ||
			 map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return 1;
}

int chek_elelment(char **map,int *i)
{
    int a;
    int b;
    int c;

	b = 0 ;
	a = 0 ;
	c = 0 ;
	while(map[*i])
	{
        if(ft_strchr(map[*i],'C'))
            a = 1;
        if(ft_strchr(map[*i],'P'))
            b++;
        if(ft_strchr(map[*i],'E'))
            c++;
		(*i)++;
	}
    if(a ==1 && b == 1 && c == 1)
        return 1;
    return 0;
}

int mapcadre(char **m)
{
	int ligne;
	size_t len;
	size_t len2;

	ligne = 0;
	len = 0;
	len2 = 0;
	while(m[ligne])
		ligne++;
	len = ft_strlen(m[0]);
	while(m[ligne - 1][len2] == '1' && m[0][len2] == '1')
		len2++;
	if (len != len2)
		return 0;
	ligne--;
	while(ligne >= 0)
	{
		len2 = 0;
		len2 = ft_strlen(m[ligne]);
		if (len2 != len || m[ligne][0] != '1' || m[ligne][len2 -1] != '1')
			return (0);
		ligne--;
	}
	return 1;
}
int map_quality(char **map)
{
	int i;
	int c;

	c = 0;
	
	i = chek_elelment(map,&c);
	if(i == 0)
		return (ft_free(map,c),0);
	i = mapcadre(map);
	if(i == 0)
        return (ft_free(map,c),0);
	i  = map_data(map, &i);
		if(i == 0)
	 	return (ft_free(map,c),0);
	if(!map_alphabet(map))
		return (ft_free(map,c),0);
	return(1);
}

// int	map_make(char ** map)
// {
// 	int fd;
// 	char **map_dimention;
// 	char *readmap;
// 	int i;

// 	map_dimention = NULL;
// 	fd = open ("map.txt", O_CREAT | O_RDWR,0777);
// 	readmap = read_everyting(fd,readmap);
// 	if(!readmap)
// 		return NULL;
// 	i = 0;
// 	while(readmap[i])
// 	{
// 		if((readmap[i] == '\n' && readmap[i + 1] == '\n') || (readmap[0] == '\n'))
// 			return (free(readmap),readmap = NULL,NULL);
// 		i++;
// 	}
// 	map_dimention = ft_split(readmap, '\n');
// 	if(!map_dimention)
//         return (free(readmap),readmap = NULL,NULL);
// 	free(readmap);
	
// 	// readmap = NULL;
// 	if (map_quality(map) == 0)
// 		return (0);
//     return 1;
// }

// int main ()
// {
// 	int i;
// 	i = map();
// 	if (i == 1)
// 		ft_printf("good map");
// 	else
// 		ft_printf("bad map");
// }

#include "so_long.h"

char	*read_everyting(int fd, char *s)
{
	int		i;
	char	*n;

	i = 1;
	n = malloc(BUFFER_SIZE + 1);
	if (!n)
		return (free(s), s = NULL, NULL);
	while (i > 0)
	{
		i = read(fd, n, BUFFER_SIZE);
		if (i == -1)
			return(free (s), s = NULL, free(n), n = NULL, NULL);
		if (i == 0)
			break ;
		n[i] = '\0';
		s = ft_strjoin(s, n);
	}
	return (free(n),n = NULL,s);
}

int chek_elelment(char **readmap,int *i)
{
    int a;
    int b;
    int c;

	b = 0 ;
	a = 0 ;
	c = 0 ;
	while(readmap[*i])
	{
        if(ft_strchr(readmap[*i],'C'))
            a = 1;
        if(ft_strchr(readmap[*i],'P'))
            b++;
        if(ft_strchr(readmap[*i],'E'))
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
int map_quality(char **map_dimention)
{
	int i;
	int c;

	c = 0;
	i = chek_elelment(map_dimention,&c);
	if(i == 0)
		return (ft_free(map_dimention,c),0);
	i = mapcadre(map_dimention);
	if(i == 0)
        return (ft_free(map_dimention,c),0);
	i  = map_data(map_dimention, &i);
		if(i == 0)
		{
	 	return (ft_free(map_dimention,c),0);
		}
	return(1);
}

int map()
{
	int fd;
	char *readmap;
	char ** map_dimention ;

	fd = open ("map.txt",O_RDWR,0777);
	readmap = read_everyting(fd,readmap);
	if(!readmap)
		return 0;
	fd = 0;
	while(readmap[fd])
	{
		if((readmap[fd] == '\n' && readmap[fd + 1] == '\n') || (readmap[0] == '\n'))
		return(0);
		fd++;
	}
	map_dimention = ft_split(readmap, '\n');
	if(!map_dimention)
        return (free(readmap),readmap = NULL,0);
	free(readmap);
	readmap = NULL;
	if (map_quality(map_dimention) == 0)
		return 0;
    return 1;
}

int main ()
{
	int i;
	i = map();
	if (i == 1)
		ft_printf("good map");
	else
		ft_printf("bad map");
}

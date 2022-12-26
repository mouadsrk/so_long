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
	while(s[i])
	{
		if(s[i] == '\n' && s[i + 1] == '\n')
		return(free (s), s = NULL, free(n), n = NULL, NULL);
		i++;
	}
	return (free(n),n = NULL,s);
}

int chek_elelment(char **readmap)
{
    int a;
    int b;
    int c;
	int i;

	i = 0;
	b = 0 ;
	a = 0 ;
	c = 0 ;
	while(readmap[i])
	{
        if(ft_strchr(readmap[i],'C'))
            a = 1;
        if(ft_strchr(readmap[i],'P'))
            b++;
        if(ft_strchr(readmap[i],'E'))
            c++;
		i++;
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
		ft_printf("%s\n",m[ligne]);
		len2 = 0;
		len2 = ft_strlen(m[ligne]);
		if (len2 != len || m[ligne][0] != '1' || m[ligne][len2 -1] != '1')
			return (0);
		ligne--;
	}
	return 1;
}


int map_quality()
{
    int i;
	int fd;
	char *readmap;
	char ** map_dimention ;
	int c;

	fd = open ("map.txt",O_RDWR,0777);
	readmap = read_everyting(fd,readmap);
	if(!readmap)
		return 0;
	map_dimention = ft_split(readmap, '\n');
	if(!map_dimention)
        return 0;
	free(readmap);
	readmap =NULL;
	i =  chek_elelment(map_dimention);
		if(i == 0)
		return 0;
	i = mapcadre(map_dimention);
		if(i == 0)
        return 0;
		
    return 1;
}
int main ()
{
	int i;
	i = map_quality();
	if (i == 1)
		ft_printf("good map");
	else
		ft_printf("bad map");
}

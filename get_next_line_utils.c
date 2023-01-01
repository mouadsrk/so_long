#include "so_long.h"

int	ft_strchr(char *str,char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	if (!dst && !src)
		return (NULL);
	if (src == dst)
		return (dst);
	d = (char *)dst;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s1);
	ptr = (char *) malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    	*str;
    int        i;
    int        j;

    if (!s1 || !s2)
        return (NULL);
    i = ft_strlen(s2) + ft_strlen(s1);
    str = (char *)malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = -1;
    while (s1[++j])
        str[j] = s1[j];
    while (s2[i])
        str[j++] = s2[i++];
    str[j] = '\0';
        free(s1);
    return (str);
}
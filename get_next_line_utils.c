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


char	*ft_strjoin(char *s1, char *s2)
{
	size_t	lens1;
	size_t	lens2;
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc(lens1 + lens2 + 1);
	if (ptr == NULL)
		return (free(s1), free(s2), NULL);
	ft_memcpy(ptr, s1, lens1);
	ft_memcpy(ptr + lens1, s2, lens2);
	ptr[lens1 + lens2] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}
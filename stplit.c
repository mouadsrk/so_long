/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stplit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:30:47 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 15:31:24 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*ptr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen((char *) s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen((char *) s))
		ptr = (char *) malloc((ft_strlen((char *)s) - start + 1) * 1);
	else
		ptr = (char *) malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (s[start + j] && (j < len))
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

void	ft_free(char **arr, int r)
{
	int	i;

	i = 0;
	while (i <= r)
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

int	ft_word(char const	*s, char c)
{
	int	i;
	int	r;

	r = 0;
	if (*s != '\0')
	{
		i = ft_strlen((char *) s) - 1;
		if (s[i] != c)
			r++;
		i = 0;
		while (s[i])
		{
			if ((s[i] != c && s[i + 1] == c && c != 0))
			r++;
		i++;
		}
	}
	return (r);
}

void	ft_allocation(int r, char c, char **arr, const char *s)
{
	int	j;
	int	i;
	int	l;

	l = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		i = i + j;
		j = 0;
		while (s[i] == c && s[i])
				i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (l < r)
		{
			arr[l] = ft_substr(s, i, j);
			if (!arr[l])
				return (ft_free(arr, l));
			l++;
		}
	}
	arr[l] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		r;
	char	**arr;

	if (s == NULL)
		return (NULL);
	r = ft_word(s, c);
	arr = (char **)malloc((r + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	ft_allocation(r, c, arr, s);
	return (arr);
}

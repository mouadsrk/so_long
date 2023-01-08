/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_quality2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:34:44 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 16:42:34 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_alphabet(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C' ||
				map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'P')
				j++;
			else
			{
				ft_printf("Error\n");
				ft_printf("The map can be composed of only 5 characters:\n");
				ft_printf("'1','0','P','C' and 'E'\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	chek_elelment(char **map, int *i)
{
	int	a;
	int	b;
	int	c;

	b = 0 ;
	a = 0 ;
	c = 0 ;
	while (map[*i])
	{
		if (ft_strchr(map[*i], 'C'))
			a = 1;
		if (ft_strchr(map[*i], 'P'))
			b++;
		if (ft_strchr(map[*i], 'E'))
			c++;
		(*i)++;
	}
	if (a == 1 && b == 1 && c == 1)
		return (1);
	ft_printf("Error\nThe map must contain 1 'E', 1 'P', and at least 1 'C'\n");
	return (0);
}

int	mapcadre(char **m)
{
	int		ligne;
	size_t	len2;

	ligne = -1;
	while (m[++ligne])
	{
		len2 = 0;
		len2 = ft_strlen(m[ligne]);
		if (len2 != ft_strlen(m[0]))
			return (ft_printf("Error\nThe map must be rectangular.\n"), 0);
	}
	len2 = 0;
	while (m[ligne - 1][len2] == '1' && m[0][len2] == '1')
		len2++;
	if (ft_strlen(m[0]) != len2)
		return (ft_printf("Error\nThe map must be surrounded by walls\n"), 0);
	while (--ligne >= 0)
	{
		len2 = 0;
		len2 = ft_strlen(m[ligne]);
		if (m[ligne][0] != '1' || m[ligne][len2 -1] != '1')
			return (ft_printf("Error\nThe map must be surrounded by walls"), 0);
	}
	return (1);
}

int	map_quality(char **map)
{
	int	i;
	int	c;

	c = 0;
	i = chek_elelment(map, &c);
	if (i == 0)
		return (ft_free(map, c), 0);
	i = mapcadre(map);
	if (i == 0)
		return (ft_free(map, c), 0);
	i = map_data(map);
	if (i == 0)
		return (ft_free(map, c), 0);
	if (!map_alphabet(map))
		return (ft_free(map, c), 0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapdata3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:01:22 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 19:14:56 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	number_of_element(t_h_v *el_po,	char **map)
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				cont++;
			else if (map[i][j] == 'P')
			{
				el_po->ph = i;
				el_po->pv = j;
			}
			j++;
		}
		i++;
	}
	return (cont);
}

void	set_element_position(char **map,	int cont, t_h_v *el_po)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	cont = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				el_po->h[cont] = i;
			if (map[i][j] == 'C')
				el_po->v[cont++] = j;
			if (map[i][j] == 'E')
				el_po->eh = i;
			if (map[i][j] == 'E')
				el_po->ev = j;
			j++;
		}
		i++;
	}
	el_po->h[cont] = -1337;
	el_po->v[cont] = -1337;
}

int	map_data(char **m)
{
	size_t	map_nodes;
	int		cont;
	t_h_v	e_po;

	map_nodes = 0;
	while (m[map_nodes])
		map_nodes++;
	map_nodes = (ft_strlen(m[0]) - 2) * (map_nodes - 2);
	cont = number_of_element(&e_po, m);
	e_po.h = malloc((cont + 1) * sizeof(int));
	if (!e_po.h)
		return (0);
	e_po.v = malloc((cont + 1) * sizeof(int));
	if (!e_po.v)
		return (free(e_po.h), e_po.h = NULL, 0);
	set_element_position(m, cont, &e_po);
	if (player_range(e_po, map_nodes, m) == 0)
	{
		ft_printf("Error\nno valid path in the map.\n");
		return (free(e_po.h), e_po.h = NULL, free(e_po.v), e_po.v = NULL, 0);
	}
	return (free(e_po.h), e_po.h = NULL, free(e_po.v), e_po.v = NULL, 1);
}

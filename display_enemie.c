/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_enemie.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:38:50 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 19:13:42 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemie_patrol(t_vars *v, int i, int j)
{
	int	ve;
	int	h;

	ve = 0;
	h = 0;
	ve = rand() % 3 - 1;
	if (ve == 0)
		h = rand() % 3 - 1;
	if (v->map[i + ve][j + h] == 'P')
	{
		ft_printf("YOU LOST");
		exit(0);
	}
	if (v->map[i + ve][j + h] == '0')
	{
		if (ve == -1)
			v->rd = 1;
		if (ve == 1)
			v->rd = 0;
		v->map[i][j] = '0';
		v->map[i + ve][j + h] = 'R';
	}
}

void	enemie_move(t_vars *v)
{
	static int	l;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (l++ == 30)
	{
		while (v->map[i])
		{
			j = 0;
			while (v->map[i][j])
			{
				if (v->map[i][j] == 'R')
					enemie_patrol(v, i, j);
				j++;
			}
			i++;
		}
		l = 0;
	}
}

int	display_enemie(t_vars *v)
{
	mlx_clear_window(v->mlx, v->win);
	enemie_move(v);
	display(v);
	return (0);
}

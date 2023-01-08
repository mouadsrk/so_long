/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:50:09 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/09 00:15:03 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down_norm(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h + 1][v] == 'E' && vars->c == 0)
	{
		ft_printf("you win");
		exit(0);
	}
	else if (vars->map[h + 1][v] == 'R')
	{
		ft_printf("you lost");
		exit(0);
	}
}

void	move_downp(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;
	char	*n;

	n = ft_itoa(vars->number);
	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h + 1][v] == 'C' || vars->map[h + 1][v] == '0')
	{
		e_p->ph = h + 1;
		if (vars->map[h + 1][v] == 'C')
			vars->c -= 1;
		vars->map[h][v] = '0';
		vars->map[h + 1][v] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		display(vars);
		mlx_string_put(vars->mlx, vars->win, 0, 0, 91422, n);
		free(n);
	}
	else
		move_down_norm(e_p, vars);
}

void	move_down(t_h_v *e_p, t_vars *vars)
{
	int	h;
	int	v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h + 1][v] == '1')
		return ;
	if (vars->map[h + 1][v] == 'E' && vars->c != 0)
		return ;
	vars->number += 1;
	move_downp(e_p, vars);
}

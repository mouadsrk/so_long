/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_upb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:14:23 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 22:54:26 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up_norm(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h - 1][v] == 'E' || vars->c == 0)
	{
		ft_printf("you win");
		exit(0);
	}
	else if (vars->map[h - 1][v] == 'R')
	{
		ft_printf("you lost");
		exit(0);
	}	
}

void	move_upp(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h - 1][v] == 'C' || vars->map[h - 1][v] == '0')
	{
		e_p->ph = h - 1;
		if (vars->map[h - 1][v] == 'C')
			vars->c -= 1;
		vars->map[h][v] = '0';
		vars->map[h - 1][v] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		display(vars);
	}
	else
		move_up_norm(e_p, vars);
}

void	move_upb(t_h_v *e_p, t_vars *vars)
{
	int	h;
	int	v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h - 1][v] == '1')
		return ;
	if (vars->map[h - 1][v] == 'E' && vars->c != 0)
		return ;
	vars->number += 1;
	move_upp(e_p, vars);
}

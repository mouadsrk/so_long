/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:11:38 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 20:32:59 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_leftp(t_h_v *e_p, t_vars *vars)
{
	int		h;
	int		v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h][v - 1] == 'C' || vars->map[h][v - 1] == '0')
	{
		vars->d = 1;
		e_p->pv = v - 1;
		if (vars->map[h][v - 1] == 'C')
			vars->c -= 1;
		vars->map[h][v] = '0';
		vars->map[h][v - 1] = 'P';
		mlx_clear_window(vars->mlx, vars->win);
		display(vars);
	}
	else if (vars->map[h][v - 1] == 'E' && vars->c == 0)
		exit(0);
}

void	move_left(t_h_v *e_p, t_vars *vars, int *number)
{
	int	h;
	int	v;

	h = e_p->ph;
	v = e_p->pv;
	if (vars->map[h][v - 1] == '1')
		return ;
	if (vars->map[h][v - 1] == 'E' && vars->c != 0)
		return ;
	*number += 1;
	ft_printf("move number: %d\n",*number);
	move_leftp(e_p, vars);
}

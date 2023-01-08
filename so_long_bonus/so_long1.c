/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:51:08 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 21:44:25 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	map_extension(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] != 'r' || s[i - 2] != 'e'
		|| s[i - 3] != 'b' || s[i - 4] != '.')
	{
		ft_printf("Error\nthe map must have .ber extension\n");
		return (0);
	}
	return (1);
}

void	so_long(char **av)
{
	int		i;
	t_vars	vars;

	if (!map_extension(av[1]))
		return ;
	vars.map = ft_read(av);
	if (!vars.map)
		return ;
	if (map_quality(vars.map) == 0)
		return ;
	mlx_graphique(&vars);
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 2)
		return (1);
	so_long(av);
}

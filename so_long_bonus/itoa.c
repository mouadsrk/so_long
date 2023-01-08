/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:43:47 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 16:47:45 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	size_t	ft_intlen(long n)
{
	size_t	i;
	size_t	con;

	i = 1;
	con = 1;
	if (n < 0)
	{
		con++;
		n *= -1;
	}
	while ((n / i) >= 10)
	{
		i *= 10;
		con++;
	}
	return (con);
}

char	*ft_itoa(int n)
{
	long	a;
	char	*str;
	size_t	len;

	a = n;
	len = ft_intlen(a);
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	if (a < 0)
	{
		str[0] = '-';
		a *= -1;
	}
	str[len--] = '\0';
	while (a > 0)
	{
		str[len] = (a % 10) + 48 ;
		a /= 10;
		len-- ;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:38:23 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 20:38:27 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hexa(unsigned int i, int len)
{
	char	*t;

	t = "0123456789abcdef";
	if (i <= 15)
		len += ft_putchar(t[i]);
	if (i >= 16)
	{
		len = hexa(i / 16, len);
		len += ft_putchar(t[i % 16]);
	}
	return (len);
}

int	hexaup(unsigned int i, int len)
{
	char	*t;

	t = "0123456789ABCDEF";
	if (i <= 15)
		len += ft_putchar(t[i]);
	if (i >= 16)
	{
		len = hexaup(i / 16, len);
		len += ft_putchar(t[i % 16]);
	}
	return (len);
}

int	hexap(unsigned long long n, int len)
{
	char	*t;

	t = "0123456789abcdef";
	if (n <= 15)
		len += ft_putchar(t[n]);
	if (n >= 16)
	{
		len = hexap(n / 16, len);
		len += ft_putchar(t[n % 16]);
	}
	return (len);
}

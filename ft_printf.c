/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:43:11 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/08 16:43:12 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chrch(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u')
		return (1);
	if (s == 'x' || s == 'X' || s == '%')
		return (1);
	return (0);
}

int	formatype(char s, va_list p, int	*len)
{
	if (s == 'c')
	{
		*len += ft_putchar(va_arg(p, int));
	}
	else if (s == 's')
		*len += ft_putstr(va_arg(p, char *));
	else if (s == 'd' || s == 'i')
		*len = ft_putnbr(va_arg(p, int), *len);
	else if (s == 'u')
	*len = ft_unsignedputnbr(va_arg(p, unsigned int),*len);
	else if (s == 'x')
		*len = hexa(va_arg(p, unsigned int),*len);
	else if (s == 'X')
		*len = hexaup(va_arg(p, unsigned int),*len);
	else if (s == 'p')
	{
		*len += ft_putstr("0x");
		*len = hexap(va_arg(p, unsigned long long), *len);
	}
	return (*len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	char	*ptr;
	va_list	p;
	int		i;

	ptr = (char *) s;
	len = 0;
	va_start (p, s);
	i = 0;
	while (ptr[i])
	{
		if (s[i] == '%' && chrch(s[i + 1]))
		{
			i++;
			if (s[i] == '%')
				len += ft_putchar(ptr[i]);
			else
			len = formatype(ptr[i], p, &len);
		}
		else if (s[i] != '%')
			len += ft_putchar(ptr[i]);
		i++;
	}
	va_end(p);
	return (len);
}

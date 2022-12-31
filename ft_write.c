#include "so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb, int len)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		n *= -1;
		len += ft_putchar('-');
	}
	if (n <= 9)
		len += ft_putchar(n + 48);
	if (n >= 10)
	{
		len = ft_putnbr(n / 10, len);
		len += ft_putchar(n % 10 + 48);
	}
	return (len);
}

int	ft_unsignedputnbr(unsigned int n, int len)
{
	if (n <= 9)
		len += ft_putchar(n + 48);
	if (n >= 10)
	{
		len = ft_putnbr(n / 10, len);
		len += ft_putchar(n % 10 + 48);
	}
	return (len);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write (1, s + i, 1);
		i++;
	}
	return (i);
}
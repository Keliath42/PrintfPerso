/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuythor <kevin.puythorac@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 13:36:18 by kpuythor          #+#    #+#             */
/*   Updated: 2026/11/20 14:44:58 by kpuythor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nb_hexa(unsigned long n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		nb++;
	}
	return (nb);
}

static void	ft_put_hexa_nbr_fd(unsigned long n, int fd, char *base)
{
	char	c;

	if (n < 16)
	{
		c = base[n];
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_put_hexa_nbr_fd(n / 16, fd, base);
		c = base[n % 16];
		ft_putchar_fd(c, fd);
	}
}

int	ft_print_hexa(unsigned long n, char *base, char c)
{
	int	i;

	i = 0;
	if (c == 'p' && n != 0)
		i += ft_print_str("0x");
	else if (c == 'p' && n == 0)
			return (i = ft_print_str("(nil)"));
	i += len_nb_hexa(n);
	ft_put_hexa_nbr_fd(n, 1, base);
	return (i);
}

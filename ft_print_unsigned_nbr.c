/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuythor <kevin.puythorac@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:08:45 by kpuythor          #+#    #+#             */
/*   Updated: 2026/11/18 19:41:32 by kpuythor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nb(unsigned int n)
{
	unsigned int	nb;

	nb = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

static void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		ft_putchar_fd(c, fd);
	}
	else
	{
		ft_put_unsigned_nbr_fd(n / 10, fd);
		c = n % 10 + 48;
		ft_putchar_fd(c, fd);
	}
}

int	ft_print_unsigned_nbr(unsigned int n)
{
	int	i;

	i = len_nb(n);
	ft_put_unsigned_nbr_fd(n, 1);
	return (i);
}

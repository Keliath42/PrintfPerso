/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuythor <kevin.puythorac@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 18:46:42 by kpuythor          #+#    #+#             */
/*   Updated: 2026/11/18 18:56:01 by kpuythor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_nb(int n)
{
	int	nb;

	nb = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nb++;
	while (n != 0)
	{
		n /= 10;
		nb++;
	}
	return (nb);
}

int	ft_print_nbr(int n)
{
	int	i;

	i = len_nb(n);
	ft_putnbr_fd(n, 1);
	return (i);
}

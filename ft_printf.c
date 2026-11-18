/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuythor <kevin.puythorac@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:50:28 by kpuythor          #+#    #+#             */
/*   Updated: 2026/11/18 19:46:07 by kpuythor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(*args, int));
	if (c == 's')
		count = ft_print_str(va_arg(*args, char *));
	if (c == 'd' || c == 'i')
		count = ft_print_nbr(va_arg(*args, int));
	if (c == 'u')
		count = ft_print_unsigned_nbr(va_arg(*args, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
			if (str[i] == '%' && str[i + 1])
		{
			count += ft_format(str[i + 1], &args);
			 i += 2;
		}
		else
		{
		ft_putchar_fd(str[i], 1);
		i++;
		count++;
		}
	}
	va_end(args);
	return (count);
}

#include <stdio.h>
int	main (void)
{
	int i = 0;
	i = ft_printf("Bonjour %s ! Vous avez %u ans !\n", "Kevin", -452);
	printf("%d\n", i);
	return 0;
}

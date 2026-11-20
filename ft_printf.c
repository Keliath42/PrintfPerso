/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuythor <kevin.puythorac@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:50:28 by kpuythor          #+#    #+#             */
/*   Updated: 2026/11/20 14:51:52 by kpuythor         ###   ########.fr       */
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
	if (c == 'x' || 'p')
		count = ft_print_hexa(va_arg(*args, unsigned long), "0123456789abcdef", c);
	if (c == 'X')
		count = ft_print_hexa(va_arg(*args, unsigned long), "0123456789ABCDEF", c);
	if (c == '%')
		count = ft_print_char(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	if (!str)
		return (-1);
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

/*#include <stdio.h>
int	main (void)
{
	int i = 0;
	i = ft_printf("Hexa : %p\n", 0);
	printf("%d\n", i);
	return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:39:28 by aautret           #+#    #+#             */
/*   Updated: 2025/05/28 22:07:05 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_x(char c, unsigned int n)
{
	const char	*table_base;
	int			count;

	count = 0;
	if (c == 'x')
		table_base = "0123456789abcdef";
	else if (c == 'X')
		table_base = "0123456789ABCDEF";
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		count += ft_putnbr_base_x(c, n / 16);
	count += ft_putchar(table_base[n % 16]);
	return (count);
}

int	put_ptr(uintptr_t n)
{
	int	written;
	int	tmp;

	if (n >= 16)
	{
		written = put_ptr(n / 16);
		if (written < 0)
			return (-1);
		tmp = put_ptr(n % 16);
		if (tmp < 0)
			return (-1);
		return (written + tmp);
	}
	if (n <= 9)
		return (ft_putchar('0' + (int)n));
	return (ft_putchar('a' + (int)(n - 10)));
}

int	printf_address(void *ptr)
{
	int	tmp;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") < 0)
		return (-1);
	tmp = put_ptr((uintptr_t)ptr);
	if (tmp < 0)
		return (-1);
	return (2 + tmp);
}

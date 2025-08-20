/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:05:31 by aautret           #+#    #+#             */
/*   Updated: 2025/07/28 11:39:52 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_spec(char c, va_list ap)
{
	return (ft_check_specificator(c, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		n;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
			count += ft_putchar(format[i++]);
		else
		{
			i++;
			n = handle_spec(format[i], ap);
			if (n < 0)
				return (-1);
			count += n;
			i++;
		}
	}
	va_end(ap);
	return (count);
}

int	ft_check_specificator(char spe, va_list ap)
{
	if (spe == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (spe == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (spe == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	if (spe == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (spe == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (spe == 'x')
		return (ft_putnbr_base_x(spe, va_arg(ap, unsigned int)));
	if (spe == 'X')
		return (ft_putnbr_base_x(spe, va_arg(ap, unsigned int)));
	if (spe == 'p')
		return (printf_address(va_arg(ap, void *)));
	if (spe == '%')
		return (ft_putchar('%'));
	return (-1);
}

// int	main(void)
// {
// 	int		ret_ft_printf;
// 	int		ret_printf;
// 	char	*str;
// 	char	*null_str;
// 	void	*ptr;

// 	str = "Hello ft_printf!";
// 	null_str = NULL;
// 	ptr = str;

// 	ret_ft_printf = ft_printf("ft_printf: char       = '%c'\n", 'A');
// 	ret_printf = printf("printf:    char       = '%c'\n", 'A');
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: string     = '%s'\n", str);
// 	ret_printf = printf("printf:    string     = '%s'\n", str);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: null string= '%s'\n", null_str);
// 	ret_printf = printf("printf:    null string= '%s'\n", null_str);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: pointer    = %p\n", ptr);
// 	ret_printf = printf("printf:    pointer    = %p\n", ptr);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: decimal    = %d\n", INT_MAX);
// 	ret_printf = printf("printf:    decimal    = %d\n", INT_MAX);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: integer    = %i\n", -42);
// 	ret_printf = printf("printf:    integer    = %i\n", -42);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: unsigned   = %u\n", 4294967295u);
// 	ret_printf = printf("printf:    unsigned   = %u\n", 4294967295u);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: hex lower  = %x\n", 305441741);
// 	ret_printf = printf("printf:    hex lower  = %x\n", 305441741);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: hex upper  = %X\n", 305441741);
// 	ret_printf = printf("printf:    hex upper  = %X\n", 305441741);
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	ret_ft_printf = ft_printf("ft_printf: percent    = %%\n");
// 	ret_printf = printf("printf:    percent    = %%\n");
// 	ft_printf("Return ft: %d, Return std: %d\n\n", ret_ft_printf, ret_printf);

// 	return (0);
// }

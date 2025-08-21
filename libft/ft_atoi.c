/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:59:43 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 15:03:05 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("ft_atoi : %d\n", ft_atoi("42"));
// 	printf("ft_atoi : %d\n", ft_atoi("-42"));
// 	printf("ft_atoi : %d\n", ft_atoi("0"));
// 	printf("ft_atoi : %d\n", ft_atoi("   42"));
// 	printf("ft_atoi : %d\n", ft_atoi("   -42"));
// 	printf("ft_atoi : %d\n", ft_atoi("   +42"));
// 	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));
// 	return (0);
// }

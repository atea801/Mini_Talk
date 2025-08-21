/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:45:06 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 15:27:04 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len ++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[--len] = nb % 10 + '0';
		nb /= 10;
	}
	return (res);
}
// #include <stdio.h>
// int main(void)
// {
// 	int	nb0 = 0;
// 	int	nb1 = 42;
// 	int	nb2 = -42;
// 	int	nb3 = 123;
// 	int	nb4 = -1232;
// 	int	nb5 = -2147483648;

// 	printf("Le res de %d est %s\n", nb0, ft_itoa(nb0));
// 	printf("Le res de %d est %s\n", nb1, ft_itoa(nb1));
// 	printf("Le res de %d est %s\n", nb2, ft_itoa(nb2));
// 	printf("Le res de %d est %s\n", nb3, ft_itoa(nb3));
// 	printf("Le res de %d est %s\n", nb4, ft_itoa(nb4));
// 	printf("Le res de %d est %s\n", nb5, ft_itoa(nb5));
// 	return (0);
// }

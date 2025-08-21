/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:56:23 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 12:24:38 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	int	c = 2;
// 	int	a = 55;
// 	int	b = 30;

// 	printf("est ce que %d digit ? : %d\n", c, ft_isprint(c));
// 	printf("est ce que %d digit ? : %d\n", a, ft_isprint(a));
// 	printf("est ce que %d digit ? : %d\n", b, ft_isprint(b));
// 	return (0);
// }

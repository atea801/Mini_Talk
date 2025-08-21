/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:10:23 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 12:23:09 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	int	c = '9';
// 	int	a = 'f';
// 	int	b = 30 ;

// 	printf("est ce que %d digit ? : %d\n", c, ft_isdigit(c));
// 	printf("est ce que %d digit ? : %d\n", a, ft_isdigit(a));
// 	printf("est ce que %d digit ? : %d\n", b, ft_isdigit(b));
// 	return (0);
// }

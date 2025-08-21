/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:27:58 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 13:38:07 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// #include <stdio.h>
// int main(void)
// {
// 	int	c = 56;
// 	int	a = 'f';
// 	int	b = 128;

// 	printf("est ce que %d ascii ? : %d\n", c, ft_isalnum(c));
// 	printf("est ce que %d ascii ? : %d\n", a, ft_isalnum(a));
// 	printf("est ce que %d ascii ? : %d\n", b, ft_isalnum(b));
// 	return (0);
// }

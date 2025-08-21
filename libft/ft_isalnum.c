/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:06:01 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 12:01:26 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}

// #include <stdio.h>
// int main(void)
// {
// 	int	c = 56;
// 	int a = 'f';
// 	int b = 2;

// 	printf("est ce que %d alnum ? : %d\n", c, ft_isalnum(c));
// 	printf("est ce que %d alnum ? : %d\n", a, ft_isalnum(a));
// 	printf("est ce que %d alnum ? : %d\n", b, ft_isalnum(b));
// 	return (0);
// }

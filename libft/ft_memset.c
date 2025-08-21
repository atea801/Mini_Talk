/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:46:24 by aautret           #+#    #+#             */
/*   Updated: 2025/04/28 13:48:41 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (n > 0)
	{
		str[i] = (char)c;
		i++;
		n--;
	}
	return (s);
}
/*#include <stdio.h>

int	main(void)
{
	char	p[20];

	ft_memset(p, 67, 5);
	printf("%s\n", p);
	return (0);
}*/

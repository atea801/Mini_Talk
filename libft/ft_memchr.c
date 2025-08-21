/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autret <autret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:33:05 by aautret           #+#    #+#             */
/*   Updated: 2025/05/11 15:03:43 by autret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*p_s == (unsigned char)c)
			return (p_s);
		p_s++;
		n--;
	}
	return (NULL);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Hello, world!";
	char data[] = {'a', 'b', '\0', 'd'};
	char *ptr = ft_memchr(str, 'a', ft_strlen(str));
	char *ptr2 = ft_memchr(data, '\0', 4);

	if (ptr != NULL)
		printf("Trouver : %c a la position %ld\n", *ptr, ptr - str);
	else
		printf("Caractere 'a' non trouver\n");
	if (ptr2 != NULL)
		printf("Octet NULL trouver a la position %ld\n", ptr2 - data);
	return (0);
}*/

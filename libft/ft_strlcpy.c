/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:05:24 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 13:58:40 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (n > 0)
	{
		while (i < n - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	len = ft_strlen(src);
	return (len);
}
/*nclude <stdio.h>

int main(void)
{
	char	src[] = "Bonjour 42";
	char	dest[5];
	size_t	copied;

	copied = ft_strlcpy(dest, src, sizeof(dest));

	printf("Source      : %s\n", src);
	printf("Destination : %s\n", dest);
	printf("Longueur de src : %zu\n", copied);

	return (0);
}*/

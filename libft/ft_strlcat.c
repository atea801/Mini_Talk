/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:26:42 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 16:22:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = ft_strlen(src);
	i = 0;
	while (dest[dest_len] && dest_len < n)
		dest_len++;
	if (dest_len == n)
		return (n + src_len);
	i = 0;
	while (src[i] && dest_len + i < n - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < n)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		printf("ft_strlcat    || %zu\n", ft_strlcat(av[1], av[2], ft_atoi(av[3])));
		printf("ft_strlcat || %zu\n", ft_strlcat(av[1], av[2], ft_atoi(av[3])));
	}
}*/

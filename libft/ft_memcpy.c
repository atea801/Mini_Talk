/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:24:12 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 13:46:47 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dest;
	size_t			i;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
/*#include <stdio.h>

int	main(void)
{
	char	src1[10];
	char	dest1[10];

	ft_memcpy(dest1, src1, 3);
	printf("%s\n", dest1);
	return (0);
}*/

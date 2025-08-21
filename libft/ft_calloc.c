/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:12:42 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 15:04:36 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size && (count * size / size != count))
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, (count * size));
	return (p);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int		*tab;
// 	size_t	count = 7;
// 	size_t	size = sizeof(int);
// 	size_t	i = 0;

// 	tab = ft_calloc(count, size);
// 	if (!tab)
// 	{
// 		printf("Échec de l'allocation\n");
// 		return (1);
// 	}
// 	while (i < count)
// 	{
// 		printf("tab[%zu] = %d\n", i, tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:11:49 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 10:53:30 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <stdio.h>
// #include <string.h>

// int	main(int ac, char **av)
// {
// 	if (ac == 4)
// 	{
// 		printf("strncmp    || %d\n", strncmp(av[1], av[2], ft_atoi(av[3])));
// 		printf("ft_strncmp || %d\n", ft_strncmp(av[1], av[2], ft_atoi(av[3])));
// 	}
// 	return (0);
// }

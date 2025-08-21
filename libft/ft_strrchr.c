/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 12:02:45 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 14:28:01 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	printf("strrchr    || %s\n", strrchr(av[1], atoi(av[2])));
// 	printf("ft_strrchr || %s\n", ft_strrchr(av[1], atoi(av[2])));
// 	return (0);
// }

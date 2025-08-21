/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:07:14 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 15:14:57 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && (i + j) < len && needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>

int	main(void)
{
	const char	*text = "Hello 42 Paris";
	printf("Test 1 : Normal match\n");
    printf("ft_strnstr : %s\n", ft_strnstr(text, "42", 14));

    printf("Test 2 : Hors de la limite\n");
    printf("ft_strnstr : %s\n", ft_strnstr(text, "Paris", 10));

    printf("Test 3 : Needle vide\n");
    printf("ft_strnstr : %s\n", ft_strnstr(text, "", 5));


    printf("Test 4 : Pas trouvé\n");
    printf("ft_strnstr : %s\n", ft_strnstr(text, "Banane", 20));

	return (0);
}*/

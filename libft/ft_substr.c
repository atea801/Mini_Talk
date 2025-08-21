/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 18:10:23 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 15:11:41 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	const char *str = "hello world";

// 	// Cas 1 : Substring normal
// 	printf("Substring (6, 3) : %s\n", ft_substr(str, 6, 5));

//     // Cas 2 : start trop grand
// 	printf("Substring (50, 5) : \"%s\"\n", ft_substr(str, 50, 5));

// 	// Cas 4 : len = 0
// 	printf("Substring (2, 0) : \"%s\"\n", ft_substr(str, 2, 0));

// 	return (0);
// }

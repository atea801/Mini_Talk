/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 18:40:48 by aautret           #+#    #+#             */
/*   Updated: 2025/05/06 18:40:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = (char *)malloc((ft_strlen(s) +1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*#include <stdio.h>

char	map_to_upper(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

int	main(void)
{
	char	*str;

	str = "Bonjour";
	printf("str avant %s\n", str);
	printf("str apres %s\n", ft_strmapi(str, map_to_upper));
	return (0);
}*/

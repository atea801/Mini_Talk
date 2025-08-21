/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:00:10 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 16:15:27 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void	print_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = ft_toupper(*c);
// }

// int	main(void)
// {
// 	char str[] = "hello";

// 	printf("Avant ft_striteri: %s\n", str);
// 	ft_striteri(str, print_upper);
// 	printf("Après ft_striteri: %s\n", str);
// 	return (0);
// }

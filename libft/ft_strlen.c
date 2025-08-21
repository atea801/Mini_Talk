/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:51:47 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 13:39:26 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}
/*#include <stdio.h>

int	main(void)
{
	const char *s;

	s = "Helloworld";
	printf("taille : %zu", ft_strlen(s));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:13:12 by aautret           #+#    #+#             */
/*   Updated: 2025/05/14 13:34:45 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*#include <stdio.h>

int main(void)
{
    char test_chars[] = {'A', 'z', 'G', '9', '#', 'm', 'Z', ' '};
    int size = sizeof(test_chars) / sizeof(test_chars[0]);

    for (int i = 0; i < size; i++)
    {
        char c = test_chars[i];
        int result = ft_isalpha(c);
        printf("ft_isalpha('%c') = %d\n", c, result);
    }
    return (0);
}*/

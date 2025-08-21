/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:46:15 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 11:02:31 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	size_t	count;
	size_t	in_word;
	size_t	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	ft_free_split(char **res, size_t j)
{
	while (j > 0)
		free(res[--j]);
	free(res);
}

static int	ft_extract_word(char **res, char const *s, char c)
{
	size_t			len;
	size_t			i;
	size_t			j;
	unsigned int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			len = i - start;
			res[j] = ft_substr(s, start, len);
			if (!res[j])
				return (ft_free_split(res, j), 0);
			j++;
		}
	}
	res[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_word(s, c);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	if (!ft_extract_word(res, s, c))
		return (NULL);
	return (res);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
// 	char	*str = " Salutalesaamisaea42atous ";
// 	char	sep = 'a';
// 	char	**res = ft_split(str, sep);
// 	int	i = 0;

// 	if (!res)
// 	{
// 		printf("Erreur d’allocation\n");
// 		return (1);
// 	}
// 	while (res[i])
// 	{
// 		printf("mot[%d] = \"%s\"\n", i, res[i]);
// 		i++;
// 	}

// 	i = 0;
// 	while (res[i])
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:27:16 by aautret           #+#    #+#             */
/*   Updated: 2025/05/04 17:50:03 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char	*original = "Hello Libft!";
	char		*copie;

	copie = ft_strdup(original);
	if (!copie)
	{
		printf("Erreur : allocation échouée.\n");
		return (1);
	}

	printf("Chaîne originale : %s\n", original);
	printf("Chaîne dupliquée : %s\n", copie);
	if (original == copie)
		printf("Échec : les pointeurs sont identiques.\n");
	else
		printf("Succès : les pointeurs sont différents.\n");

	free (copie);
	return (0);
}*/

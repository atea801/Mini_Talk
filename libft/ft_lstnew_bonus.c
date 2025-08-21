/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:31:19 by aautret           #+#    #+#             */
/*   Updated: 2025/05/13 16:52:18 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_t;

	new_t = (t_list *)malloc(sizeof(t_list));
	if (!new_t)
		return (NULL);
	new_t -> content = content;
	new_t -> next = NULL;
	return (new_t);
}

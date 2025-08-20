/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:24 by aautret           #+#    #+#             */
/*   Updated: 2025/08/20 19:34:06 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	__pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		write(1, "parametre(s) incorrect(s)", 25);
		exit (0);
	}
	pid = (__pid_t)ft_atoi(av[1]);
	check_pid(pid);
	message = av[2];

}

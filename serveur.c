/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:32 by aautret           #+#    #+#             */
/*   Updated: 2025/08/20 17:10:59 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"
// #include <signal.h>

t_srv	g_srv = {0, 0};

/**
 * @brief identifie le signal USR1/ USR2 et fait une action en en fonctoin du sig
 * agit comme un interupteur
 *
 * @param signum
 */
void	handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "USR1 recu\n", 10);
	else if (signum == SIGUSR2)
		write(1, "USR2 recu\n", 10);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("[serveur] PID: %d\n", getpid());
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

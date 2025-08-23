/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:21 by aautret           #+#    #+#             */
/*   Updated: 2025/08/23 17:43:08 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Configure le handler d'accusé de réception
 */
void	setup_ack_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	send_message(pid_t pid, const char *s)
{
	size_t		len;
	uint32_t	len32;
	size_t		i;

	setup_ack_handler();
	len = 0;
	if (s == NULL)
		len = 0;
	else
		len = ft_strlen(s);
	if (len > UINT32_MAX)
	{
		ft_printf("Message trop long\n");
		exit(1);
	}
	len32 = (uint32_t)len;
	sen_u32_be(pid, len32);
	i = 0;
	while (i < len32)
	{
		send_byte(pid, (unsigned char)s[i]);
		i++;
	}
	wait_for_confirmation();
}

/**
 * @brief
 * - condition 1 : verifie si le pid est pas interdit (-1)
 * ou autre comportement (0)
 *
 * - condition 2 : verifie si on a les autorisations d'y envoyer un signal
 * - ESRCH => le PID n'existe pas
 *
 * = test d'accessibilite et d'exitance du rpocesseur serveur
 *
 *
 * @param pid
 */
void	check_pid(pid_t pid)
{
	if (pid <= 0)
	{
		ft_printf("Veuillez choisir un autre PID !\n");
		exit (1);
	}
	if (kill(pid, 0) == -1)
	{
		if (errno == ESRCH)
		{
			write(2, "Erreur: PID inexistant\n", 23);
			exit(1);
		}
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;

	if (ac != 3)
	{
		write(1, "parametre(s) incorrect(s)", 25);
		exit (0);
	}
	pid = (pid_t)ft_atoi(av[1]);
	check_pid(pid);
	message = av[2];
	ft_printf("Envoi en cours...\n");
	send_message(pid, message);
	ft_printf("Message envoyé!\n");
}

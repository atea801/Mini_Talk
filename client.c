/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:24 by aautret           #+#    #+#             */
/*   Updated: 2025/08/24 21:07:48 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

/**
 * @brief Handler pour recevoir l'accusé de réception du serveur
 */
void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

/**
 * @brief Envoie une chaîne de caractères au serveur via signaux UNIX.
 *
 * La fonction envoie d’abord la longueur de la chaîne
 * (uint32_t en big-endian), puis chaque octet du message.
 * Si la chaîne est NULL, seule une longueur 0 est envoyée.
 *
 * @param pid PID du serveur destinataire.
 * @param s   Chaîne C à transmettre (peut être NULL).
 *
 * @warning Quitte le programme si la taille dépasse UINT32_MAX.
 *
 */
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

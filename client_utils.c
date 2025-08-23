/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:33:46 by aautret           #+#    #+#             */
/*   Updated: 2025/08/23 15:07:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Variable globale pour l'accusé de réception
volatile sig_atomic_t g_ack_received = 0;

/**
 * @brief Handler pour recevoir l'accusé de réception du serveur
 */
void	ack_handler(int signum)
{
	(void)signum;
	g_ack_received = 1;
}

/**
 * @brief Configure le handler d'accusé de réception
 */
void	setup_ack_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);  // Le serveur répond avec SIGUSR1
}


/**
 * @brief transforme un bit en un signal envoye au serveur
 *
 * @param pid
 * @param bit
 */
void	send_bit(pid_t pid, int bit)
{
	if (bit != 1 && bit != 0)
		return ;
	
	// Reset du flag d'accusé de réception
	g_ack_received = 0;
	
	// Envoi du signal
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	
	// Attendre l'accusé de réception du serveur
	while (!g_ack_received)
		pause();  // Suspend jusqu'au signal d'accusé de réception
}

/**
 * @brief transforme un caratere en signal
 *
 * - appel sent_bit pour envoyer chaque bit au serveur sous forme de signal
 * @param pid
 * @param c
 */
void	send_byte(pid_t pid, unsigned char c)
{
	int	i;
	int	bit;

	bit = 0;
	i = 8;
	while (i--)
	{
		bit = ((c >> i) & 1);
		send_bit(pid, bit);
	}
}

/**
 * @brief
 * - n = entier 32 bits non signe
 * - chaque bx correspond a un des 4 octets qui composent n
 *  *
 * @param pid
 * @param len
 */
void	sen_u32_be(pid_t pid, uint32_t len)
{
	uint32_t		n;
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	b0;

	n = len;
	b3 = (n >> 24) & 0xFF;
	b2 = (n >> 16) & 0xFF;
	b1 = (n >> 8) & 0xFF;
	b0 = (n >> 0) & 0xFF;

	send_byte(pid, b3);
	send_byte(pid, b2);
	send_byte(pid, b1);
	send_byte(pid, b0);
}

void	send_message(pid_t pid, const char *s)
{
	size_t		len;
	uint32_t	len32;
	size_t		i;

	// Configuration du handler d'accusé de réception
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

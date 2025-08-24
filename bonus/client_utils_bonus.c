/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:11:05 by aautret           #+#    #+#             */
/*   Updated: 2025/08/24 20:52:17 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;
volatile sig_atomic_t	g_message_confirmed = 0;

/**
 * @brief Handler pour recevoir l'accusé de réception du serveur
 */
void	ack_handler(int signum)
{
	if (signum == SIGUSR1)
		g_ack_received = 1;
	else if (signum == SIGUSR2)
		g_message_confirmed = 1;
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
	g_ack_received = 0;
	if (bit == 0)
		kill(pid, SIGUSR1);
	else if (bit == 1)
		kill(pid, SIGUSR2);
	while (!g_ack_received)
		pause();
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

/**
 * @brief Attend la confirmation finale du serveur
 */
void	wait_for_confirmation(void)
{
	while (!g_message_confirmed)
		pause();
	ft_printf("✅ Message reçu par le serveur !\n");
}

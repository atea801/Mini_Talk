/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:32 by aautret           #+#    #+#             */
/*   Updated: 2025/08/23 15:07:58 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Variable globale - persiste entre les appels du handler
static t_reception	g_srv;

/**
 * @brief Handler principal des signaux SIGUSR1/SIGUSR2
 * Convertit les signaux en bits et route vers les bonnes fonctions
 */
void	simple_handler(int signo)
{
	int	bit;

	if (signo == SIGUSR1)
		bit = 0;
	else if (signo == SIGUSR2)
		bit = 1;
	else
		return ;

	if (g_srv.phase == 0)
		handle_size_bit(&g_srv, bit);
	else if (g_srv.phase == 1)
		handle_content_bit(&g_srv, bit);
}

/**
 * @brief Set the sigactions object
 *
 * - quand on recois le signal SIG1 ou SIG2 on appel sig_handler
 *
 * - c'est "la colle entre le monde des signaux et le code cote serveur"
 *
 */
void	set_sigactions(void)
{
	struct sigaction	sa;

	sa.sa_handler = simple_handler;  // Utiliser un handler simple d'abord
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		_exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		_exit(1);
}


int	main(void)
{
	ft_printf("Serveur PID: %d\n", getpid());

	// Initialisation de l'état de réception
	reset_state(&g_srv);

	// Configuration des handlers de signaux
	set_sigactions();

	// Boucle infinie d'attente des signaux
	while (1)
		pause();

	return (0);
}

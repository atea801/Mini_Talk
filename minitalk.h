/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:28 by aautret           #+#    #+#             */
/*   Updated: 2025/08/20 16:57:17 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include <signal.h> // sigaction, SIGUSR1/2, sigemptyset
# include <unistd.h> //write, pause, getpid
# include <stdlib.h> //exit
# include <stdio.h>

/**
 * @brief État global : 1 globale par programme (regroupe tout dans une struct
 *
 */
typedef struct s_srv
{
	volatile sig_atomic_t	got_usr1;
	volatile sig_atomic_t	got_usr2;
}	t_srv;

/**
 * @brief Déclaration (pas définition) de la globale du serveur
 *
 */
extern t_srv	g_srv;

void	handler(int signum);

#endif

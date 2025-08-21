/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:28 by aautret           #+#    #+#             */
/*   Updated: 2025/08/21 19:57:41 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <sys/types.h>   // pid_t
# include <signal.h>      // struct sigaction, sigaction, sigemptyset, SA_*
# include <unistd.h>      // write, pause, getpid, usleep
# include <stdint.h>      // uint32_t
# include <stdlib.h>      // exit
# include <errno.h>       // errno, ESRCH

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

void	send_bit(pid_t pid, int bit);
void	send_byte(pid_t pid, unsigned char c);
void	sen_u32_be(pid_t pid, uint32_t len);
void	send_message(pid_t pid, const char *s);
void	check_pid(pid_t pid);

#endif

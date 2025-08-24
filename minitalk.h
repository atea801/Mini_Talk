/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:15:28 by aautret           #+#    #+#             */
/*   Updated: 2025/08/24 20:58:43 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define _POSIX_C_SOURCE 200809L
# define _GNU_SOURCE

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>      // struct sigaction, sigaction, sigemptyset, SA_*
# include <sys/types.h>   // pid_t
# include <unistd.h>      // write, pause, getpid, usleep
# include <stdint.h>      // uint32_t
# include <stdlib.h>      // exit
# include <errno.h>       // errno, ESRCH
# include <string.h>      // memset pour ft_bzero

/**
 * @brief Structure de réception pour le serveur
 */
typedef struct s_reception {
	char			*buffer;
	uint32_t		expected_size;
	uint32_t		expected_bits;
	int				phase;
	unsigned char	current_byte;
	uint32_t		index;
	unsigned char	bit_index;
	pid_t			client_pid;
}	t_reception;

/**
 * @brief État global : 1 globale par programme (regroupe tout dans une struct
 */
typedef struct s_srv
{
	volatile sig_atomic_t	got_usr1;
	volatile sig_atomic_t	got_usr2;
}	t_srv;

//CLIENT
extern volatile sig_atomic_t	g_ack_received;

void	send_bit(pid_t pid, int bit);
void	send_byte(pid_t pid, unsigned char c);
void	sen_u32_be(pid_t pid, uint32_t len);
void	send_message(pid_t pid, const char *s);
void	check_pid(pid_t pid);
void	ack_handler(int signum);
void	setup_ack_handler(void);
void	wait_for_confirmation(void);


//SERVEUR
void	advanced_handler(int signo, siginfo_t *info, void *ucontext);
void	set_sigactions(void);

void	reset_state(t_reception *rx);
void	handle_size_bit(t_reception *rx, int bit);
void	flush_byte_if_ready(t_reception *rx);
void	handle_content_bit(t_reception *rx, int bit);

#endif

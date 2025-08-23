/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aautret <aautret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:23:43 by aautret           #+#    #+#             */
/*   Updated: 2025/08/23 15:24:33 by aautret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Réinitialise l'état de la structure de réception.
 *
 * - Cette fonction remet à zéro tous les champs de la structure
 * `t_reception` afin de préparer la réception d'un nouveau message.
 *
 * - Elle libère la mémoire du buffer s'il a été alloué et met
 * les compteurs (taille attendue, bits reçus, index, etc.)
 * dans leur état initial.
 *
 * @param rx Pointeur vers la structure de réception `t_reception`
 * à réinitialiser.
 *
 * @note À appeler après la réception complète d'un message ou en cas d'erreur,
 * pour que le serveur soit prêt à traiter un nouveau message.
 */
void	reset_state(t_reception *rx)
{
	if (rx->buffer != NULL)
	{
		free(rx->buffer);
		rx->buffer = NULL;
	}
	rx->expected_size = 0;
	rx->expected_bits = 0;
	rx->index = 0;
	rx->phase = 0;
	rx->current_byte = 0;
	rx->bit_index = 0;
}

/**
 * @brief Traite un bit reçu pour la phase de récupération de la taille
 *
 * - ajoute le bit reçu (0 ou 1) à la taille attendue (`expected_size`)
 * dans la structure `t_reception`
 *
 * - chaque bit est positionné dans l'ordre correct afin de reconstruire
 * la valeur entière de la taille du message
 *
 * - une fois que le nombre total de bits nécessaire
 * (32 bits pour un entier) a été reçu, la fonction passe la
 * réception à la phase suivante (contenu du message) et alloue
 * dynamiquement le buffer correspondant
 *
 *
 * @param rx
 * @param bit valeur du bit recu 0 || 1
 *
 * @note ftc uniquement utilisee pdt la phase 0 = RECUPERATION DE LA TAILLE
 *
 * - quand la taille est complètement reçue, `state->phase` est mis à 1
 */
void	handle_size_bit(t_reception *rx, int bit)
{
	// Construire l'octet bit par bit (MSB en premier)
	rx->current_byte = (rx->current_byte << 1) | bit;
	rx->bit_index++;

	// Quand on a 8 bits = 1 octet complet
	if (rx->bit_index == 8)
	{
		// Construire la taille en big-endian (décalage + nouvel octet)
		rx->expected_size = (rx->expected_size << 8) | rx->current_byte;
		rx->expected_bits += 8;  // Compter les bits traités

		// Reset pour le prochain octet
		rx->current_byte = 0;
		rx->bit_index = 0;

		// Si on a reçu les 4 octets de la taille (32 bits)
		if (rx->expected_bits == 32)
		{
			// Cas spécial : message vide
			if (rx->expected_size == 0)
			{
				ft_printf("\n");
				reset_state(rx);
				return;
			}

			// Allouer le buffer pour le message (+1 pour \0)
			rx->buffer = malloc(rx->expected_size + 1);
			if (!rx->buffer)
			{
				reset_state(rx);
				return;
			}
			rx->buffer[rx->expected_size] = '\0';

			// Reset pour la phase contenu
			rx->index = 0;
			rx->current_byte = 0;
			rx->bit_index = 0;
			rx->phase = 1;  // Passer à la phase contenu
		}
	}
}

/**
 * @brief Vérifie si un octet complet est prêt et l’ajoute au buffer
 *
 * - regarde si 8 bits ont été reçus dans `current_byte`
 *
 * - Si oui, elle place cet octet dans le buffer du message à la position
 * courante et réinitialise `current_byte` pour continuer la réception
 *
 * @param rx
 *
 * @note Ne fait rien tant que l’octet en cours n’est pas complet
 */
void	flush_byte_if_ready(t_reception *rx)
{
	if (rx->bit_index != 8)
		return ;
	if (rx->index < rx->expected_size)
		rx->buffer[rx->index] = rx->current_byte;
	rx->index++;
	rx->current_byte = 0;
	rx->bit_index = 0;

	if (rx->index == rx->expected_size)
	{
		ft_printf("%s\n", rx->buffer);
		reset_state(rx);
	}
}

/**
 * @brief Ajoute un bit reçu à l’octet en cours de construction
 *
 * - CONSTRUIRE L'OCTET BIT PAR BIT MSB EN PERMIER
 *
 * - Cette fonction est appelée à chaque réception de bit pendant la phase
 * de contenu (phase 1). Le bit est inséré dans `current_byte` à la bonne
 * position.
 *
 * - Quand 8 bits ont été reçus, un octet complet est prêt
 *
 * - La logique d’ajout de cet octet dans le buffer
 * (et la gestion de la fin de message) est déléguée à `flush_byte_if_ready`
 * @param rx
 * @param bit
 */
void	handle_content_bit(t_reception *rx, int bit)
{
	rx->current_byte = (rx->current_byte << 1) | bit;
	rx->bit_index++;

	flush_byte_if_ready(rx);
}

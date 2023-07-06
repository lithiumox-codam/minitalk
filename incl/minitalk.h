/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mdekker <mdekker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/02 00:02:55 by mdekker       #+#    #+#                 */
/*   Updated: 2023/06/18 01:40:26 by mdekker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdbool.h>
# include <unistd.h>

/* -------------------------------------------------------------------------- */
/*                                   Client                                   */
/* -------------------------------------------------------------------------- */

void				client(char **av);
void				send_char(char c);

/**
 * @brief Struct to hold information about the client.
 * 
 * @param pid The pid of the server.
 * @param received Whether the character sent has been received.
 * @param i The current index of the message.
 */
typedef struct s_client
{
	int				pid;
	bool			received;
	int				i;
}					t_client;

/* -------------------------------------------------------------------------- */
/*                                   Server                                   */
/* -------------------------------------------------------------------------- */

/**
 * @brief The buffer size for the server.
 * 
 * The buffer size is 1024 bytes by default.
 * If the message is longer than 1024 bytes, the buffer will be reallocated.
 */
# define BUFF_SIZE 1024

void				server(void);
void				recieve_bit(int sig, siginfo_t *info, void *context);

/**
 * @brief Struct to hold the bit position and the current char.
 *
 * @param bitpos The current bit position.
 * @param c The current char.
 */
typedef struct s_bit
{
	int				bitpos;
	unsigned char	c;
}					t_bit;

/**
 * @brief Struct to hold the message and the index of the current bit.
 *
 * @param buffer The buffer to hold the message. (1024 bytes by default)
 * @param message The final string concatenated from the buffer. (malloced)
 * @param i The index of the current total length of the message.
 */
typedef struct s_server
{
	bool			complete;
	char			*buffer;
	char			*message;
	int				i;
	t_bit			signal;
}					t_server;

#endif

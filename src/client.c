/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:13:03 by dilopez-          #+#    #+#             */
/*   Updated: 2022/08/11 15:24:54 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include "client.h"
#include "ft_printf.h"
#include "ft_utils.h"

void	ft_send_message(char *argv[]);
void	ft_send_message_len(int server_pid, char *message);

int	main(int argc, char *argv[])
{
	if (argc == 3)
		ft_send_message(argv + 1);
	else
		ft_printf("\nInvalid argumends\n\n");
	return (0);
}

void	ft_send_message(char *argv[])
{
	pid_t	server_pid;
	char	*message;
	int		bit_moves;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	bit_moves = 0;
	message = argv[1];
	server_pid = ft_atoi(argv[0]);
	ft_send_message_len(server_pid, message);
	while (message[i])
	{
		while (bit_moves < 8)
		{
			if (((int)message[i] << bit_moves) & 128)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			bit_moves++;
			//pause();
			usleep(42);
		}
		bit_moves = 0;
		i++;
	}
}

void	ft_send_message_len(int server_pid, char *message)
{
	unsigned int	message_len;
	int				bit_moves;

	message_len = 0;
	bit_moves = 0;
	while (message[message_len])
		message_len++;
	while (bit_moves < 32)
	{
		if ((message_len << bit_moves) & 2147483648)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit_moves++;
		usleep(500);
	}
}

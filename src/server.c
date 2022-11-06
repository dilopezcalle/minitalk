/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 10:12:47 by dilopez-          #+#    #+#             */
/*   Updated: 2022/08/11 15:34:58 by dilopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include "server.h"
#include "ft_utils.h"
#include "ft_printf.h"

void	ft_server_handler(int signum/*, siginfo_t *sig_info, void *contex*/);
int		ft_get_message_len(int signum, int *len);

int	main(void)
{
	struct sigaction server_action;

	ft_memset(&server_action, 0, sizeof(server_action));
	sigemptyset(&server_action.sa_mask);
	sigaddset(&server_action.sa_mask, SIGUSR1);
	sigaddset(&server_action.sa_mask, SIGUSR2);
	
	server_action.sa_handler = ft_server_handler;
	
	//server_action.sa_sigaction = ft_server_handler;
	//server_action.sa_flags = SA_SIGINFO;

	ft_printf("\nServer's PID: %d\n\n", getpid());
	sigaction (SIGUSR1, &server_action, 0);
	sigaction (SIGUSR2, &server_action, 0);
	while (1)
	{
		pause();
		//usleep(42);
	}
	return (0);
}

void	ft_server_handler(int signum/*, siginfo_t *sig_info, void *contex*/)
{
	static int	i;
	static char	c;
	static char	*message;
	static int	bit_moves;
	static int	message_len;
	int			len;

	//contex = 0;
	len = 0;
	if (!message)
		len = ft_get_message_len(signum, &message_len);
	if (len && !message)
		message = (char *)malloc(len * sizeof(char));
	else if (message)
	{
		if (signum == SIGUSR1)
			c = (c | 1);
		if (bit_moves < 7)
			c = c << 1;
		bit_moves++;
		//kill(sig_info->si_pid, SIGUSR2);
		if (bit_moves >= 8)
		{
			message[i] = c;
			bit_moves = 0;
			c = 0;
			i++;
		}
		if (i > message_len - 1)
		{
			printf("Message: %s\n", message);
			free(message);
			message = 0;
			message_len = 0;
			i = 0;
		}
	}
}

int		ft_get_message_len(int signum, int *len)
{
	static int	bit_moves;

	if (signum == SIGUSR1)
		*len = (*len | 1);
	if (bit_moves < 31)
		*len = *len << 1;
	bit_moves++;
	if (bit_moves == 32)
	{
		ft_printf("len: %d\n", *len);
		bit_moves = 0;
		return (*len);
	}
	return (0);
}

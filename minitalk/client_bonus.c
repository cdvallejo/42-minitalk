/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:33:24 by cvallejo          #+#    #+#             */
/*   Updated: 2022/09/09 11:31:16 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Para el bonus, el cliente tiene que crear su propia SIGNAL.
// SIGUSR1 para recibir la server-signal de caracter leído.
// SIGUSR2 para recibir la server-signal de str completada.
// La función nueva se ecarga de imprimir el mensaje de las señales.

#include "minitalk.h"

void	ft_transfer_bits(unsigned char octet, int pid_server)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = ((octet >> i) & 1) + '0';
		if (bit == '1')
			kill(pid_server, SIGUSR2);
		else if (bit == '0')
			kill(pid_server, SIGUSR1);
		usleep(100);
	}
}

void	ft_confirmation_of_server(int sig_client)
{
	if (sig_client == SIGUSR1)
		ft_printf("purr,\n");
	else if (sig_client == SIGUSR2)
	{
		ft_printf("\nMiau, string complete");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	size_t	i;
	int		pid_server;

	if (argc != 3 || argv[1] == 0)
	{
		ft_printf("Wrong parameters. Please try again");
		return (0);
	}
	if (argc == 3)
	{
		str = argv[2];
		signal(SIGUSR1, ft_confirmation_of_server);
		signal(SIGUSR2, ft_confirmation_of_server);
		i = 0;
		while (i <= ft_strlen(str))
		{
			ft_transfer_bits(str[i], ft_atoi(argv[1]));
			i++;
		}
		while (1)
			pause();
	}
	return (0);
}

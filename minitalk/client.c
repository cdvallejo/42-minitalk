/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:33:24 by cvallejo          #+#    #+#             */
/*   Updated: 2022/09/09 11:01:36 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1) Primer parámetro: el pid del server. Segundo parámetro: el str
// (que ya sabemos al haberlo escrito previamente al inicializar el server).
// 2) Como nos piden mandar señales, vamos a traducir el str mediante bits,
// conociendo sus 1 y 0. Es decir: sólo enviaremos 
// al server la traducción a bits
// de cada letra, que luego la máquina va transformar en la que sea.
// 3) Por eso, mientras que i no sea igual a la longitud del str,
// realizará un bitwise de cada str[i]: ¿qué ochos '0' ó '1' esconde?
// 4) La función ft_transfer_bits se encargará de realizar el bitwise. 
// Mientra que i = 8 no sea 0,
// recorremos de derecha a izquierda su octeto y lo comparamos con 1
// (sin olvidar el + '0' para convertirlo a caracter). Si es 1,
// mandamos al pid_server SIGUSR2, si es 0 SIGUSR1

#include "minitalk.h"

void	ft_transfer_bits(unsigned char octet, int pid_server)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		if (bit == '1')
			kill(pid_server, SIGUSR2);
		else if (bit == '0')
			kill(pid_server, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	char	*str;
	size_t	i;
	int		pid_server;

	if (argc != 3 || ft_strlen(argv[1]) == 0)
	{
		ft_printf("Wrong parameters. Please try again");
		return (0);
	}
	if (argc == 3)
	{
		str = argv[2];
		i = 0;
		while (i <= ft_strlen(str))
		{
			ft_transfer_bits(str[i], ft_atoi(argv[1]));
			i++;
		}
	}
	return (0);
}

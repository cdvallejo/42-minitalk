/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:33:32 by cvallejo          #+#    #+#             */
/*   Updated: 2022/09/09 10:49:00 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Signals se usa para transmitir señales entre un cliente y un servidor.
//PID es el process identification que un proceso tiene asignado por realizarse.
//Data type: pid_t
//- pid_t getpid (void) -- getpid function returns
//	the process ID of the current process.
//- pid_t gettid (void) -- The gettid function returns
//	the thread ID of the current thread. The returned value is obtained from the
//- kill() function shall send a signal to a process
//	or a group of processes specified by pid.
//En esta versión sin bonus usamos signal, más simple que sigaction.
//- SIGUSR1: User-defined signal 1 // SIGUSR2: User-defined signal 2
//La función getbit_signal recibe las señales de client y compara sus bits
//con los de str (que está a 0). Si recibe 0 simplemente no hará nada porque esa
//posición ya está en 0, reduce i. Y si es 1, escribirá 1 en esa posición.

#include "minitalk.h"

static void	getbit_signal(int octet)
{
	static unsigned char	str = 0;
	static int				pos = 7;

	if (octet == SIGUSR2)
	{
		str += (1 << pos);
		pos--;
	}
	else if (octet == SIGUSR1)
		pos--;
	if (pos < 0)
	{
		if (str == '\0')
		{
			pos = 7;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", str);
		pos = 7;
		str = 0;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_printf("PID server: %d\n", getpid());
		signal(SIGUSR1, getbit_signal);
		signal(SIGUSR2, getbit_signal);
		while (1)
			pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 10:48:15 by cvallejo          #+#    #+#             */
/*   Updated: 2022/09/09 10:48:20 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Para el bonus necesitamos sigaction para poder saber el pid del cliente.
//PID es el process identification que un proceso tiene asignado por realizarse.
//Con struct sigaction configuramos la estructura que va a manejar las señales
//- sa_sigaction The sigaction() system call is used to change the action taken 
//	by a process on receipt of a specific signal.  
//- When the SA_SIGINFO flag is specified in act.sa_flags, the signal
//	handler address is passed via the act.sa_sigaction field.
// This handler takes three arguments:
// 1) The number of the signal that caused invocation of the handler.
// 2) info: a pointer to a siginfo_t, which is a structure containing
// 3) ucontext: This is a pointer to a ucontext_t structure, cast to
//	void *.  The structure pointed to by this field contains
//	signal context information that was saved on the user-space stack 
//	by the kernel

#include "minitalk.h"

static void	getbit_signal(int octet, siginfo_t *info, void *context)
{
	static unsigned char	str = 0;
	static int				pos = 7;
	static pid_t			client_pid = 0;

	if (!client_pid)
		client_pid = info->si_pid;
	if (octet == SIGUSR2)
		str += (1 << pos);
	pos--;
	if (pos < 0)
	{
		if (str == '\0')
		{
			pos = 7;
			ft_printf("\n");
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_printf("%c", str);
		kill(client_pid, SIGUSR1);
		pos = 7;
		str = 0;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	data;

	if (argc == 1)
	{
		ft_printf("PID server: %d\n", getpid());
		data.sa_sigaction = getbit_signal;
		data.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &data, NULL);
		sigaction(SIGUSR2, &data, NULL);
		while (1)
			pause();
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:36:38 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/17 19:03:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	*pipes;
	int	i;

	i = 0;
	if (argc >= 5)
	{
		pipes = step_one(argc, argv);
		if (!pipes)
			return (0);
		if (check_args(argc, argv, envp) != 0)
			exit(0);
		check_fd(pipes);
		pipex(pipes, argc, argv, envp);
		wait(NULL);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			unlink(".tmp");
	}
	else
		ft_putstr_fd("Usage: ./pipex file cmd1 cmd2 .. cmd'n file-out", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:04:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/12 23:34:00 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av,char	**envp)
{
	char	**paths;
	char	*cmds;

	if (ac != 5)
		return(perror("Usage: Pipex input1 cmd1 cmd2 output"), -1);
	paths = get_paths(av,envp);
	pipex(paths, av,envp);
}

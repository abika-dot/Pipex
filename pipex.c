/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:52:45 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/12 23:33:57 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_exec(char	*path, char *cmd,char	**envp, char	*file, int pi)
{
	char	**arv;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd = -1)
	{
		perror("input not found");
		exit(-1)
	}
	dup2(0,fd);
	dup(1,pi)
	arv = ft_split(cmd, ' ');
	if (!arv)
	{
		perror("child buffer fail");
	}
	if (execve(path,arv,envp) == -1)
		perror("child execution fail");
	
}

void	parent_exec(char	*path, char	*cmd, char	**envp,char	*file,int pi)
{
	char	**arv;
	int fd;

	fd = open(file, OCREAT | O_RDWR);
	if (fd < 0)
	{
		perror("couldn't create the file");
		exit(-1);
	}
	arv = ft_split(cmd, ' ');
	if (!arv)
	{
		perror("parent Buffer fail");
		exit(-1);
	}
	dup2(0,pi);
	dup2(1,fd);
	if (execve(path, arv, envp) == -1)
		perror("parent execution fail");
}
int pipex(char	**paths,char	**av,	char	**envp)
{
	int id;
	int filde[2];

	if (pipe(filde) == -1)
	{
		perror("pipe not created");
	}
	id = fork();
	if (id < 0)
	{
		perror("coudnt fork the process");
		exit(-1);
	}
	if (id == 0)
		child_exec(paths[0],av[2],envp, av[1],filde[1]);
	if (id != 0)
		parent_exec(paths[1], av[3], envp,av[4], filde[0]);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:52:45 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/13 15:12:45 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_exec(char	*path, char *cmd, char	**envp, char	*file, int *id)
{
	char	**arv;
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("input not found");
		exit(-1);
	}
	printf("1 child %s \n", path);
	printf("2 child  %s \n", cmd);

	dup2(fd, 0);
	close(fd);
	close(id[0]);
	dup2(id[1], 1);
	arv = ft_split(cmd, ' ');
	if (!arv)
	{
		perror("child buffer fail");
	}
	if (execve(path,arv,envp) == -1)
		perror("child execution fail");
	
}

void	parent_exec(char	*path, char	*cmd, char	**envp,char	*file,int id)
{
	char	**arv;
	int fd;
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	printf("parent %s \n", file);
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
	printf("1 parent %s \n", path);
	printf("2 parent %s \n", arv[0]);
	dup2(fd ,1);
	close(id);
	close(fd);
	if (execve(path, arv, envp) == -1)
		perror("parent execution fail");
}
void pipex(char	**paths,char	**av,	char	**envp)
{
	int id;
	int id2;
	int filde[2];
	int	i;

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
	{
		// close(filde[0]);
		child_exec(paths[0],av[2],envp, av[1],filde);
	}
	close(filde[1]);
	dup2(filde[0], 0);
	// if (pipe(filde) == -1)
	// 	perror("pipe 2 not created");
	id = fork();
	if (id == 0)
	{
		close(filde[1]);
		parent_exec(paths[1],av[3],envp, av[4], filde[0]);
	}
	close(filde[0]);
	close(filde[1]);
	i = 3;
	while (--i)
		waitpid(id, NULL, 0);
	// waitpid(id2,NULL,0);


}

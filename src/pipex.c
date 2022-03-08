/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:27:46 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/08 22:27:30 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/pipex.h"

void check_fd(int *fd)
{
	int i;
	int state;

	state = 0;
	i = 0;
	while (fd[i] != 1000000)
	{
		if (fd[i] < 0)
			state++;
		i++;
	}
	i = 0;
	if (state != 0)
	{
		while (fd[i] != 1000000)
		{
			if (fd[i] > 0)
				close(fd[i]);
			i++;
		}
	ft_putstr_fd("pipe error\n", 1);
	free(fd);
    fd = NULL;
    exit(1);
  
	}
}

int	*step_one(int argc, char	**argv)
{
	int	in_out[2];
	int	*pipes;
	
	if (ft_strncmp(argv[1] , "here_doc", 8) == 0)
	{
		in_out[0] = here_doc(argv[2]);
		in_out[1] = open(argv[argc-1], O_WRONLY | O_APPEND| O_CREAT, 0664);
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		in_out[0] = open(argv[1], O_RDONLY,0664);
		in_out[1] = open(argv[argc-1], O_WRONLY | O_CREAT ,0664);
	}
	pipes = get_pipes(argv, argc,in_out[0], in_out[1]);
    printf("ts one %d %d \n", in_out[0], in_out[1]);
	return (pipes);
}

void	exec_this(int *pipes, int *pip, char	*cmd, char	**envp)
{
	char	*path;
	char	**cnd;

	cnd = ft_split(cmd, ' ');
	if (!cnd)
		{
            ft_putstr_fd("error in ft_split",2);
            exit(1);
        }
        path = get_path(cnd[0], envp);
	if (!path)
		{
            d_free(cnd);
            printf("eror");
            exit(1);
        }
        close_unused_pipes(pipes, pip[0],pip[1]);
	dup2(pip[0],0);
	dup2(pip[1],1);
	execve(path,cnd,envp);
	ft_putstr_fd("command failed to execute", 2);
	exit(1);
}
void	pipex(int	*pipes, int argc, char	**argv, char	**envp)
{
	int	i;
	int fd;
	int k;

	k  = 0;
    i = 2;
	if (ft_strncmp(argv[1] , "here_doc",8 ) == 0)
		i = 3;
    printf("%d \n", i);
	while (i < argc -1)
	{
		fd = fork();
		if (fd == -1)
		{
			ft_putstr_fd("fork error\n",2);
			exit(1);
		}
		if (fd == 0)
			exec_this(pipes,pipes + k, argv[i],envp);
		k += 2;
		i++;
	}
}

int main(int argc, char	**argv,char **envp)
{
	int	*pipes;
    int i;
    i = 0;
	if (argc >= 5)
	{
		pipes = step_one(argc, argv);
        if (!pipes)
            return (0);
		check_fd(pipes);
        while (pipes[i] != 1000000)
            {
                printf("in %d out %d \n", pipes[i],pipes[i+1]);   
            i +=2;
            }
		pipex(pipes, argc,argv,envp);
		wait(NULL);
	}
	else
		ft_putstr_fd("Usage: ./pipex file cmd1 cmd2 .. cmd'n file-out", 1);
}

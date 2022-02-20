/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:24:38 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/17 22:49:34 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
int    exec_that(int *pipes,int in, int out, char *cmd,char  **envp)
{
    char    **command;
    char    *path;
    command = ft_split(cmd,' ');
    if (!command)
        return 1;
    path = get_path(command[0], envp);
    if (!path || !command)
        return 2;
    dup2(in, 1);
    dup2(out,0);
    close_unused_pipes(pipes,in,out);
    execve(path,command,envp); 
}
void case_hand(int exi, char *cmd)
{
    if (exi == 1)
    {
        ft_putstr_fd(cmd,2);
        ft_putstr_fd(": error parsing the command \n",2);
        exit(1);
    }
    else if (exi == 2)
    {
        ft_putstr_fd(cmd, 2);
        ft_putstr_fd(": bin not found \n");
        exit(1);        
    }    
    else if (exi = 3)
    {
        
    }
    
}
void pipex(int argc, char   **argv,char **envp)
{
    int *pipes;
    int exi;
    int id;
    int i;
    int j;
    
    exi = 0;
    i = 2;
    j = 0;
    pipes = get_pipes(argv[1], argv[argc - 1], argc - 4);
    if (!pipes)
        exi = 3;
    while (i < (argc -1))
    {

        id = fork();
        if (id == -1)
        exit(1);
        if (id == 0)
            exi = exec_that(pipes, pipes[j+ 1], pipes[j], argv[i], envp);
        case_hand(exi, argv[i]);
        j += 2;
        i++;
    }
    wait(NULL);
}

int main(int argc , char **argv,char	**envp)
{
    if (argc >= 5)
        pipex(argc, argv,envp);
    else 
        perror("Usage: ./pipex  file_in cmd cmd1 cmd2 cmdn file_out");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:12:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 21:01:26 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    ***cmd_sp(int argc, char    **argv)
{
    char	***test;
	int in;
	int	i;

    in = argc - 3;
    i = 0;
	test = malloc(in * sizeof(char**) + 1);
    if (!test)
        return (NULL);
	test[in] = NULL;
	while (i  != in)
	{
		test[i] = ft_split(argv[2 + i], ' ');
		if (!test)
			return(t_free(test),case_err(2,argv[2 + i]), NULL);
		i++;
	}
    return(test);
}
void  t_free(char ***t_buff)
{ 
  int i;
  i = 0;
  while (t_buff[i])
  {
    d_free(t_buff[i]);
    i++;
  }
  free(t_buff);
}

void	exec_that(t_data *data,int in, int out, int index)
{
    dup2(out, 1);
    dup2(in,0);
    close_unused_pipes(data->pipes,in,out);
    execve(data->paths[index],data->commands[index],data->env);
}
void  case_err(int ex, char *str)
{
  if (ex == 1)
  {
    if(str)
      ft_putstr_fd(str,2);
    exit(1);    
  }  
  if (ex == 2 && str)
    ft_putstr_fd(str, 2);
}

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

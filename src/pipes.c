/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:52:17 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/10 21:49:24 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_unused_pipes(int *pipes, int in, int out)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (pipes[i] != 1000000)
	{
		if (pipes[i] != in && pipes[i] != out)
			close(pipes[i]);
		i++;
	}
}

int	*arrange_pipes(int in, int out, int *pipes, int n_pipes)
{
	int	pip[900][2];
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	j = 1;
	while (i < n_pipes)
	{
		pipe(pip[i]);
		pipes[j] = pip[i][1];
		pipes[j + 1] = pip[i][0];
		j += 2;
		i++;
	}
	pipes[0] = in;
	pipes[j] = out;
	pipes[j + 1] = 1000000;
	return (pipes);
}

int	*get_pipes(char	**argv, int argc, int in, int out)
{
	int	*pipes;

	pipes = NULL;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		pipes = malloc((((argc - 5) * 2) + 3) * sizeof(int));
		if (!pipes)
			return (ft_putstr_fd("fd allcation error\n", 2), NULL);
		pipes = arrange_pipes(in, out, pipes, argc - 5);
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		pipes = malloc((((argc - 4) * 2) + 3) * sizeof(int));
		if (!pipes)
			return (ft_putstr_fd("fd alocation error/n", 2), NULL);
		pipes = arrange_pipes(in, out, pipes, argc - 4);
	}
	return (pipes);
}

char	**d_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (str);
}

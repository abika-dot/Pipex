/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:13:41 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 20:59:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_unused_pipes(int *pipes,int in,int out)
{
	int i;
    int index;
	i = 0;
    index = 0;
	while (pipes[i] != 1000000)
	{
        if (pipes[i] == in)
        index += 1;
        if (pipes[i] == out)
        index += 1;
        if (index == 0)
        {
            close(pipes[i]);
        index--;
        }
    i++;
	}
}
int *arrange_pipes(int in,int out,int *pipes, int n_pipes)
{
    int pip[n_pipes][2];
    int i;
    int j;
    int k;

    k  = 0;
    i = 0;
    j = 1;
    while (i < (n_pipes /2) )
    {
        k = pipe(pip[i]);
        if (k != 0)
        perror("piping error");

		printf("readend %d -- write end %d \n",pip[i][0],pip[i][1]);
        pipes[j] = pip[i][1];
        pipes[j + 1] = pip[i][0];
        j += 2;
        i++;
    }
    pipes[0] = in;
    pipes[n_pipes + 1] = out;
	pipes[n_pipes + 2] = 1000000;
	return (pipes);
}

int *get_pipes(char	**argv, int argc)
{
    int in;
    int out;
    int *pipes;

    pipes = malloc(((argc - 4) * 2)  * sizeof(char) + 2);
    if (!pipes)
        perror("Buffer error");
    in = open(argv[1], O_RDONLY);
    if (!in)
        perror("file 1 doesnt exist");
    out = open(argv[argc - 1], O_WRONLY | O_CREAT, 0664);
    if (!out)
        perror("coudnt creat file");
    pipes = arrange_pipes(in,out,pipes,(argc - 4) * 2);
    return pipes;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:58:06 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/17 22:35:31 by ozahir           ###   ########.fr       */
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
        printf("%d \n",i);
        k = pipe(pip[i]);
        if (k != 0)
        perror("piping error");
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

int *get_pipes(char    *in_file, char  *out_file, int n_pipes)
{
    int in;
    int out;
    int *pipes;
    
    pipes = malloc((n_pipes * 2)  * sizeof(char) + 2);
    if (!pipes)
        perror("Buffer error");
    in = open(in_file, O_RDONLY);
    if (!in)
        perror("file 1 doesnt exist");
    out = open(out_file, O_WRONLY | O_CREAT, 0664);
    if (!out)
        perror("coudnt creat file");
    pipes = arrange_pipes(in,out,pipes,n_pipes * 2);
    return pipes;
}


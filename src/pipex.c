/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:52:45 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/10 23:52:26 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
void pipex(char	*fst_cmd,char *sec_cmd , char	**av)
{
	int id;
	id = fork();
	if (id == -1)
		perror("coudn't fork the prosses");
	if (id != 0)
	{
		wait();
	}
	
}

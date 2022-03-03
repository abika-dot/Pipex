/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:31:54 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/04 00:45:31 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_args(int	argc, char	**argv, char **envp)
{
	int i; 

	i = 0;
	if (argc < 5)
		return (0);
	while (i < argc -1)
	{
		if (!argv[i])
			return (ft_putstr_fd("a parameter is wrong\n", 1), exit(1), 0);
		i++;
	}
	if (!envp)
		return	(ft_putstr_fd("envp is not valid \n",1), exit(1), 0);
	return (1);
}

int	main(int argc, char	**argv, char	**envp)
{
	int	index;
	int	in;
	int out;

	index = 0;
	if	(check_args(argc,argv,envp))
	{
		if (ft_strncmp(argv[1], "here_doc"))
		
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:16:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/12 23:34:04 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	*get_env(char	**envp,char	*cmd)
{
	int		i;
	char	**envirment;
	char	*env;

	i = 0;
	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=",5) == 0)
				break ;
		i++;
	}
	envirement = ft_split(envp[i] + 5 , ";");
	if (!envirement)
		return (NULL);
	env  = check_path(cmd,envirement)
	do_free(enviremet);
	return (env);
}

char	**get_paths(char **av, char **envp)
{
	char	**paths;

	paths = malloc(3 * sizeof(char	*));
	if (!paths)
		return NULL;

	paths[0] = get_env(envp, av[2]);
	if (paths[0] == NULL)
	{
		do_free(paths);
		perror("cmd1 not found");
		exit(-1);
	}
	paths[1] = get_env(envp,av[3]);
	if (paths[1] == NULL)
	{
		do_free(paths);
		perror("cmd2 not found");
		exit(-1)
	}
	paths[2] = NULL;
	return(paths);
}

char	*chack_path(char	*cmd,	char	**envirement)
{
	char	*to_check;
	int	i;

	i = 0;
	while (envirement[i])
	{
		to_check = plus_strjoin(envirement[i],cmd);
		if (!to_check)
			return NULL;
		if (acces(to_check, X_OK) == 0)
			return (to_check);
		free(to_check);
	i++;
	}
	return (NULL);
}

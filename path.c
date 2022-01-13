/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:16:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/13 15:13:56 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

char	*get_env(char	**envp,char	*cmd)
{
	int		i;
	char	**envi;
	char	*env;

	i = 0;
	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=",5) == 0)
				break ;
		i++;
	}
	envi = ft_split(envp[i] + 5 , ';');
	if (!envi)
		return (NULL);
	env  = check_path(cmd,envi);
	do_free(envi);
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
		exit(-1);
	}
	paths[2] = NULL;
	return(paths);
}

char	*check_path(char	*cmd,	char	**envirement)
{
	char	*to_check;
	int	i;

	i = 0;
	while (envirement[i])
	{
		to_check = plus_strjoin(envirement[i],cmd,'/');
		if (!to_check)
			return NULL;
		if (access(to_check, X_OK) == 0)
			return (to_check);
		free(to_check);
	i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (dstsize == 0)
		return (count);
	while (src[i] && dstsize != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

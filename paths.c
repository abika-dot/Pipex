/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:11:08 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 02:12:14 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **bin_path(char  **envp)
{
    int		i;
	char	**envi;

	i = 0;
	while(envp[i])
	{
		if(ft_strncmp(envp[i], "PATH=",5) == 0)
				break ;
		i++;
	}
	envi = ft_split(envp[i] + 5 , ':');
	if (!envi)
		return (NULL);
	return (envi);
}
char    *path_join(char const *s1, char const *s2, int c)
{
    char    *ss;
    int        ln1;
    int        ln2;
    int        j;

    j = 0;
    if (!s1 || !s2)
        return (NULL);
    ln1 = ft_strlen(s1);
    ln2 = ft_strlen(s2);
    ss = malloc((ln1 + ln2) * sizeof(char) + 2);
    if (!ss)
        return (NULL);
	ft_memcpy(ss, s1, ln1);
    ss[ln1] = c;
    ln1++;
    while (s2[j])
    {
        ss[ln1 + j] = s2[j];
        j++;
    }
    ss[ln1 + ln2] = 0;
    return (ss);
}

char    *get_path(char  *cmd, char **path_key)
{
    char    *path;
	int i;

	i = 0;
    while (path_key[i])
    {
        path = path_join(path_key[i],cmd, '/');
        if (!path)
        return  NULL;
        if (access(path, X_OK) == 0)
             return path;
        free(path);
        i++;
    }
    return NULL;
}

char	**path_checker(char	***commands,char	**envp)
{
	int  i;
	char	**paths;
	char	**c_paths;

	i = 0;
	paths = bin_path(envp);
	if (!paths)
		return NULL;
	while(commands[i])
		i++;
	c_paths = malloc(i * sizeof(char	*) + 1);
	if (!c_paths)
		return NULL;
	c_paths[i] = NULL;
	i = 0;
	while(commands[i])
	{
		c_paths[i] = get_path(commands[i][0], paths);
		printf("%s\n", c_paths[i]);
		if (!c_paths[i])
			return(d_free(c_paths), d_free(paths) ,case_err(2 , commands[i][0]),NULL);
		i++;
	}
	d_free(paths);
	return (c_paths);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:19:53 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/17 22:49:40 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
char    *get_path(char  *cmd, char **envp)
{
    char    **path_key;
    char    *path;

    int i;
    i = 0;
    path_key = bin_path(envp);
    if (!path_key)
        {
            perror("coudn't parse the envp");
            exit(1);
        }
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
    perror("command not found");
    return NULL;
}

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


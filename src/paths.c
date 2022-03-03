/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:19:37 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/28 16:02:55 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_bins(char	**envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*get_path(char	*cmd, char	**envp)
{
	char	*paths;

	paths = bin_path(cmd, get_bins(envp));
	return (paths);
}

char	*bin_path(char	*cmd, char	**paths)
{
	int		i;
	char	*path;

	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		path = path_join(paths[i], cmd, '/');
		if (!path)
			return (NULL);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*path_join(char const *s1, char const *s2, int c)
{
	char	*ss;
	int		ln1;
	int		ln2;
	int		j;

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

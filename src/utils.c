/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:16:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/10 23:52:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	do_free(char	**to_free)
{
	int i;

	i = 0;
	while(to_free[i])
		i++;
	i--;
	while(i != 0)
	{
		free(to_free[i]);
		i--;
	}
	free(to_free);
}
char	*path_join(char const *s1, char const *s2)
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
	ss = malloc((ln1 + ln2) * sizeof(char) + 1);
	if (!ss)
		return (NULL);
	ft_memcpy(ss, s1, ln1);
	ss[ln1] = "/";
	j++;
	while (s2[j])
	{
		ss[ln1 + j] = s2[j];
		j++;
	}
	ss[ln1 + ln2] = 0;
	return (ss);
}
char	*get_path(char **envp,char	*cmd)
{
	int i;
	int j;
	char	*cnd;
	char **path;
	
	i = 0;
	j = 0;
	while(envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break;
		i++;
	}
	if (envp[i] == NULL)
		perror("PATH variable  not found");
	path = ft_split(envp[i] + 5, ":");
	while (path[j])
	{
		cnd = path_join(path[j],cmd);
	   if (access(cnd, X_OK) == 0)
	   	return(do_free(path), cnd);
	   i++;
	   free(cnd);
	}
	free(cnd)
	do_free(path);
	return NULL;
}

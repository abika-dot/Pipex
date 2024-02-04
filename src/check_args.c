/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 02:01:54 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/17 19:06:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check_args(int argc, char **argv, char **envp)
{
	int		i;
	char	*path;
	char	**cmd;

	i = 2;
	if (!envp[0])
		return (write(1, "env is not valid\n", 18));
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	while (i < argc - 1)
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
			return (write(1, "command is NULL\n", 16));
		path = get_path(cmd[0], envp);
		if (!path)
		{
			unlink(".tmp");
			return (d_free(cmd), write(1, "cmd not found\n", 18));
		}
		free(path);
		d_free(cmd);
		i++;
	}
	return (0);
}

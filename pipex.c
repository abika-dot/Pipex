/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:14:18 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 02:14:31 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void pipex(t_data *data,int argc,char **argv)
{
	int i;
	int j;
	int id;

	j = 0;
	i = 0;
    data->pipes = get_pipes(argv,argc);
    if (!data->pipes)
        case_err(1, "Error creating pipes");
    while(data->paths[i])
    {
		if (data->paths[i] == NULL)
			exit(1);
        id = fork();
        if (id == -1)
        exit(1);
        if (id == 0)
			exec_that(data,data->pipes[j + 1],data->pipes[j],i);
        j += 2;
		i++;
    }
    wait(NULL);
	t_free(data->commands);
	d_free(data->paths);
}
int  main(int  argc, char	**argv,char	**envp)
{
	t_data *data;

	if (argc	>= 5)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			case_err(1, "error data");
		data->commands = cmd_sp(argc,argv);
		if (!data->commands)
			case_err(1,": error parsing");
		data->paths = path_checker(data->commands,envp);
		if (!data->paths)
		case_err(1,": Not found");
		data->env = envp;
		pipex(data,argc,argv);
	}
	else
		ft_putstr_fd("Usage; ./pipex filein cmd  ... cmdn  fileout",1);

}

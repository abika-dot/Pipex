/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:04:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/10 23:52:18 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int ac, char **av,char	**envp)
{
	char	*a_path1;
	char	*a_path2;

	a_path1 = get_path(envp,av[2]);
	if (!a_path1)
		return(perror("first command Not found"));
	a_path2 =get_path(envp,av[3]);
	if (!a_path2)
		return(perror("second command not found "));
	pipex(a_path1,a_path2,av);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:53:23 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/04 00:49:06 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void free_list(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while(!tmp)
	{
		free(data->text);
		tmp = data->next;
		free(data);
		data = tmp;
	}
}
int	write_to_tmp(t_data *data)
{
	t_data	*temp;
	int file;

	if (!data)
		return (0);
	file = open("tmp", O_WRONLY | O_CREAT,0664);
	temp = data;
	while (data->next != NULL)
	{
		ft_putstr_fd(data->text, file);
		data = data->next;
	}
	free_list(temp);
	close(file);
	file = open("tmp", O_RDONLY , 0664);
	return file;
}

int	here_doc(char	*delimiter)
{	
	t_data	*temp;
	t_data	*lines;
	int fd;

	lines = malloc(sizeof(t_data));
	if (!lines)
		return 0;
	temp = lines;
	while(1)
	{
		write(1,"heredoc>",8);
		lines->text = get_next_line(0);
		if (lines->text == NULL ||
			   	(ft_strlen(lines->text) -1  == ft_strlen(delimiter)  &&
				 ft_strncmp(lines->text, delimiter, ft_strlen(delimiter) ) == 0))
			break ;
		lines->next = malloc(sizeof(t_data));
		lines = lines->next;
		if (!lines)
			return (free_list(temp), 0);
	}
	lines->next = NULL;
	fd = write_to_tmp(temp);
	return (fd);
}

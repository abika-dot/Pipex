/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:41:21 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/13 15:14:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	do_free(char	**to_free);
char    *plus_strjoin(char const *s1, char const *s2, int c);
char	*get_env(char	**envp,char	**cmd);
char	**get_paths(char **av, char **envp);
char	*check_path(char	*cmd,	char	**envirement);
void	child_exec(char	*path, char *cmd,char	**envp, char	*file, int *id);
void	parent_exec(char	*path, char	*cmd, char	**envp,char	*file,int id);
void pipex(char	**paths,char	**av,	char	**envp);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif

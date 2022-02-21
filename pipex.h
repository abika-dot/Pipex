/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:14:57 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 02:15:34 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

typedef struct t_data{
  int 	*pipes;
  char	**paths;
  char	***commands;
  char	**env;
} t_data;

size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	d_free(char	**l_str);
char    ***cmd_sp(int argc, char    **argv);
void  exec_that(t_data *data,int in, int out, int index);
char	**ft_split(char const *s, char c);
char    **bin_path(char  **envp);
char    *path_join(char const *s1, char const *s2, int c);
char	**path_checker(char	***commands,char	**envp);
void	close_unused_pipes(int *pipes,int in,int out);
int *arrange_pipes(int in,int out,int *pipes, int n_pipes);
int *get_pipes(char	**argv, int argc);
void pipex(t_data *data,int argc,char **argv);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void  t_free(char ***t_buff);
void  case_err(int ex, char *str);
void	ft_putstr_fd(char *s, int fd);
char	**freed(char **spl);
int	rows(const char *s, char c);
char	**alocation(char **spl, const char *s, char c);
char	**endl(char **spl, const char *s, char c);



#endif

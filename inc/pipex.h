/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <ozahir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:54:57 by ozahir            #+#    #+#             */
/*   Updated: 2022/03/17 19:04:44 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct s_data
{
	char			*text;
	struct s_data	*next;
}	t_data;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(char const *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*newline(char *left);
int		nl_sig(char *str);
char	*get_next_line(int fd);
char	*rest(char	*rest);
char	*binary_path(char	*cmd, char	**paths);
char	**ft_split(char const *s, char c);
void	close_unused_pipes(int *pipes, int in, int out);
char	**d_free(char **str);
char	*get_path(char	*cmd, char	**envp);
int		*get_pipes(char	**argv, int argc, int in, int out);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		here_doc(char	*delimiter);
char	*path_join(char const *s1, char const *s2, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		check_args(int argc, char **argv, char **envp);
void	check_fd(int *fd);
void	pipex(int *pipes, int argc, char **argv, char **envp);
int		*step_one(int argc, char **argv);
#endif

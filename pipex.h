#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
char	**ft_split(char const *s, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char    **free_t(unsigned int i, char **tab);
char    *path_join(char const *s1, char const *s2, int c);
char    *get_path(char  *cmd, char **envp);
char    **bin_path(char  **envp);
int *arrange_pipes(int in,int out,int *pipes, int n_pipes);
int *get_pipes(char    *in_file, char  *out_file, int n_pipes);
void    exec_that(int *pipes,int in, int out, char *cmd,char  **envp);
void pipex(int argc, char   **argv, char **envp);
void	close_unused_pipes(int	*pipes,int	in,int	out);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 02:06:35 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/21 02:11:02 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ddst;
	char	*ssrc;
	int		i;

	if (!dst && !src)
		return (NULL);
	ddst = (char *)dst;
	ssrc = (char *)src;
	i = 0;
	while (n)
	{
		ddst[i] = ssrc[i];
		n--;
		i++;
	}
	return ((void *)(dst));
}
void	d_free(char	**l_str)
{
	int i;
	i = 0;
	while(l_str[i])
	{
		free(l_str[i]);
		i++;
	}
	free(l_str);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (src[count])
		count++;
	if (dstsize == 0)
		return (count);
	while (src[i] && dstsize != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}
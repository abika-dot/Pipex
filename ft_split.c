/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 03:06:00 by ozahir            #+#    #+#             */
/*   Updated: 2022/02/19 20:16:43 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

static int	count_words(const char *s, char c)
{
	size_t	i;
	size_t	compt;

	i = 0;
	compt = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != c && s[i])
		{
			compt++;
		}
		while (s[i] != c && s[i])
		{
			i++;
		}
	}
	return (compt);
}

static char	*this(const char *s, char c)
{
	size_t	i;
	char	*tab;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
	{
		return (NULL);
	}
	ft_strlcpy (tab, s, i + 1);
	return (tab);
}

char	**free_t(unsigned int i, char **tab)
{
	while (i > 0)
	{
		free(tab[i--]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	length;
	char	**tab;

	if (!s)
		return (NULL);
	length = count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (length + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < length)
	{
		while (s[0] == c)
		{
			s++;
		}
		tab[i] = this(s, c);
		if (tab[i] == NULL)
			return (NULL);
		s = s + ft_strlen(tab[i]);
	}
	tab[i] = 0;
	return (tab);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:44:28 by ozahir            #+#    #+#             */
/*   Updated: 2022/01/12 23:34:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	do_free(char	**to_free)
{
	int	i;

	i = 0;
	if (!to_free)
		return ;
	while (to_free[i])
			i++;
	i--;
	while (i >= 0)
	{
		free(to_free[i]);
		i--;
	}
}

char    *plus_strjoin(char const *s1, char const *s2, int c)
{
    char    *ss;
    int        ln1;
    int        ln2;
    int        j;

    j = 0;
    if (!s1 || !s2)
        return (NULL);
    ln1 = ft_strlen(s1);
    ln2 = ft_strlen(s2);
    ss = malloc((ln1 + ln2) * sizeof(char) + 2);
    if (!ss)
        return (NULL);
	ft_memcpy(ss, s1, ln1);
    ss[ln1] = c;
    ln1++;
    while (s2[j])
    {
        ss[ln1 + j] = s2[j];
        j++;
    }
    ss[ln1 + ln2] = 0;
    return (ss);
}

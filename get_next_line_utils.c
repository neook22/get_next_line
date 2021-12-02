/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:55:55 by sjeuneje          #+#    #+#             */
/*   Updated: 2021/12/02 10:37:22 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joiner;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joiner = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (joiner == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joiner[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		joiner[i] = *s2;
		i++;
		s2++;
	}
	joiner[i] = '\0';
	return (joiner);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	int		i;

	s1_cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (s1_cpy == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		s1_cpy[i] = *s1;
		i++;
		s1++;
	}
	s1_cpy[i] = '\0';
	return (s1_cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len <= 0)
		return (ft_strdup(""));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			substr[j++] = s[i];
	}
	substr[j] = '\0';
	return (substr);
}

int	ft_check_n(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos] && s[pos] != (char)c)
		pos++;
	if (s[pos] == '\0')
		return (-1);
	return (pos);
}

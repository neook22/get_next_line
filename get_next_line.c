/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:18:33 by sacha             #+#    #+#             */
/*   Updated: 2021/12/02 10:48:22 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_rest(char **rest)
{
	free(*rest);
	*rest = NULL;
}

char	*ft_test_ret_read(char **rest, int ret_read)
{
	char	*line;
	char	*tmp;

	if (**rest == '\0')
	{
		free(*rest);
		return (NULL);
	}
	else if (ret_read == 0)
	{
		line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	else
	{
		line = ft_substr(*rest, 0, ft_check_n(*rest, '\n') + 1);
		tmp = ft_substr(*rest, ft_check_n(*rest, '\n') + 1, ft_strlen(*rest));
		free(*rest);
		*rest = tmp;
	}
	return (line);
}

int	ft_get_next_line_helper(char **rest, int ret_read, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*tmp;

	ret_read = read(fd, buf, BUFFER_SIZE);
	if (ret_read < 0)
	{
		free(*rest);
		return (ret_read);
	}
	buf[ret_read] = '\0';
	if (ret_read == 0)
		return (ret_read);
	tmp = ft_strjoin(*rest, buf);
	free(*rest);
	*rest = tmp;
	return (ret_read);
}

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	int			ret_read;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	if (!rest)
	{
		rest = malloc(1);
		if (!rest)
			return (NULL);
		*rest = '\0';
	}
	ret_read = 1;
	while (ft_check_n(rest, '\n') == -1)
	{
		ret_read = ft_get_next_line_helper(&rest, ret_read, fd);
		if (ret_read < 0)
			return (NULL);
		else if (ret_read == 0)
			break ;
	}
	return (ft_test_ret_read(&rest, ret_read));
}

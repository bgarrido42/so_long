/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:04:56 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/05 16:42:52 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gnl.h"

static int	len(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*joinstr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*n_str;

	n_str = (char *)malloc(sizeof(char) * (len(s1, 0) + len(s2, 0) + 1));
	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = 0;
	}
	while (s1[++i])
		n_str[i] = s1[i];
	while (s2[++j])
		n_str[i + j] = s2[j];
	n_str[i + j] = 0;
	free(s1);
	return (n_str);
}

static char	*cutstr(char *str, int start, int len, int on)
{
	int		i;
	char	*n_str;

	i = 0;
	if (on && !ft_strchr(str, 10))
	{
		free(str);
		return (NULL);
	}
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	while (str[start + i] && i < len)
	{
		n_str[i] = str[start + i];
		i++;
	}
	n_str[i] = 0;
	if (on)
		free(str);
	return (n_str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*kept;
	int			size;

	if (fd == -1 || fd == 2)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (1024 + 1));
	size = 1;
	while (size && !ft_strchr(kept, 10))
	{
		size = read(fd, buff, 1024);
		if (size < 0)
			return (ft_free_buff(buff));
		buff[size] = 0;
		kept = joinstr(kept, buff);
	}
	free(buff);
	buff = cutstr(kept, 0, len(kept, 10) + 1, 0);
	kept = cutstr(kept, len(buff, 0), len(kept, 0) - len(buff, 0), 1);
	if (!size && !len(buff, 0))
	{
		free(buff);
		return (NULL);
	}
	return (buff);
}

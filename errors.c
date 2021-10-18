/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <bgarrido@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:42:30 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:28:15 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_check_objs(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
				map->min_x++;
			else if (map->map[y][x] == 'C')
				map->min_c++;
			else if (map->map[y][x] == 'E')
				map->min_e++;
			x++;
		}
		y++;
	}
	if (map->min_x != 1 || map->min_c < 1 || map->min_e < 1)
		return (0);
	else
		return (1);
}

int	ft_check_borders(t_map *map)
{
	int	x;
	int	x_first;
	int	y;

	y = 0;
	x_first = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			x++;
		}
		if (y == 0)
			x_first = x;
		else if (x != x_first)
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_box(t_map *map)
{
	int		fd;
	int		x;
	int		y;
	int		first_x;
	char	*buff;

	fd = open(map->argv, O_RDONLY);
	y = 1;
	first_x = 0;
	buff = get_next_line(fd);
	while (buff)
	{
		x = 0;
		while (buff[x])
			x++;
		if (buff[x] == '\n' || buff[x] == '\0')
			x -= 1;
		if (y == 1)
			first_x = x;
		else if (first_x != x)
			return (0);
		y++;
		buff = get_next_line(fd);
	}
	return (1);
}

void	ft_free_map(t_map *map)
{
	int	argc;

	argc = 0;
	while (argc <= map->y)
	{
		free(map->map[argc]);
		argc++;
	}
	free(map->map);
}

void	ft_close_error(void)
{
	ft_printf("File not found\n");
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <bgarrido@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:03:20 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:28:30 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static int	ft_get_map_width(char *buffer)
{
	int	x;

	x = 0;
	while (buffer[x])
	{
		x++;
	}
	return (x - 1);
}

static int	ft_get_map_heigth(int fd)
{
	int	y;

	y = 1;
	while (get_next_line(fd))
		y++;
	return (y);
}

static void	ft_malloc_map(t_map *map)
{
	int	x;

	x = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	while (x <= map->y)
	{
		map->map[x] = (char *)malloc(sizeof(char) * (map->x + 1));
		x++;
	}
}

static void	ft_fill_buffer(char *src, t_map *map)
{
	char	*buff;
	int		x;
	int		y;
	int		fd;

	y = 0;
	fd = open(src, O_RDONLY);
	while (y < map->y)
	{
		buff = get_next_line(fd);
		x = 0;
		while (x < map->x)
		{
			map->map[y][x] = buff[x];
			x++;
		}
		map->map[y][x] = '\0';
		y++;
	}
	map->map[y] = NULL;
	close(fd);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		fd;
	char	*buffer;

	if (argc == 2)
	{
		ft_map_init(&map);
		map.argv = argv[1];
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_close_error();
		buffer = get_next_line(fd);
		map.x = ft_get_map_width(buffer);
		map.y = ft_get_map_heigth(fd);
		ft_malloc_map(&map);
		close(fd);
		ft_fill_buffer(argv[1], &map);
		ft_check_errors(&map);
		ft_define_img_route(&map);
		ft_create_map(&map);
	}
	else
		ft_printf("Wrong args\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:29:44 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 09:42:11 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

void	ft_find_player(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->old_x = x;
				map->old_y = y;
			}
			if (map->map[y][x] == 'C')
				map->t_c++;
			x++;
		}
		y++;
	}
}

void	ft_map_init(t_map *map)
{
	map->y = 0;
	map->x = 0;
	map->old_x = 0;
	map->old_y = 0;
	map->new_x = 0;
	map->new_y = 0;
	map->t_c = 0;
	map->c_c = 0;
	map->min_x = 0;
	map->min_c = 0;
	map->min_e = 0;
	map->movements = 0;
}

void	ft_end_game(t_map *map)
{
	map->map[map->new_y][map->new_x] = 'P';
	map->map[map->old_y][map->old_x] = '0';
	map->old_y = map->new_y;
	map->old_x = map->new_x;
	mlx_destroy_window(map->mlx, map->win);
	exit(1);
}

int	ft_close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(1);
	return (0);
}

void	ft_check_errors(t_map *map)
{
	int	min_objs;
	int	closed;
	int	boxed;

	min_objs = ft_check_objs(map);
	closed = ft_check_borders(map);
	boxed = ft_check_box(map);
	if (!min_objs || !closed || !boxed)
	{
		ft_printf("MAP ERROR");
		ft_free_map(map);
		exit(1);
	}
}

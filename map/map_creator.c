/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:28:46 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:08:45 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_define_img_route(t_map *map)
{
	map->chest = ft_strdup("./Assets/Chest.xpm");
	map->wall = ft_strdup("./Assets/Wall.xpm");
	map->door = ft_strdup("./Assets/Door_closed.xpm");
	map->hero = ft_strdup("./Assets/Hero.xpm");
	map->floor = ft_strdup("./Assets/Floor.xpm");
}

static void	ft_print_obj(t_map *m)
{
	m->i_f = mlx_xpm_file_to_image(m->mlx, m->floor, &m->i_x, &m->i_y);
	m->i_w = mlx_xpm_file_to_image(m->mlx, m->wall, &m->i_x, &m->i_y);
	m->i_h = mlx_xpm_file_to_image(m->mlx, m->hero, &m->i_x, &m->i_y);
	m->i_c = mlx_xpm_file_to_image(m->mlx, m->chest, &m->i_x, &m->i_y);
	m->i_d = mlx_xpm_file_to_image(m->mlx, m->door, &m->i_x, &m->i_y);
}

static void	ft_loop_content(t_map *m, int x, int y)
{
	mlx_put_image_to_window(m->mlx, m->win, m->i_f, x * 50, y * 50);
	if (m->map[y][x] == '1')
		mlx_put_image_to_window(m->mlx, m->win, m->i_w, x * 50, y * 50);
	else if (m->map[y][x] == 'P')
	{
		mlx_put_image_to_window(m->mlx, m->win, m->i_h, x * 50, y * 50);
		m->x = x;
		m->y = y;
	}
	else if (m->map[y][x] == 'E')
		mlx_put_image_to_window(m->mlx, m->win, m->i_d, x * 50, y * 50);
	else if (m->map[y][x] == 'C')
		mlx_put_image_to_window(m->mlx, m->win, m->i_c, x * 50, y * 50);
}

void	ft_map_loop(t_map *map)
{
	int		y;
	int		x;
	char	*moves;
	char	*move_count;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			ft_loop_content(map, x, y);
			x++;
		}
		y++;
	}
	move_count = ft_itoa(map->movements);
	moves = ft_strjoin("Moves :", move_count);
	mlx_string_put(map->mlx, map->win, x + 10, (y * 50) + 20, 0xffffff, moves);
}

void	ft_create_map(t_map *m)
{
	ft_find_player(m);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, m->x * 50, (m->y * 50) + 32, "DOOM!");
	mlx_key_hook(m->win, ft_keyboard, m);
	mlx_hook(m->win, 17, 1L << 17, ft_close_window, m);
	ft_print_obj(m);
	ft_map_loop(m);
	mlx_loop(m->mlx);
}

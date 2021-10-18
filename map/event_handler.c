/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <bgarrido@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:03:42 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 09:42:14 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_door(t_map *map)
{
	if (map->t_c == map->c_c)
	{
		map->door = ft_strdup("./Assets/Door_open.xpm");
		map->i_d = mlx_xpm_file_to_image(map->mlx, map->door, &map->x, &map->y);
	}
}

int	ft_keyboard(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 123)
		ft_move_left(map);
	if (keycode == 1 || keycode == 125)
		ft_move_down(map);
	if (keycode == 2 || keycode == 124)
		ft_move_right(map);
	if (keycode == 13 || keycode == 126)
		ft_move_up(map);
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(1);
	}
	return (1);
}

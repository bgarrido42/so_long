/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:36:06 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:34:14 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move(t_map *map)
{
	map->map[map->new_y][map->new_x] = 'P';
	map->map[map->old_y][map->old_x] = '0';
	map->old_y = map->new_y;
	map->old_x = map->new_x;
	map->movements++;
	ft_check_door(map);
}

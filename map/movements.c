/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:50:40 by bgarrido          #+#    #+#             */
/*   Updated: 2021/10/13 10:05:04 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_down(t_map *m)
{
	if (m->map[m->old_y + 1][m->old_x] != '1')
	{
		if (m->map[m->old_y + 1][m->old_x] == 'C')
		{
			m->new_y = m->old_y + 1;
			m->new_x = m->old_x;
			ft_move(m);
			m->c_c++;
		}
		else if (m->map[m->old_y + 1][m->old_x] == '0')
		{		
			m->new_y = m->old_y + 1;
			m->new_x = m->old_x;
			ft_move(m);
		}
		else if (m->map[m->old_y + 1][m->old_x] == 'E' && m->t_c == m->c_c)
		{
			m->new_y = m->old_y + 1;
			m->new_x = m->old_x;
			ft_end_game(m);
		}		
		mlx_clear_window(m->mlx, m->win);
		ft_map_loop(m);
	}
}

void	ft_move_up(t_map *m)
{
	if (m->map[m->old_y - 1][m->old_x] != '1')
	{
		if (m->map[m->old_y - 1][m->old_x] == 'C')
		{
			m->new_y = m->old_y - 1;
			m->new_x = m->old_x;
			ft_move(m);
			m->c_c++;
		}
		else if (m->map[m->old_y - 1][m->old_x] == '0')
		{		
			m->new_y = m->old_y - 1;
			m->new_x = m->old_x;
			ft_move(m);
		}
		else if (m->map[m->old_y - 1][m->old_x] == 'E' && m->t_c == m->c_c)
		{
			m->new_y = m->old_y - 1;
			m->new_x = m->old_x;
			ft_end_game(m);
		}
		mlx_clear_window(m->mlx, m->win);
		ft_map_loop(m);
	}
}

void	ft_move_left(t_map *m)
{
	if (m->map[m->old_y][m->old_x - 1] != '1')
	{
		if (m->map[m->old_y][m->old_x - 1] == 'C')
		{
			m->new_y = m->old_y;
			m->new_x = m->old_x - 1;
			ft_move(m);
			m->c_c++;
		}
		else if (m->map[m->old_y][m->old_x - 1] == '0')
		{		
			m->new_y = m->old_y;
			m->new_x = m->old_x - 1;
			ft_move(m);
		}
		else if (m->map[m->old_y][m->old_x - 1] == 'E' && m->t_c == m->c_c)
		{
			m->new_y = m->old_y;
			m->new_x = m->old_x - 1;
			ft_end_game(m);
		}
		mlx_clear_window(m->mlx, m->win);
		ft_map_loop(m);
	}
}

void	ft_move_right(t_map *m)
{
	if (m->map[m->old_y][m->old_x + 1] != '1')
	{
		if (m->map[m->old_y][m->old_x + 1] == 'C')
		{
			m->new_y = m->old_y;
			m->new_x = m->old_x + 1;
			ft_move(m);
			m->c_c++;
		}
		else if (m->map[m->old_y][m->old_x + 1] == '0')
		{		
			m->new_y = m->old_y;
			m->new_x = m->old_x + 1;
			ft_move(m);
		}
		else if (m->map[m->old_y][m->old_x + 1] == 'E' && m->t_c == m->c_c)
		{
			m->new_y = m->old_y;
			m->new_x = m->old_x + 1;
			ft_end_game(m);
		}
		mlx_clear_window(m->mlx, m->win);
		ft_map_loop(m);
	}
}

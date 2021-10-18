/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afiat-ar <afiat-ar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 11:23:13 by afiat-ar          #+#    #+#             */
/*   Updated: 2021/10/01 11:21:44 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	With this method we 
**	initialice *tab to false
**/
static t_print	*ft_init_struct(t_print *tab)
{
	tab->zero = 0;
	tab->minus = 0;
	tab->pnt = 0;
	tab->tl = 0;
	tab->sign = 0;
	tab->pad = 0;
	tab->sp = 0;
	tab->wdt = 0;
	return (tab);
}

t_print	*ft_reset_struct(t_print *tab)
{
	tab->zero = 0;
	tab->minus = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->pad = 0;
	tab->sp = 0;
	tab->wdt = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		r;
	t_print	*tab;

	if (!format)
		return (0);
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	i = -1;
	r = 0;
	va_start(tab->args, format);
	ft_init_struct(tab);
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_check_flags(tab, i + 1, format);
		else
			r += write(1, &format[i], 1);
	}
	r += tab->tl;
	va_end(tab->args);
	free(tab);
	return (r);
}

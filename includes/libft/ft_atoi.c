/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:58:11 by bgarrido          #+#    #+#             */
/*   Updated: 2021/09/15 10:27:36 by bgarrido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_jump_spcs(char *aux)
{
	while (*aux == ' ' || *aux == '\t' || *aux == '\r'
		|| *aux == '\f' || *aux == '\v' || *aux == '\n')
		aux++;
	return (aux);
}

int	ft_check_nb_max(unsigned long long result, int mult)
{
	unsigned long long	i;

	i = 2147483647;
	if (result > i)
	{
		if (mult == -1 && result != i++)
			result = 0;
		else
			result = 0;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	char				*aux;
	int					mult;
	unsigned long long	result;

	mult = 1;
	aux = (char *)str;
	result = 0;
	aux = ft_jump_spcs(aux);
	if (*aux == '+' || *aux == '-')
	{
		if (*aux == '-')
			mult = -1;
		aux++;
	}
	while (*aux)
	{
		if (*aux < 48 || 57 < *aux)
			return (result * mult);
		else
			result = (result * 10) + (long long int)(*aux - '0');
		aux++;
	}
	result = ft_check_nb_max(result, mult);
	return (result * mult);
}

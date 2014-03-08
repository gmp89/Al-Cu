/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charly.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 23:54:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 23:58:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_charly_help1(t_data *data, int i, int j)
{
	if (data->map[j - 1] && data->map[j - 1][i] == data->empty)
	{
		data->move = ft_itoa(i + 1);
		return (1);
	}
	if (data->map[j][i + 1] &&
	(data->map[j][i + 1] == data->empty ||
	(data->map[j - 1] &&
	data->map[j - 1][i + 1] == data->empty)))
	{
		data->move = ft_itoa(i + 1 + 1);
		return (1);
	}
	if (data->map[j][i - 1] &&
	(data->map[j][i - 1] == data->empty ||
	(data->map[j - 1] &&
	data->map[j - 1][i - 1] == data->empty)))
	{
		data->move = ft_itoa(i + 1 - 1);
		return (1);
	}
	return (1);
}

int		ft_charly(t_data *data)
{
	if (data->first == 1 || data->first == -1)
	{
		data->move = ft_itoa((data->size_x / 2) + 1);
		data->first = 0;
		return (1);
	}
	if (ft_charly_help3(data) == 1)
		return (1);
	if (ft_charly_help2(data) == 1)
		return (1);
	if (ft_charly_help4(data) == 1)
		return (1);
	return (0);
}

int		ft_charly_help4(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->size_y)
	{
		i = -1;
		while (++i < data->size_x)
		{
			if (data->map[j][i] == data->charli)
			{
				ft_charly_help1(data, i, j);
				return (1);
			}
		}
	}
	return (0);
}

int		ft_charly_help2(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	ft_putstr("OK\n");
	while (++j < data->size_y)
	{
		i = -1;
		while (++i < data->size_x)
		{
			if (data->map[j][i] == data->player1)
			{
				if (data->map[j + 2] && data->map[j + 2][i] == data->player1 &&
				data->map[j + 1][i] == data->player1 && data->map[j - 1] &&
				data->map[j - 1][i] == data->empty)
				{
					data->move = ft_itoa(i + 1);
					return (1);
				}
			}
		}
	}
	return (0);
}

int		ft_charly_help3(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->size_y)
	{
		i = -1;
		while (++i < data->size_x)
		{
			if (data->map[j][i] == data->charli)
			{
				if (data->map[j + 2] && data->map[j + 2][i] == data->charli &&
				data->map[j + 1][i] == data->charli && data->map[j - 1] &&
				data->map[j - 1][i] == data->empty)
				{
					data->move = ft_itoa(i + 1);
					return (1);
				}
			}
		}
	}
	return (0);
}

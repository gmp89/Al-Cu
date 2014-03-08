/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:14:34 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 22:01:29 by gpetrov          ###   ########.fr       */
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
	int	i;
	int	j;

	j = -1;
	if (data->first == 1 || data->first == -1)
	{
		data->move = ft_itoa((data->size_x / 2) + 1);
		data->first = 0;
		return (1);
	}
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

int		ft_while_help1(t_data *data)
{
	ft_check_turn(data);
	if (data->turn == 1)
	{
		get_next_line(0, &data->line);
		data->move = ft_strdup(data->line);
		free(data->line);
	}
	else
		ft_charly(data);
	return (0);
}

int		ft_while(t_data *data)
{
	while (42)
	{
		ft_while_help1(data);
		if (ft_check_piece(data->move) == -1 ||
		ft_put_piece(data, data->move) == -1)
		{
			ft_putstr("Invalid piece try again\n");
			continue ;
		}
		ft_print_map(data);
		if (tray_analyse(data, data->player1) == 1)
		{
			ft_putstr("Human Player win the game !!\n");
			return (1);
		}
		if (tray_analyse(data, data->charli) == 1)
		{
			ft_putstr("Charly win the game !!\n");
			return (1);
		}
		free(data->move);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data	data;

	data.player1 = 'X';
	data.charli = 'O';
	data.empty = '.';
	if (ac != 3)
	{
		ft_putstr("[USAGE] - ./puissance4 Size_y Size_x\n");
		return (0);
	}
	if (ft_check_args(av) == -1)
		return (0);
	ft_create_map(&data, av);
	ft_hazard(&data);
	if (ft_while(&data) == 1)
		return (0);
	return (0);
}

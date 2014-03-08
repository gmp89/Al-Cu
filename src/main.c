/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:14:34 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 23:55:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_while_help1(t_data *data)
{
	ft_check_turn(data);
	if (data->turn == 1)
	{
		if (get_next_line(0, &data->line) <= 0)
		{
			ft_putstr("Wrong input\n");
			return (-1);
		}
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
		if (ft_check_null(data) == -1)
			return (-1);
		if (ft_while_help1(data) == -1)
			return (0);
		if (ft_check_piece(data->move) == -1 ||
		ft_put_piece(data, data->move) == -1)
			continue ;
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
	{
		ft_putstr("Invalid size\n");
		return (0);
	}
	ft_create_map(&data, av);
	ft_hazard(&data);
	if (ft_while(&data) == -1)
		ft_putstr("Game is NULL\n");
	free(data.map);
	return (0);
}

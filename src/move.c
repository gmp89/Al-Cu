/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:56:12 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 23:26:34 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_create_map(t_data *data, char **av)
{
	int		i;
	int		j;

	j = -1;
	data->size_y = ft_atoi(av[1]);
	data->size_x = ft_atoi(av[2]);
	data->map = (char **)malloc(sizeof(char *) * (data->size_y + 1));
	while (++j < data->size_y)
	{
		i = -1;
		data->map[j] = (char *)malloc(sizeof(char) * (data->size_x + 1));
		while (++i < data->size_x)
			data->map[j][i] = data->empty;
		data->map[j][i] = '\0';
	}
	data->map[j] = NULL;
	ft_print_map(data);
}

int		ft_move_player(t_data *data, char *piece)
{
	int	move;
	int	i;

	i = -1;
	move = ft_atoi(piece) - 1;
	if (data->map[0][move] == data->player1 ||
	data->map[0][move] == data->charli)
		return (-1);
	while (++i < (data->size_y - 1))
	{
		if (data->map[i + 1] && (data->map[i + 1][move] == data->player1 ||
		data->map[i + 1][move] == data->charli) &&
		data->map[i][move] == data->empty)
			break ;
	}
	if (data->turn == 1)
		data->map[i][move] = data->player1;
	else
		data->map[i][move] = data->charli;
	return (0);
}

int		ft_put_piece(t_data *data, char *piece)
{
	if (ft_atoi(piece) > data->size_x || ft_atoi(piece) < 1)
	{
		ft_putstr("\nInvalid piece try again\n\n");
		return (-1);
	}
	if (data->turn == 1)
	{
		if (ft_move_player(data, piece) == -1)
		{
			ft_putstr("\nInvalid piece try again\n\n");
			return (-1);
		}
	}
	else
		ft_move_player(data, piece);
	if (data->turn == 1)
		data->turn = 2;
	else
		data->turn = 1;
	return (0);
}

int		ft_check_null(t_data *data)
{
	int	i;
	int	j;

	j = -1;
	while (++j < data->size_y)
	{
		i = -1;
		while (++i < data->size_x)
		{
			if (data->map[j][i] == data->empty)
				return (1);
		}
	}
	return (-1);
}

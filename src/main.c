/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:14:34 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 18:20:20 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_check_if_bigger_than_int(char *str)
{
	int	i;

	i = -1;
	if (ft_strlen(str) > 10)
		return (-1);
	else if (ft_strlen(str) < 10)
		return (1);
	else
	{
		if (ft_strcmp("2147483646", str) < 0)
			return (-1);
	}
	return (1);
}

int		ft_check_args(char **av)
{
	int		i;

	i = -1;
	while (av[1][++i] != 0)
	{
		if (!ft_isdigit(av[1][i]))
			return (-1);
	}
	if (ft_check_if_bigger_than_int(av[1]) == -1)
		return (-1);
	if (ft_check_if_bigger_than_int(av[2]) == -1)
		return (-1);
	i = -1;
	while (av[2][++i] != 0)
	{
		if (!ft_isdigit(av[2][i]))
			return (-1);
	}
	if (ft_atoi(av[1]) < 6 || ft_atoi(av[2]) < 7)
	{
		ft_putstr("Minimum size is (6 x 7)\n");
		return (-1);
	}
	return (0);
}

void	ft_print_map(t_data *data)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++i < data->size_x)
	{
		ft_putstr("  ");
		ft_putnbr(i + 1);
		ft_putstr(" ");
	}
	ft_putchar('\n');
	while (++j < data->size_y)
	{
		i = -1;
		ft_putnbr(j + 1);
		ft_putchar(' ');
		ft_putchar('|');
		ft_putchar(' ');
		while (++i < data->size_x)
		{
			ft_putchar(data->map[j][i]);
			ft_putchar(' ');
			ft_putchar('|');
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

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
		/*free(data->map[j]);*/
	}
	data->map[j] = NULL;
	ft_print_map(data);
}

int		ft_move_player(t_data *data)
{
	int	move;
	int	i;

	i = -1;
	move = ft_atoi(data->line) - 1;
	if (data->map[0][move] == data->player1 || data->map[0][move] == data->charli)
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

int		ft_put_piece(t_data *data)
{
	if (ft_atoi(data->line) > data->size_x || ft_atoi(data->line) < 1)
		return (-1);
	if (data->turn == 1)
	{
		if (ft_move_player(data) == -1)
			return (-1);
	}
	else
		ft_move_player(data);
	if (data->turn == 1)
		data->turn = 2;
	else
		data->turn = 1;
	return (0);
}

void	ft_check_turn(t_data *data)
{
	if (data->turn == 1)
		ft_putstr("Human Player's turn :\n");
	else
		ft_putstr("Charly's turn : \n");
}

int		ft_check_piece(char *piece)
{
	int	i;

	i = -1;
	while (piece[++i] != 0)
	{
		if (!ft_isdigit(piece[i]))
			return (-1);
	}
	if (ft_check_if_bigger_than_int(piece) == -1)
		return (-1);
	return (0);
}

int		ft_while(t_data *data)
{
	while (42)
	{
		ft_check_turn(data);
		get_next_line(0, &data->line);
		if (ft_check_piece(data->line) == -1 || ft_put_piece(data) == -1)
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
		free(data->line);
	}
	return (0);
}

int		ft_hazard(t_data *data)
{
	srand(time(NULL));
	rand();
	data->charly = rand() / 100;
	data->player = rand() / 100;
	if (data->player > data->charly)
		data->turn = 1;
	else
		data->turn = 2;
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
		ft_putstr("[USAGE] - ./puissance4 Size_x Size_y\n");
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

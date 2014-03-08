/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:52:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 21:53:33 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

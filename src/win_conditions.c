/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 02:15:06 by gtandeo           #+#    #+#             */
/*   Updated: 2014/03/08 21:58:22 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		tray_analyse(t_data *d, char player)
{
	if (left_diagonal_analyse(d, player) == 1)
		return (1);
	if (right_diagonal_analyse(d, player) == 1)
		return (1);
	if (vertical_analyse(d, player) == 1)
		return (1);
	if (horizontal_analyse(d, player) == 1)
		return (1);
	return (0);
}

int		left_diagonal_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y != d->size_y - 3)
	{
		x = -1;
		while (++x != d->size_x)
		{
			count = 0;
			while (d->map[y][x] == player)
			{
				y++;
				x--;
				count++;
				if (count == 4)
					return (1);
			}
			y -= count;
			x += count;
		}
	}
	return (0);
}

int		right_diagonal_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y != d->size_y - 3)
	{
		x = -1;
		while (++x != d->size_x - 3)
		{
			count = 0;
			while (d->map[y][x] == player)
			{
				y++;
				x++;
				count++;
				if (count == 4)
					return (1);
			}
			y -= count;
			x -= count;
		}
	}
	return (0);
}

int		vertical_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y != d->size_y - 3)
	{
		x = -1;
		while (++x != d->size_x)
		{
			count = 0;
			while (d->map[y][x] == player)
			{
				y++;
				count++;
				if (count == 4)
					return (1);
			}
			y -= count;
		}
	}
	return (0);
}

int		horizontal_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y != d->size_y)
	{
		x = -1;
		while (++x != d->size_x - 3)
		{
			count = 0;
			while (d->map[y][x] == player)
			{
				x++;
				count++;
				if (count == 4)
					return (1);
			}
			x -= count;
		}
	}
	return (0);
}

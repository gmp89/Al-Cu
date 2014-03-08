/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 21:48:32 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 21:51:12 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_hazard(t_data *data)
{
	srand(time(NULL));
	rand();
	data->charly = rand() / 100;
	data->player = rand() / 100;
	if (data->player > data->charly)
	{
		data->turn = 1;
		data->first = -1;
	}
	else
	{
		data->turn = 2;
		data->first = 1;
	}
	return (0);
}

void	ft_print_map_help1(int i)
{
	ft_putstr("  ");
	ft_putnbr(i + 1);
	ft_putstr(" ");
}

void	ft_print_map_help2(void)
{
	ft_putchar(' ');
	ft_putchar('|');
	ft_putchar(' ');
}

void	ft_print_map(t_data *data)
{
	int		i;
	int		j;

	j = -1;
	i = -1;
	while (++i < data->size_x)
		ft_print_map_help1(i);
	ft_putchar('\n');
	while (++j < data->size_y)
	{
		i = -1;
		ft_print_map_help2();
		while (++i < data->size_x)
		{
			ft_putchar(data->map[j][i]);
			ft_putchar(' ');
			ft_putchar('|');
			ft_putchar(' ');
		}
		ft_putnbr(j + 1);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

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

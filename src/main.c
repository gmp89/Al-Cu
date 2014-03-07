/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:14:34 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/07 21:30:18 by gpetrov          ###   ########.fr       */
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
	i = -1;
	while (av[2][++i] != 0)
	{
		if (!ft_isdigit(av[2][i]))
			return (-1);
	}
	if (ft_atoi(av[1]) < 7 || ft_atoi(av[2]) < 6)
	{
		ft_putstr("Minimum size is (7 x 6)\n");
		return (-1);
	}
	return (0);
}

void	ft_print_map(char **map)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[++j] != 0)
		{
			ft_putchar(map[i][j]);
			ft_putchar(' ');
		}
		j = -1;
		ft_putchar('\n');
	}
}

void	ft_create_map(t_data *data, char **av)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	data->size_x = ft_atoi(av[1]);
	data->size_y = ft_atoi(av[2]);
	data->map = (char **)malloc(sizeof(char *) * (data->size_y + 1));
	while (++i < (data->size_y - 1))
	{
		data->map[i] = (char *)malloc(sizeof(char) * (data->size_x + 1));
		while (++j < data->size_x)
			data->map[i][j] = '.';
		data->map[i][j] = 0;
		j = -1;
	}
	ft_print_map(data->map);
}

int		main(int ac, char **av)
{
	t_data	data;

	if (ac != 3)
	{
		ft_putstr("[USAGE] - ./puissance4 Size_x Size_y\n");
		return (0);
	}
	if (ft_check_args(av) == -1)
		return (0);
	ft_create_map(&data, av);
	ft_putstr("\nPuissance4\n");
	return (0);
}

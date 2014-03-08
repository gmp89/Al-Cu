/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:13:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 17:13:48 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h> /*Careful*/

# include <time.h>
# include "libft.h"

/*
**	Struct
*/

typedef struct	s_data
{
	char		**map;
	char		*line;
	char		empty;
	char		player1;
	char		charli;
	int			size_x;
	int			size_y;
	int			charly;
	int			player;
	int			turn;
}				t_data;

/*
**	Prototypes
*/

int		ft_check_args(char **av);
void	ft_create_map(t_data *data, char **av);
int		tray_analyse(t_data *data, char player);
int		left_diagonal_analyse(t_data *data, char player);
int		right_diagonal_analyse(t_data *data, char player);
int		vertical_analyse(t_data *data, char player);
int		orizontal_analyse(t_data *data, char player);
int		ft_while(t_data *data);
void	ft_check_turn(t_data *data);

#endif

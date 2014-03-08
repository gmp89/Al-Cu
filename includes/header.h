/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:13:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/08 23:59:01 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

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
	int			first;
	char		*move;
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
int		horizontal_analyse(t_data *data, char player);
int		ft_while(t_data *data);
void	ft_check_turn(t_data *data);
int		ft_hazard(t_data *data);
int		ft_check_piece(char *piece);
void	ft_check_turn(t_data *data);
int		ft_put_piece(t_data *data, char *piece);
int		ft_move_player(t_data *data, char *piece);
int		ft_check_if_bigger_than_int(char *str);
int		ft_while_help1(t_data *data);
void	ft_print_map(t_data *data);
void	ft_print_map_help1(int i, t_data *data);
void	ft_print_map_help2(void);
int		ft_charly(t_data *data);
int		ft_charly_help1(t_data *data, int i, int j);
int		ft_charly_help2(t_data *data);
int		ft_charly_help3(t_data *data);
int		ft_charly_help4(t_data *data);
int		ft_while_help1(t_data *data);
int		ft_check_null(t_data *data);
void	ft_free_data(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 20:13:47 by gpetrov           #+#    #+#             */
/*   Updated: 2014/03/07 21:02:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"

typedef struct	s_data
{
	char		**map;
	int			size_x;
	int			size_y;
}				t_data;

/*
**	Prototypes
*/

int		ft_check_args(char **av);
void	ft_create_map(t_data *data, char **av);

#endif

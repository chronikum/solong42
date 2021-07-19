/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:37:13 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 11:28:27 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"

typedef struct s_game_map
{
	int	map_height;
	int	map_length;
	int	player_position_x;
	int	player_position_y;
	char **map_data;
}	t_game_map;

int	ft_check_map_file(char *file_name);
t_game_map *ft_get_map(int argc, char *argv[]);
int	ft_check_map_data(char **data, int lines);



#endif
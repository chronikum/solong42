/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:45:44 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 08:58:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	Checks if all the lines have the same length.
**	Returns 1, if true, 0 if otherwise
*/
static int	ft_check_length(t_game_map *game_map)
{
	int line_l;
	int should_l;
	int is_l;
	int cl;

	cl = 0;
	should_l = 0;
	is_l = 0;
	line_l = ft_strlen(game_map->map_data[0]);
	while (cl <= game_map->map_height)
	{
		is_l += ft_strlen(game_map->map_data[(cl)]);
		should_l += line_l;
		cl++;
	}
	return (is_l == should_l);
}

/*
**
**	This checks the map struct for validity and rules:
**  - All lines have same length
**  - Theres one player symbol
**  - It is surrounded by walls
**  - There is one exit
*/
int	ft_check_map_data(t_game_map *game_map)
{
	if (!ft_check_length(game_map))
		return (0);
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:45:44 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 10:32:37 by jfritz           ###   ########.fr       */
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
**	Checks if there is exactly one player.
*/
static unsigned long	ft_check_player(t_game_map *game_map)
{
	int		count;
	char	*position;
	char	*position2;
	char	*line;

	position = 0;
	count = 0;
	position2 = 0;
	while (count <= game_map->map_height)
	{
		line = game_map->map_data[count];
		if (position)
			position2 = ft_linechr_player(line);
		if (!position)
			position = ft_linechr_player(line);
		if (position2)
			return (0);
		count++;
	}
	return (!!position);
}

/*
** Checks if the walls are coherent.
** If not, it will return 0.
*/
static int	ft_check_walls(t_game_map *game_map)
{
	int	count;
	int flag;
	char *temp;

	count = 0;
	flag = 1;
	if (!ft_check_is_wall(game_map->map_data[0]))
		return (0);
	if (!ft_check_is_wall(game_map->map_data[game_map->map_height]))
		return (0);
	while (count <= game_map->map_height)
	{
		temp = game_map->map_data[count];
		if (temp[0] != '1')
			flag = 0;
		if (temp[ft_strlen(temp) - 1] != '1')
			flag = 0;
		count++;
	}

	return (flag);
}

/*
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
	if (!ft_check_walls(game_map))
		return (0);
	if (!ft_check_player(game_map))
		return (0);
	return (1);
}
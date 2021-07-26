/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:28:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 13:31:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	Returns 1 if the game is over
**	(all items are collected)
*/
int	ft_game_end(t_game_map *game_map)
{
	return (game_map->max_score == game_map->game_score);
}

/*
**	Returns the amounts
**	of points available in the
**	game.
*/
int	ft_max_score(t_game_map *game_map)
{
	int	score;
	int	count_y;
	int	count_x;

	score = 0;
	count_y = 0;
	count_x = 0;
	while (count_y <= game_map->map_height)
	{
		count_x = 0;
		while (game_map->map_data[count_y][count_x])
		{
			if (game_map->map_data[count_y][count_x] == 'C')
				score++;
			count_x++;
		}
		count_y++;
	}
	return (score);
}

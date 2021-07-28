/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:40:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/28 10:29:37 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_y(int change, t_game_map **map)
{
	if (change < 0)
		return (0);
	if (change >= (*map)->map_height)
		return (0);
	return (1);
}

static int	is_valid_x(int change, t_game_map **map)
{
	if (change < 0)
		return (0);
	if (change >= (*map)->map_length)
		return (0);
	return (1);
}

/*
**	Moves the enemy "random" in a direction.
**	Also makes sure the direction is actually valid!
*/
void	ft_move_enemy(t_game_map **map)
{
	int	change;
	int	dir;
	int	ho;

	change = (ft_ps_random() + (*map)->steps) % 10;
	dir = ft_ps_random() % 2;
	ho = (*map)->enemyPos[0];
	if (dir == 1)
		ho = (*map)->enemyPos[1];
	if (change > 4)
		ho = ho + 1;
	else
		ho = ho - 1;
	if (dir == 1 && is_valid_y(ho, map))
		(*map)->enemyPos[1] = ho;
	else if (dir == 0 && is_valid_x(ho, map))
		(*map)->enemyPos[0] = ho;
}

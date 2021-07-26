/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:40:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 12:02:13 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_valid_y(int change, t_game_map **map)
{
	if (change < 0)
		return (0);
	if ((change - 1) >= (*map)->map_height)
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

void	ft_move_enemy(t_game_map **map)
{
	int change;
	int dir;
	int ho;
	
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
	{
		ft_printf("Y MOVEMENT TO %d is ok! \n", ho);
		(*map)->enemyPos[1] = ho;
	}
	else if (dir == 0 && is_valid_x(ho, map))
	{
		ft_printf("X MOVEMENT TO %d is ok! \n", ho);
		(*map)->enemyPos[0] = ho;
	}
	ft_printf("ENEMY POSITION: Y %d X %d\n", (*map)->enemyPos[1], (*map)->enemyPos[0]);
}
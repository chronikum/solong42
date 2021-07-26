/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:06:59 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 12:47:55 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_over(t_game_map **map, t_render_v **vars)
{
	int		wh;
	int		wc;
	void	*p[2];
	char	*go;


	wh = ft_whc((*map));
	wc = ft_wwc((*map));
	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "You won!!";
	if ((*map)->game_over)
	{
		mlx_string_put(p[0], p[1], wc, wh, ORANGE, go);
		return (1);
	}
	if ((*map)->enemySet)
	{
		ft_printf("PLAYER X %d PLAYER Y %d\n",(*map)->player_position_x / TILE_WIDTH, (*map)->player_position_y / TILE_WIDTH);
		ft_printf("ENEMY X %d ENEMY Y %d\n", (*map)->enemyPos[0], (*map)->enemyPos[1]);
		if ((*map)->enemyPos[0] == ((*map)->player_position_x / TILE_WIDTH)
		&& (*map)->enemyPos[1] == ((*map)->player_position_y / TILE_WIDTH))
		{
				ft_printf("COLLISION!");
				(*map)->game_over = 1;
				go = "The owl caught you!";
				mlx_string_put(p[0], p[1], wc, wh, ORANGE, go);
				return (1);
		}
	}

	return (0);
}
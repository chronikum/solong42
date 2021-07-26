/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:06:59 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 14:10:47 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_game_lost(t_game_map **m, void **p, int *w_v)
{
	(*m)->game_over = 1;
	mlx_string_put(p[0], p[1], w_v[1], w_v[0], ORANGE, GAME_LOST);
	ft_control_player(-2, (*m));
	return (1);
}

static int	ft_game_won(t_game_map **m, void **p, int *w_v)
{
	(*m)->game_over = 1;
	mlx_string_put(p[0], p[1], w_v[1], w_v[0], ORANGE, GAME_WON);
	ft_control_player(-2, (*m));
	return (1);
}

int	ft_game_over(t_game_map **map, t_render_v **vars)
{
	int		w_v[2];
	void	*p[2];
	int		pos[2];

	w_v[0] = ft_whc((*map));
	w_v[1] = ft_wwc((*map));
	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	pos[0] = (*map)->player_position_y / TILE_WIDTH;
	pos[1] = (*map)->player_position_x / TILE_WIDTH;
	if ((*map)->enemySet)
	{
		if ((*map)->map_data[pos[0]][pos[1]] == 'E' && ft_game_end((*map)))
			return (ft_game_won(map, p, w_v));
		if ((*map)->enemyPos[0] == pos[1]
			&& (*map)->enemyPos[1] == pos[0])
			return (ft_game_lost(map, p, w_v));
	}
	return (0);
}

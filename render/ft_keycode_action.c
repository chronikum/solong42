/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode_action.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 12:33:29 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 17:07:28 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_game_map	*ft_move_vertical(t_game_map *game_map, int dir)
{
	game_map->player_position_y += dir * TILE_WIDTH;
	return (game_map);
}

static t_game_map	*ft_move_horizontal(t_game_map *game_map, int dir)
{
	game_map->player_position_x += dir * TILE_WIDTH;
	return (game_map);
}

t_game_map	*ft_keycode_action(t_game_map *game_map, int keycode)
{
	if (keycode == 1)
		return (ft_move_vertical(game_map, 1));
	if (keycode == 13)
		return (ft_move_vertical(game_map, -1));
	if (keycode == 2)
		return (ft_move_horizontal(game_map, 1));
	if (keycode == 0)
		return (ft_move_horizontal(game_map, -1));
	return (game_map);
}
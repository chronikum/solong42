/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:21 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 08:20:42 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_game_map	*ft_game_quit(t_game_map *game_map)
{
	game_map->game_over = 1;
	return (game_map);
}

/*
**	Checks if there is a tile
**	on the current player position
*/
static t_game_map	*ft_check_tile(t_game_map *game_map)
{
	int	x;
	int	y;

	y = game_map->player_position_y / TILE_WIDTH;
	x = game_map->player_position_x / TILE_WIDTH;
	if (game_map->map_data[y][x] == 'E')
	{
		if (ft_game_end(game_map))
			return (ft_game_quit(game_map));
	}
	if (game_map->map_data[y][x] == 'C')
	{
		game_map->map_data[y][x] = '0';
		game_map->game_score++;
	}
	return (game_map);
}

/*
**	Controls the player. Keycodes determine according
**	logic to be called on the static variable
**	map_data. This is what is being rendered later on.
**
**  When the static variable game_map is being initialized
**  at the beginning we will also get the players position
**  in the map. This is being updated through the 
**  ft_keycode_action function.
*/
t_game_map	*ft_control_player(int keycode, t_game_map *inj_game_map)
{
	static t_game_map	*game_map;

	if (inj_game_map)
	{
		game_map = inj_game_map;
		ft_find_player(game_map, &game_map->player_position_x,
			&game_map->player_position_y);
	}
	if (game_map)
	{
		game_map = ft_keycode_action(game_map, keycode);
		game_map = ft_check_tile(game_map);
	}
	return (game_map);
}

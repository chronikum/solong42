/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:21 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 19:01:50 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
t_game_map *ft_control_player(int keycode, t_game_map *inj_game_map)
{
	static t_game_map *game_map;
	if (inj_game_map)
	{
		game_map = inj_game_map;
		ft_find_player(game_map, &game_map->player_position_x,
			&game_map->player_position_y);
	}
	if (game_map)
	{
		game_map = ft_keycode_action(game_map, keycode);
		return (game_map);
	}
	return (NULL);

}
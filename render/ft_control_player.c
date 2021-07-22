/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:21 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 13:54:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


// Debugging purposes
// static void ft_print_map(t_game_map *game_map)
// {
// 	int count;

// 	count = 0;
// 	while (count <= game_map->map_height)
// 	{
// 		ft_printf("%s\n", game_map->map_data[count]);
// 		ft_printf("X %d\n", game_map->player_position_x);
// 		ft_printf("Y %d\n", game_map->player_position_y);
// 		count++;
// 	}
// }

/*
**	Controls the player. Keycodes determine according
**	logic to be called on the static variable
**	map_data. This is what is being rendered later on.
**	It also updates the player position.
*/
void ft_control_player(int keycode, t_game_map *inj_game_map)
{
	static t_game_map *game_map;
	if (inj_game_map)
	{
		game_map = inj_game_map;
		ft_find_player(game_map, &game_map->player_position_x,
			&game_map->player_position_y);
	}
	if (game_map)
		game_map = ft_keycode_action(game_map, keycode);
}
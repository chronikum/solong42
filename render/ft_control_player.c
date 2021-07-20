/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:53:21 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 12:27:27 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


// Debugging purposes
static void ft_print_map(t_game_map *game_map)
{
	int count;

	count = 0;
	while (count <= game_map->map_height)
	{
		ft_printf("%s\n", game_map->map_data[count]);
		ft_find_player(game_map, &game_map->player_position_x,
			&game_map->player_position_y);
		ft_printf("X %d\n", game_map->player_position_x);
		ft_printf("Y %d\n", game_map->player_position_y);
		count++;
	}
}

void ft_control_player(int keycode, t_game_map *inj_game_map)
{
	static t_game_map *game_map;
	if (inj_game_map)
		game_map = inj_game_map;
	if (game_map)
	{
		if (keycode == 1)
			ft_printf("DOWN");
		if (keycode == 13)
			ft_printf("UP");
		if (keycode == 2)
			ft_printf("RIGHT");
		if (keycode == 0)
			ft_printf("LEFT");
		ft_print_map(game_map);
	}
}
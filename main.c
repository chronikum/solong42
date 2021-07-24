/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/24 18:25:21 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	ft_exit_with_error()
{
	ft_printf("Error");
	return (1);
}

/*
** Initializes the window, returns
** at at exit.
*/
int	ft_start_game(t_game_map *game_map)
{
	t_render_v *vars;

	vars = ft_start_render(game_map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_map *game_map;

	game_map = ft_get_map(argc, argv);
	if (!game_map)
		return (ft_exit_with_error());
	game_map->game_score = 0;
	game_map->game_over = 0;
	ft_control_player(-1, game_map);
	ft_start_game(game_map);
	return (0);
}

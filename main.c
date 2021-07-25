/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 15:45:57 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_free_stuff(t_game_map **game_map, t_render_v **vars)
{
	static t_game_map	**game_mapm;
	static t_render_v	**varsm;
	int					maph;

	if (game_mapm && varsm && (!game_map && !vars))
	{
		maph = (*game_mapm)->map_height;
		ft_free_map_data(&((*game_mapm)->map_data), maph);
		free((*game_mapm));
		free((*varsm));
		game_mapm = NULL;
		varsm = NULL;
	}
	if (game_map)
		game_mapm = game_map;
	if (vars)
		varsm = vars;
}

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
	ft_start_render(game_map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_map *game_map;
	
	if (!ft_get_map(argc, argv, &game_map))
	{
		free(game_map);
		ft_exit_with_error();
		return (0);
	}
	ft_free_stuff(&game_map, NULL);
	if (!game_map)
	{
		return (ft_exit_with_error());
	}
	game_map->game_score = 0;
	game_map->game_over = 0;
	game_map->steps = 0;
	ft_control_player(-1, game_map);
	ft_start_game(game_map);
	return (0);
}

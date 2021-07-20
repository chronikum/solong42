/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 11:51:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_with_error()
{
	ft_printf("Error");
	exit(1);
}

/*
** Initializes the window, returns
** at at exit.
*/
int	ft_start_game(t_game_map *game_map)
{
	t_render_v *vars;

	vars = ft_start_render();
	if (game_map->map_length)
		ft_printf("OK");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game_map *game_map;

	game_map = ft_get_map(argc, argv);
	if (!game_map)
		return (ft_exit_with_error());
	ft_start_game(game_map);
	return (0);
}

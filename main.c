/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 13:48:32 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map *game_map;

	game_map = ft_get_map(argc, argv);

	ft_printf("%s\n", game_map->map_data[0]);
	ft_printf("%s\n", game_map->map_data[1]);
	ft_printf("%s\n", game_map->map_data[2]);
	ft_printf("%s\n", game_map->map_data[3]);
	ft_printf("%s\n", game_map->map_data[4]);

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 10:50:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_with_error()
{
	ft_printf("Error");
	exit(1);
}

int	ft_start_game(t_game_map *game_map)
{
	int status;
	char *user_input;

	if (game_map->map_length)
		ft_printf("OK");
	user_input = malloc(sizeof(char) * 100);
	status = get_next_line(1, &user_input);
	while (status == 1)
	{
		ft_printf("%s", user_input);
		status = get_next_line(1, &user_input);
	}

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

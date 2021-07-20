/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:42:46 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 10:45:42 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit_with_error()
{
	ft_printf("Error");
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_game_map *game_map;

	game_map = ft_get_map(argc, argv);
	if (!game_map)
		return (ft_exit_with_error());
	return (0);
}

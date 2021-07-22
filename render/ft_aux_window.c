/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:11:17 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 17:18:49 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_window_height(t_game_map *game_map)
{
	return (((game_map->map_height) + 1) * TILE_WIDTH);
}

int	ft_window_width(t_game_map *game_map)
{
	return ((game_map->map_length) * TILE_WIDTH);
}
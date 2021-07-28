/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_putenemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 08:55:07 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/28 10:12:59 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_if_putenemy(t_game_map **map)
{
	if (BONUS == 1)
		ft_put_enemy(map);
}

void	ft_put_steps(t_render_v **vars, t_game_map **map)
{
	char	*go;

	if (BONUS)
	{
		go = ft_itoa((*map)->steps);
		mlx_string_put((*vars)->mlx, (*vars)->win, 10, 10, ORANGE, go);
		free(go);
	}
}

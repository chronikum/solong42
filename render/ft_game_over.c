/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:06:59 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 12:15:01 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_game_over(t_game_map **map, t_render_v **vars)
{
	int		wh;
	int		wc;
	void	*p[2];
	char	*go;

	wh = ft_whc((*map));
	wc = ft_wwc((*map));
	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "Game Over!";
	if ((*map)->game_over)
	{
		mlx_string_put(p[0], p[1], wc, wh, ORANGE, go);
		return (1);
	}

	return (0);
}
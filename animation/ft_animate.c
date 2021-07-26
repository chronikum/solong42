/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:44:28 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 09:10:14 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_animate(t_game_map **m, t_render_v **v)
{
	static int loop = 0;
	static t_render_v **vars;

	if (v)
		vars = v;

	loop++;
	ft_printf("LOOP: %d\n", loop);
	if (loop == 0 && (vars && m))
		ft_marvin_img(v, m);
	if (loop == 1 && (vars && m))
		ft_marvin2_img(v, m);
	if (loop == 2 && (vars && m))
		ft_marvin3_img(v, m);
	if (loop == 3 && (vars && m))
		ft_marvin4_img(v, m);
	if (loop == 4 && m && vars)
		loop = 0;

	return (1);
}
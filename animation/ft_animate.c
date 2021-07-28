/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 07:44:28 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/28 09:07:14 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	state1(t_game_map **m, t_render_v **v)
{
	ft_marvin_img(v, m);
}

static void	state2(t_game_map **m, t_render_v **v)
{
	ft_marvin2_img(v, m);
}

static void	state3(t_game_map **m, t_render_v **v)
{
	ft_marvin3_img(v, m);
}

static void	state4(t_game_map **m, t_render_v **v)
{
	ft_marvin4_img(v, m);
}

int	ft_animate(t_game_map **m, t_render_v **v)
{
	static int			loop = 0;
	static t_render_v	**vars;

	if (BONUS)
	{
		if (v)
			vars = v;
		loop++;
		if (loop == 0 && (vars && m))
			state1(m, vars);
		if (loop == 1 && (vars && m))
			state2(m, vars);
		if (loop == 2 && (vars && m))
			state3(m, vars);
		if (loop == 3 && (vars && m))
			state4(m, vars);
		if (loop == 4 && m && vars)
			loop = 0;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:31:57 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/20 12:09:31 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	Catching key hooks. if user presses escape,
**	we exit the game as wanted
*/
static int	key_hook(int keycode, t_render_v *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (vars)
		ft_control_player(keycode, NULL);
	return (0);
}

/**
** Opens and inits window and
** setups keyhook to register
** keypress events.
** Returns the t_render_v struct
*/
t_render_v	*ft_init_window()
{
	t_render_v	*vars;
	
	vars = malloc(sizeof(t_render_v));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_loop(vars->mlx);
	return (vars);
}

t_render_v	*ft_start_render()
{
	t_render_v *vars;
	vars = ft_init_window();
	
	return (vars);
}
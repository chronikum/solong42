/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 11:31:57 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 09:06:58 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	exit_hook()
{
	ft_free_stuff(NULL, NULL);
	exit(0);
}

/*
**	Catching key hooks. if user presses escape,
**	we exit the game as wanted
**  Also calls the render routine
*/
static int	key_hook(int keycode, t_render_v **vars)
{	
	static t_game_map	*game_map;
	static t_render_v	*varsm;

	if ((*vars))
		varsm = (*vars);
	if (keycode == 53)
	{
		mlx_destroy_window((*vars)->mlx, (*vars)->win);
		ft_free_stuff(NULL, NULL);
		return (0);
	}
	if (varsm)
	{
		game_map = ft_control_player(keycode, NULL);
		ft_render_basic(game_map, &varsm);
	}
	return (1);
}

/**
** Opens and inits window and
** setups keyhook to register
** keypress events.
** Returns the t_render_v struct
*/
static t_render_v	*ft_init_window(t_game_map *game_map)
{
	t_render_v	*vars;
	int			w_width;
	int			w_height;

	vars = malloc(sizeof(t_render_v));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (NULL);
	w_width = ft_window_width(game_map);
	w_height = ft_window_height(game_map);
	vars->win = mlx_new_window(vars->mlx, w_width, w_height, "jfritz game");
	ft_render_basic(game_map, &vars);
	ft_free_stuff(NULL, &vars);
	mlx_key_hook(vars->win, key_hook, &vars);
	mlx_hook(vars->win, 17, 0, exit_hook, &vars);
	mlx_loop(vars->mlx);
	key_hook(-1, &vars);
	return (vars);
}

t_render_v	*ft_start_render(t_game_map *game_map)
{
	t_render_v	*vars;

	vars = ft_init_window(game_map);
	return (vars);
}

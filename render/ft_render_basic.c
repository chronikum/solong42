/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 08:03:46 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_content(t_render_v **vars)
{
	mlx_clear_window((*vars)->mlx, (*vars)->win);
}

static void	ft_put_player(t_render_v **vars, t_game_map *game_map)
{
	int		pos[2];

	pos[0] = game_map->player_position_x;
	pos[1] = game_map->player_position_y;
	ft_put_img(vars, game_map->marvin, pos[0], pos[1]);
}

static void	ft_tile(char t, t_render_v **v, int *pos, t_game_map **map)
{
	ft_put_img(v, (*map)->bg, pos[0], pos[1]);
	if (t == '1')
		ft_put_img(v, (*map)->wall, pos[0], pos[1]);
	if (t == 'C')
		ft_put_img(v, (*map)->star, pos[0], pos[1]);
	if (t == 'E')
		ft_put_img(v, (*map)->exit, pos[0], pos[1]);
}

static void	ft_draw_content(t_render_v **vars, t_game_map *game_map)
{
	int		count;
	int		char_counter;
	char	current;
	int		pos[2];

	count = 0;
	char_counter = 0;
	pos[0] = 0;
	pos[1] = 0;
	while (count <= game_map->map_height && vars)
	{
		char_counter = 0;
		pos[0] = 0;
		while (game_map->map_data[count][char_counter] != 0)
		{
			current = game_map->map_data[count][char_counter];
			ft_tile(current, vars, pos, &game_map);
			char_counter++;
			pos[0] += TILE_WIDTH;
		}
		pos[1] += TILE_WIDTH;
		count++;
	}
	ft_put_player(vars, game_map);
}

void	ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	void	*p[2];
	char	*go;
	int		wh;
	int		wc;

	wh = ft_whc(game_map);
	wc = ft_wwc(game_map);
	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "Game Over!";
	if (game_map->map_data && vars)
	{
		ft_clear_content(vars);
		if (game_map->game_over)
			mlx_string_put(p[0], p[1], wc, wh, ORANGE, go);
		else if (p[1] && p[0])
		{
			ft_animate(&game_map, vars);
			ft_draw_content(vars, game_map);
			go = ft_itoa(game_map->steps);
			mlx_string_put(p[0], p[1], 10, 10, ORANGE, go);
			free(go);
		}
	}
}

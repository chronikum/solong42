/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 08:17:57 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_content(t_render_v **vars)
{
	mlx_clear_window((*vars)->mlx, (*vars)->win);
}

static void	ft_put_player(t_render_v **vars, t_game_map *game_map)
{
	char	*marvin;
	int		img_width;
	int		img_height;
	void	*img;
	int		pos[2];

	marvin = "./assets/Marvin80.xpm";
	pos[0] = game_map->player_position_x;
	pos[1] = game_map->player_position_y;
	img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &img_width, &img_height);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, pos[0], pos[1]);
	free(img);
}

static void	ft_draw_tile(char type, t_render_v **vars, int x, int y)
{
	char	*wall;
	char	*exit;
	char	*collectable;
	char	*bg;

	wall = "./assets/wall1_80.xpm";
	exit = "./assets/exit80.xpm";
	collectable = "./assets/star.xpm";
	bg = "./assets/bg.xpm";
	ft_put_img(vars, bg, x, y);
	if (type == '1')
		ft_put_img(vars, wall, x, y);
	if (type == 'C')
		ft_put_img(vars, collectable, x, y);
	if (type == 'E')
		ft_put_img(vars, exit, x, y);
}

static void	ft_draw_content(t_render_v **vars, t_game_map *game_map)
{
	int		count;
	int		char_counter;
	char	current;
	int		x;
	int		y;

	count = 0;
	char_counter = 0;
	x = 0;
	y = 0;
	while (count <= game_map->map_height && vars)
	{
		char_counter = 0;
		x = 0;
		while (game_map->map_data[count][char_counter] != 0)
		{
			current = game_map->map_data[count][char_counter];
			ft_draw_tile(current, vars, x, y);
			char_counter++;
			x += TILE_WIDTH;
		}
		y += TILE_WIDTH;
		count++;
	}
	ft_put_player(vars, game_map);
}

void	ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	void	*p[2];
	char	*go;
	int		col;
	int		wh;
	int		wc;

	wh = ft_whc(game_map);
	wc = ft_wwc(game_map);
	col = 0xFE6500;
	p[0] = (*vars)->mlx;
	p[1] = (*vars)->win;
	go = "Game Over!";
	if (game_map->map_data && vars)
	{
		ft_clear_content(vars);
		if (game_map->game_over)
			mlx_string_put(p[0], p[1], wc, wh, col, go);
		else if (p[1] && p[0])
		{
			ft_draw_content(vars, game_map);
			go = ft_itoa(game_map->steps);
			mlx_string_put(p[0], p[1], 10, 10, col, go);
			free(go);
		}
	}
}

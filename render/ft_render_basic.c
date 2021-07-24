/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/24 18:08:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_content(t_render_v **vars)
{
	mlx_clear_window((*vars)->mlx, (*vars)->win);
}

static void ft_put_player(t_render_v **vars, t_game_map *game_map)
{
	char	*marvin = "./assets/Marvin80.xpm";
	int		img_width;
	int		img_height;
	void	*img;
	
	img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &img_width, &img_height);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, game_map->player_position_x, game_map->player_position_y);
}

static void ft_draw_tile(char type, t_render_v **vars, int x, int y)
{
	char	*wall = "./assets/wall80.xpm";
	char	*exit = "./assets/exit80.xpm";
	char	*collectable = "./assets/collectable80.xpm";
	int		img_width;
	int		img_height;
	void	*img;
	
	if (type == '1')
	{
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &img_width, &img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, x, y);
		free(img);
	}
	if (type == 'C')
	{
		img = mlx_xpm_file_to_image((*vars)->mlx, collectable, &img_width, &img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, x, y);
		free(img);
	}
	if (type == 'E')
	{
		img = mlx_xpm_file_to_image((*vars)->mlx, exit, &img_width, &img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, x, y);
		free(img);
	}
}

static void	ft_draw_content(t_render_v **vars, t_game_map *game_map)
{
	static int w_progress = 0;
	int count;
	int char_counter;
	char current;
	int x;
	int y;

	count = 0;
	char_counter = 0;
	x = 0;
	y = 0;
	while (count <= game_map->map_height && vars)
	{
		w_progress = 0;
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

void		ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	if (game_map->map_data && vars)
	{
		if (game_map->game_over)
		{
			ft_clear_content(vars);
			mlx_string_put((*vars)->mlx, (*vars)->win, ft_wwc(game_map), ft_whc(game_map), 0xFE6500, "GAME OVER!");
		}
		else if ((*vars)->win && (*vars)->mlx)
		{
			ft_clear_content(vars);
			ft_draw_content(vars, game_map);
			mlx_string_put((*vars)->mlx, (*vars)->win, 10, 10, 0xFE6500, ft_highscore_text(game_map));
		}
	}
}
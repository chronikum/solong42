/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 17:09:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_content(t_render_v **vars)
{
	mlx_clear_window((*vars)->mlx, (*vars)->win);
}

static void ft_draw_tile(char type, t_render_v **vars, int x, int y, t_game_map *game_map)
{
	char	*marvin = "./assets/Marvin80.xpm";
	char	*wall = "./assets/wall80.xpm";
	int		img_width;
	int		img_height;
	void	*img;
	
	if (type == '1')
	{
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &img_width, &img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, x, y);
	}
	if (type == 'P')
	{
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &img_width, &img_height);
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, game_map->player_position_x, game_map->player_position_y);
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
			ft_draw_tile(current, vars, x, y, game_map);
			char_counter++;
			x += TILE_WIDTH;
		}
		ft_putchar('\n');
		y += TILE_WIDTH;
		count++;
	}
}

void		ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	if (game_map->map_data && vars)
	{
		if ((*vars)->win && (*vars)->mlx)
		{
			ft_clear_content(vars);
			ft_draw_content(vars, game_map);
		}
	}	
	// mlx_png_file_to_image(mlx_data->mlx, relative_path, &img_width, &img_width);
	// img = mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
	// if (mlx_data)
}
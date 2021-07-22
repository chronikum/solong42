/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:57:58 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/22 16:14:14 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_clear_content(t_render_v **vars)
{
	mlx_clear_window((*vars)->mlx, (*vars)->win);
}

void		ft_render_basic(t_game_map *game_map, t_render_v **vars)
{
	// char	*relative_path = "./assets/42.png";
	int		img_width;
	int		img_height;
	// void	*img;

	if (game_map->map_data && vars)
	{
		if ((*vars)->win && (*vars)->mlx)
		{
			ft_clear_content(vars);
			mlx_string_put((*vars)->mlx, (*vars)->win, game_map->player_position_x, game_map->player_position_y, 0xd11b1b, "HELLO");
		}
	}	

	img_width = 322;
	img_height = 196;
	// mlx_png_file_to_image(mlx_data->mlx, relative_path, &img_width, &img_width);
	// img = mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
	// if (mlx_data)
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:34:06 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 12:14:16 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_wall_image(t_render_v **vars, t_game_map **map)
{
	char *wall;
	static void *img;
	int	pos[2];
	
	wall = "./assets/wall1_80.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void ft_star_image(t_render_v **vars, t_game_map **map)
{
	char *star;
	static void *img;
	int	pos[2];
	
	star = "./assets/star.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, star, &pos[0], &pos[1]);
	(*map)->star = img;
}

void ft_exit_image(t_render_v **vars, t_game_map **map)
{
	char *exit;
	static void *img;
	int	pos[2];
	
	exit = "./assets/exit80.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, exit, &pos[0], &pos[1]);
	(*map)->exit = img;
}
void ft_bg_image(t_render_v **vars, t_game_map **map)
{
	char *bg;
	static void *img;
	int	pos[2];
	
	bg = "./assets/bg.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, bg, &pos[0], &pos[1]);
	(*map)->bg = img;
}
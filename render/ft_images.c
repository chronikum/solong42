/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:34:06 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 11:44:04 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void *ft_wall_image(t_render_v **vars)
{
	char *wall;
	static void *img;
	int	pos[2];
	
	wall = "./assets/wall1_80.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	return img;
}

void *ft_star_image(t_render_v **vars)
{
	char *wall;
	static void *img;
	int	pos[2];
	
	wall = "./assets/star.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	return img;
}

void *ft_exit_image(t_render_v **vars)
{
	char *wall;
	static void *img;
	int	pos[2];
	
	wall = "./assets/exit80.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	return img;
}
void *ft_bg_image(t_render_v **vars)
{
	char *wall;
	static void *img;
	int	pos[2];
	
	wall = "./assets/bg.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, wall, &pos[0], &pos[1]);
	return img;
}
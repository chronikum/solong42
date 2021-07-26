/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 09:20:57 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 09:44:12 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_tree1(t_render_v **vars, t_game_map **map)
{
	char		*tree;
	static void	*img;
	int			pos[2];

	tree = WALL;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, tree, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void	ft_tree2(t_render_v **vars, t_game_map **map)
{
	char		*tree;
	static void	*img;
	int			pos[2];

	tree = WALL2;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, tree, &pos[0], &pos[1]);
	(*map)->wall = img;
}

void	ft_tree3(t_render_v **vars, t_game_map **map)
{
	char		*tree;
	static void	*img;
	int			pos[2];

	tree = WALL3;
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, tree, &pos[0], &pos[1]);
	(*map)->wall = img;
}

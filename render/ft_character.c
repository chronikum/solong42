/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 08:31:03 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 08:38:25 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_marvin_img(t_render_v **vars, t_game_map **map)
{
	char		*marvin;
	static void	*img;
	int			pos[2];

	marvin = "./assets/three.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &pos[0], &pos[1]);
	(*map)->marvin = img;
}

void	ft_marvin2_img(t_render_v **vars, t_game_map **map)
{
	char		*marvin;
	static void	*img;
	int			pos[2];

	marvin = "./assets/two.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &pos[0], &pos[1]);
	(*map)->marvin = img;
}

void	ft_marvin3_img(t_render_v **vars, t_game_map **map)
{
	char		*marvin;
	static void	*img;
	int			pos[2];

	marvin = "./assets/one.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &pos[0], &pos[1]);
	(*map)->marvin = img;
}

void	ft_marvin4_img(t_render_v **vars, t_game_map **map)
{
	char		*marvin;
	static void	*img;
	int			pos[2];

	marvin = "./assets/four.xpm";
	if (!img)
		img = mlx_xpm_file_to_image((*vars)->mlx, marvin, &pos[0], &pos[1]);
	(*map)->marvin = img;
}

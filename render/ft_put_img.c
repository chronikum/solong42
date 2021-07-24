/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:28:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/24 19:38:49 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_render_v **vars, char *p, int x, int y)
{
	void	*img;
	int		pos[2];

	img = mlx_xpm_file_to_image((*vars)->mlx, p, &pos[0], &pos[1]);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, img, x, y);
	free(img);
}

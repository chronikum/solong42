/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 18:28:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 12:19:45 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_put_img(t_render_v **vars, void *p, int x, int y)
{
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, p, x, y);
}

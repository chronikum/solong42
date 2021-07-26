/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:03:43 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/26 11:09:02 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	Gets called every frame
**	and user inputs and increases
**	seed. Technically, not random.
**	Will provide a value which
**	literally depends on the
**	speed of your computer.
**
**	Random enough for me.
*/
int ft_ps_random()
{
	static int seed = 3;

	seed++;
	if (seed > 1000)
		seed = 3;
	return (seed);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_validation_helpers.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 09:00:32 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 15:56:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
**	Returns 1 if the char array is
**	being considered a wall (only 1)
*/
int	ft_check_is_wall(char *wall)
{
	size_t	count;

	count = 0;
	while (wall[count] == '1')
		count++;
	return (ft_strlen(wall) == count);
}

/**
**	Check if the filename has
**	a valid extension (.ber)
**	If not, it returns 0.
*/
int	ft_check_filename(char *file_name)
{
	int			len;
	const char	*start;

	len = ft_strlen(file_name);
	start = (const char *) &file_name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	return (0);
}

/*
**	Writes the player position in given
**	parameters x and y.
*/
void	ft_find_player(t_game_map *game_map, int *x, int *y)
{
	int		count;
	char	*line;
	int		xPos;

	count = 0;
	xPos = 0;
	while (count <= game_map->map_height)
	{
		line = game_map->map_data[count];
		if (ft_strchr(line, 'P'))
		{
			*y = (count * TILE_WIDTH);
			while (line[xPos] != 'P')
				xPos++;
			*x = (xPos * TILE_WIDTH);
		}
		count++;
	}
}

/*
**	Returns the position of the char
**	in the string.
**	Returns (NULL) if there is no char
**	or more than one
*/
char	*ft_singlelinechr(char *line, char c)
{
	char	*p;
	char	*pr;

	p = ft_strchr(line, c);
	pr = ft_strrchr(line, c);
	if (p == pr && (pr && p))
		return (p);
	return (NULL);
}

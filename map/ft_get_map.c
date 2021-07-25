/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:41:25 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/25 09:30:55 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** Reads in the map data and checks data with
** sub functions for validity. Also gets
** metadata like length and height of the map.
*/
static char	**ft_read_map_file(char *fn, int *he, int *le)
{
	int		fd;
	char	*c;
	char	**ret;
	int		last_state;
	int		linecount;

	*he = 0;
	*le = 0;
	linecount = 0;
	fd = open(fn, O_RDONLY);
	c = malloc(sizeof(char) * 100);
	ret = malloc(sizeof(char **) * 100);
	if (!c || fd == -1 || !ret)
		return (NULL);
	last_state = get_next_line(fd, &c);
	while (last_state == 1)
	{
		*le = ft_strlen(c);
		ret[*he] = c;
		(*he)++;
		ret = ft_realloc((void *) ret, sizeof(char **) * (*he + 1));
		last_state = get_next_line(fd, &c);
	}
	close(fd);
	ret[*he] = c;
	return (ret);
}

void ft_free_map_data(char ***map_data, int size)
{
	int count;

	count = 0;

	while (count <= size)
	{
		free((*map_data)[count]);
		count++;
	}
	free((*map_data));
	(*map_data) = NULL;
}

/*
** Returns the map struct with data, player position
** and checks if pre requisites as arguments are
** fulfilled.
** Returns 0 on Error.
*/
int	ft_get_map(int argc, char *argv[], t_game_map **game_map)
{
	char	**map_data;
	int		map_h;
	int		map_l;

	map_data = NULL;
	(*game_map) = malloc(sizeof(t_game_map));
	if (argc != 1 && (*game_map) && ft_check_filename(argv[1]))
	{
		map_data = ft_read_map_file(argv[1], &map_h, &map_l);
		if (!map_data)
		{
			free((*game_map));
			(*game_map) = NULL;
			return (0);
		}
		(*game_map)->map_height = map_h;
		(*game_map)->map_length = map_l;
		(*game_map)->map_data = map_data;
		(*game_map)->max_score = ft_max_score((*game_map));
		if (ft_check_map_data((*game_map)))
			return (1);
		ft_free_map_data(&map_data, map_h);
	}
	(*game_map) = NULL;
	free((*game_map));
	return (0);
}
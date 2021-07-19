/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:41:25 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/19 13:47:51 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** Reads in the map and checks data with
** sub functions for validity.
*/
static char	**ft_read_map_file(char *fn, int *he, int *le)
{
	int		fd;
	char	*c;
	char	**ret;
	int		last_state;

	*he = 0;
	*le = 0;
	fd = open(fn, O_RDONLY);
	c = malloc(sizeof(char) * 100);
	ret = malloc(sizeof(char **) * 6);
	if (!c || fd == -1)
		return (NULL);
	last_state = get_next_line(fd, &c);
	while (last_state == 1)
	{
		*le = ft_strlen(c);
		ret[*he] = c;
		(*he)++;
		last_state = get_next_line(fd, &c);
	}
	ret[*he] = c;
	// ft_printf("%s\n", ret[0]);
	// ft_printf("%s\n", ret[1]);
	// ft_printf("%s\n", ret[2]);
	// ft_printf("%s\n", ret[3]);
	// ft_printf("%s\n", ret[4]);
	return (ret);
}

/*
** Returns the map struct with data, player position
** and checks if pre requisites as arguments are
** fulfilled.
** Returns null on Error.
*/
t_game_map *ft_get_map(int argc, char *argv[])
{
	char	**map_data;
	int		map_h;
	int		map_l;
	t_game_map *game_map;

	map_data = NULL;
	game_map = malloc(sizeof(t_game_map));
	if (argc != 1)
	{
		map_data = ft_read_map_file(argv[1], &map_h, &map_l);
		game_map->map_height = map_h;
		game_map->map_height = map_l;
		game_map->map_data = map_data;
	}

	return (game_map);
}
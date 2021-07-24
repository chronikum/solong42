/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:37:13 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/24 18:29:55 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

# define TILE_WIDTH 80
typedef struct s_game_map
{
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
	int		game_score;
	int		max_score;
	char	**map_data;
	int		game_over;
}	t_game_map;

typedef struct	s_render_v {
	void	*mlx;
	void	*win;
}	t_render_v;

t_game_map	*ft_get_map(int argc, char *argv[]);
int			ft_check_map_data(t_game_map *game_map);

int			ft_check_is_wall(char *wall);
char		*ft_singlelinechr(char *line, char c);
int			ft_check_filename(char *file_name);
void		ft_find_player(t_game_map *game_map, int *x, int *y);

t_render_v	*ft_start_render(t_game_map *game_map);

t_game_map	*ft_control_player(int keycode, t_game_map *inj_game_map);

t_game_map	*ft_keycode_action(t_game_map *game_map, int keycode);

void		ft_render_basic(t_game_map *game_map, t_render_v **vars);

void		ft_put_img(t_render_v **vars, char *p, int x, int y);

int			ft_window_height(t_game_map *game_map);
int			ft_window_width(t_game_map *game_map);
int			ft_whc(t_game_map *game_map);
int			ft_wwc(t_game_map *game_map);

int			ft_max_score(t_game_map *game_map);
char		*ft_highscore_text(t_game_map *game_map);
int			ft_game_end(t_game_map *game_map);
#endif
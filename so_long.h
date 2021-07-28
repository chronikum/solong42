/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 09:37:13 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/28 10:33:43 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

# define TILE_WIDTH 80

# define WALL "./assets/baum1.xpm"
# define WALL2 "./assets/baum2.xpm"
# define WALL3 "./assets/baum3.xpm"
# define STAR "./assets/flower_light.xpm"
# define STONE "./assets/floor1.xpm"
# define EXIT "./assets/exit80.xpm"

# define ERR_MSG "The provided map is invalid!"

# define ENEMY1 "./assets/evil1.xpm"
# define ENEMY2 "./assets/evil2.xpm"

# define GAME_LOST "Game over"
# define GAME_WON "You won!"

# define ORANGE 0xFE6500
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
	int		steps;
	void	*wall;
	void	*exit;
	void	*player;
	void	*bg;
	void	*star;
	void	*enemy;
	void	*marvin;
	int		drawP;
	int		*enemyPos;
	int		enemySet;
	char	*err_msg;
}	t_game_map;

typedef struct s_render_v {
	void	*mlx;
	void	*win;
}	t_render_v;

int			ft_get_map(int argc, char *argv[], t_game_map **game_map);
int			ft_check_map_data(t_game_map **game_map);

int			ft_check_is_wall(char *wall);
char		*ft_singlelinechr(char *line, char c);
int			ft_check_filename(char *file_name);
void		ft_find_player(t_game_map *game_map, int *x, int *y);

int			ft_aux_check_map_file(t_game_map *t_game_map);

t_render_v	*ft_start_render(t_game_map *game_map);

t_game_map	*ft_control_player(int keycode, t_game_map *inj_game_map);

t_game_map	*ft_keycode_action(t_game_map *game_map, int keycode);

void		ft_render_basic(t_game_map *game_map, t_render_v **vars);
void		ft_set_startv_render(int *c, int *cc);

void		ft_put_img(t_render_v **vars, void *p, int x, int y);

int			ft_window_height(t_game_map *game_map);
int			ft_window_width(t_game_map *game_map);
int			ft_whc(t_game_map *game_map);
int			ft_wwc(t_game_map *game_map);

int			ft_max_score(t_game_map *game_map);
int			ft_game_end(t_game_map *game_map);

void		ft_free_stuff(t_game_map **game_map, t_render_v **vars);
void		ft_free_map_data(char ***map_data, int size);

void		ft_wall_image(t_render_v **vars, t_game_map **map);
void		ft_star_image(t_render_v **vars, t_game_map **map);
void		ft_exit_image(t_render_v **vars, t_game_map **map);
void		ft_bg_image(t_render_v **vars, t_game_map **map);

void		ft_marvin_img(t_render_v **vars, t_game_map **map);
void		ft_marvin2_img(t_render_v **vars, t_game_map **map);
void		ft_marvin3_img(t_render_v **vars, t_game_map **map);
void		ft_marvin4_img(t_render_v **vars, t_game_map **map);

void		ft_tree1(t_render_v **vars, t_game_map **map);
void		ft_tree2(t_render_v **vars, t_game_map **map);
void		ft_tree3(t_render_v **vars, t_game_map **map);

void		ft_enemy1(t_render_v **vars, t_game_map **map);
void		ft_enemy2(t_render_v **vars, t_game_map **map);
int			ft_animate(t_game_map **m, t_render_v **v);

int			ft_ps_random(void);
void		ft_put_enemy(t_game_map **map);
void		ft_move_enemy(t_game_map **map);

int			ft_game_over(t_game_map **map, t_render_v **vars);

void		ft_if_putenemy(t_game_map **map);
void		ft_put_steps(t_render_v **vars, t_game_map **map);

#endif
#include "../so_long.h"

/*
**
**	Sets a enemy at a position
**	which is free.
**	This is done once.
*/
void	ft_put_enemy(t_game_map **map)
{
	static int	enemyPos[2];
	static int	enemySet = 0;

	while (enemySet == 0)
	{
		enemyPos[1] = ((ft_ps_random() + 1) % (*map)->map_height);
		enemyPos[0] = ((ft_ps_random() + 1) % (*map)->map_length);
		if (!(enemyPos[0] == ((*map)->player_position_x / TILE_WIDTH)))
			enemySet++;
		if (!(enemyPos[1] == ((*map)->player_position_y / TILE_WIDTH)))
			enemySet++;
		(*map)->enemyPos = enemyPos;
		(*map)->enemySet = 1;
	}
	(*map)->enemyPos = enemyPos;
}

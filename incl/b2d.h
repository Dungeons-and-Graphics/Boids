#ifndef B2D_H
# define B2D_H
# include <SDL2/SDL.h>
# include <stdlib.h>
# include "b2d_structs.h"

# define WIN_W 1000
# define WIN_H 500
# define CELL_W WIN_W / 50
# define CELL_H WIN_H / 50
# define COLUMNS WIN_W / CE:
# define ROWS
# define AWAY_R 10
# define CLOSE_R 50
# define FOLLOW_R 25

/*   File : init.c   */
Master	*init();

/*   File : utils.c   */
int		get_cell(Boid *boid, int offset_x, int offset_y);
void	get_all_cells(Boid *boid, int *cell);

#endif

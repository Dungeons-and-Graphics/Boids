#include "b2d.h"

int	get_cell(Boid *boid, int offset_x, int offset_y)
{
	int cell;

	cell = (((boid->position.x + offset_x) / CELL_W)  + ((boid->position.y + offset_y) / CELL_H)) - 3;
	return cell;
}

void	get_all_cells(Boid *boid, int *cell)
{
	cell[0] = get_cell(boid, 0, 1);
	cell[1] = get_cell(boid, 0, -1);
	cell[2] = get_cell(boid, 1, 0);
	cell[3] = get_cell(boid, -1, 0);
	cell[4] = get_cell(boid, 1, 1);
	cell[5] = get_cell(boid, -1, -1);
	cell[6] = get_cell(boid, -1, 1);
	cell[7] = get_cell(boid, 1, -1);
}

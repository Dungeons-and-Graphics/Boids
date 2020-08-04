#include "b2d.h"

int	get_cell(Boid boid, int offset_x, int offset_y)
{
	int cell, celly, w, h;

	w = CELL_W;
	h = CELL_H;
	cell = (boid.position.x + offset_x) / 100;
	celly = (boid.position.y + offset_y) / 100;
	cell += (celly * 10);
	//printf("Cell %d\n", cell);
	return cell;
}

void	get_all_cells(Boid boid, int *result)
{
	*result = get_cell(boid, 0, 100);
	*result = get_cell(boid, 0, -100);
	*result = get_cell(boid, 100, 0);
	*result = get_cell(boid, -100, 0);
	*result = get_cell(boid, 100, 100);
	*result = get_cell(boid, -100, -100);
	*result = get_cell(boid, -100, 100);
	*result = get_cell(boid, 100, -100);
}

double get_distance(Boid a, Boid b)
{
	int x, y;
	double dist;

	x = a.position.x - b.position.x;
	y = a.position.y - b.position.y;
	dist = (x * x) + (y * y);
	return sqrt(dist);
}

/* Vector2 add_vectors(Vector2 a, Vector2 b)
{

}

void move_away(Boid *boid, Boid target)
{

}

void move_closer(Boid *boid, Boid target)
{

}

void follow(Boid *boid, Boid target)
{

}
 */

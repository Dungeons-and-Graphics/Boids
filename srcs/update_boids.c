#include "b2d.h"

void render(Master *master)
{
	SDL_Rect rect;
	int  i = 0;

	rect.h = WIN_H / 100;
	rect.w = WIN_W / 100;
	while ( i < 10)
	{
		rect.x = master->boids[i]->position.x;
		rect.y = master->boids[i]->position.y;
		SDL_RenderDrawRect(master->renderer, &rect);
		i++;
	}
}
void cell_interactions(Node *node)
{
	Node *cell;
	Boid *boid;
	double distance;

	cell = node->next;
	boid = cell->boid;
	boid->direction = rand() % 180;
	while (cell)
	{
		distance = get_distance(*boid, *cell->boid);
		/* if (distance <= AWAY_R)
			move_away(boid, *cell->boid);
		else if (distance <= CLOSE_R)
			move_closer(boid, *cell->boid);
		else if (distance <= FOLLOW_R)
			follow(boid, *cell->boid); */
		cell = cell->next;
	}
}

void apply_transforms(Boid *boid)
{
	boid->position.x += (cos(boid->direction) + 1);
	boid->position.y += (sin(boid->direction) + 1);
}

void switch_cell(Master *master, Node *node, int cell)
{
	int i = 0, n, origin_cell, rad_cell[8];
	Boid *boid;

	while (i < 10)
	{
		boid = master->boids[i];
		origin_cell = get_cell(boid, 0, 0);
		get_all_cells(boid, &rad_cell);
		master->Grid[origin_cell]->tail->next = boid;
		master->Grid[origin_cell]->tail = boid;
		n = 0;
		while (n < 8)
		{
			if (rad_cell[n] != origin_cell)
			{
				master->Grid[rad_cell[n]]->tail->next = boid;
				master->Grid[rad_cell[n]]->tail = boid;
			}
			n++;
		}
		i++;
	}
}

void update(Master *master, int m_x, int m_y)
{
	int i;

	Node *list;
	while (i < master->cell_no)
	{
		list = master->Grid[i];
		while (list->next != NULL)
		{
			cell_interactions(list);
			apply_transforms(list->boid);
		}
	}
	render(master);
}

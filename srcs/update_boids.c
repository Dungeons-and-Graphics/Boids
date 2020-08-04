#include "b2d.h"

void render(Master *master)
{
	SDL_Rect rect;
	int  i = 0;

	rect.h = WIN_H / 100;
	rect.w = WIN_W / 100;
	while (i < 10)
	{
		rect.x = master->boids[i]->position.x;
		rect.y = master->boids[i]->position.y;
		SDL_RenderDrawRect(master->renderer, &rect);
		i++;
	}
}
void cell_interactions(Master *master)
{
	Boid **cell, *current;
//	double distance;
	int i = 0, n, elems;

	printf("Start \n");
	while (i < 50)
	{
		cell = master->grid[i].boid;
		elems = master->grid[i].num_elems;
		printf("Elems %d\n", elems);
		while (elems > 0)
		{
			printf("%d\t", elems);
			/* n = 0;
			current = cell[*elems];
			 while (n < *elems)
			{
			//	distance = get_distance(*current, cell[n]);
				current->direction = rand() % 180;
				(rand() % 1 == 1) ? (current->direction *= -1) : (1 + 1);
				n++;
			}
			printf("HERE\n");*/
			elems--;
		}
		/*i++;
		 if (distance <= AWAY_R)
			move_away(boid, *cell->boid);
		else if (distance <= CLOSE_R)
			move_closer(boid, *cell->boid);
		else if (distance <= FOLLOW_R)
			follow(boid, *cell->boid); */
		i++;
	}
}

void apply_transforms(Boid *boid)
{
	boid->position.x += (cos(boid->direction) + 1);
	boid->position.y += (sin(boid->direction) + 1);
}

void switch_cell(Master *master)
{
	int i = 0, cell, *rad_cell, *elems;
	Boid *boid;

	rad_cell = malloc(sizeof(int) * 8);

	while (i < 10)
	{
		boid = master->boids[i];
		apply_transforms(boid);
		cell = get_cell(*boid, 0, 0);
		get_all_cells(*boid, rad_cell);

		elems = &master->grid[cell].num_elems;
		master->grid[cell].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[0]].num_elems;
		master->grid[rad_cell[0]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[1]].num_elems;
		master->grid[rad_cell[1]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[2]].num_elems;
		master->grid[rad_cell[2]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[3]].num_elems;
		master->grid[rad_cell[3]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[4]].num_elems;
		master->grid[rad_cell[4]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[5]].num_elems;
		master->grid[rad_cell[5]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[6]].num_elems;
		master->grid[rad_cell[6]].boid[*elems] = boid;
		elems++;

		elems = &master->grid[rad_cell[7]].num_elems;
		master->grid[rad_cell[7]].boid[*elems] = boid;
		elems++;

		i++;
	}
//	free(rad_cell);
}

void update(Master *master, int m_x, int m_y)
{
	(void)m_x;
	(void)m_y;

	cell_interactions(master);
	printf("Cell interactions\n");
	exit(0);
	switch_cell(master);
	printf("Switch\n");
	render(master);
	printf("Render\n");
}

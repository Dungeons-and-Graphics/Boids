#include "b2d.h"

void init_boids(Master *master)
{
	int i = 0, n, *cell, cell_elems;
	Boid *boid;

	cell = malloc(sizeof(int) * 9);
	while (i < 10)
	{
		boid = malloc(sizeof(Boid));
		boid->position.x = rand() % WIN_W;
		boid->position.y = rand() % WIN_H;
		boid->direction = rand() % 360;
		boid->vars.close = 0;
		boid->vars.div_close = 0;
		boid->vars.far = 0;
		boid->vars.div_far = 0;
		boid->vars.mid = 0;
		boid->vars.div_mid = 0;

		get_all_cells(*boid, cell);

		master->boids[i] = boid;
		master->grid[cell[0]].boid[master->grid[cell[0]].num_elems] = boid;
		master->grid[cell[0]].num_elems++;

		n = 1;
		while (n < 9)
		{
			if (cell[n] != cell[0] && cell[n] >= 0  && cell[n] < 50)
			{
				cell_elems = master->grid[cell[n]].num_elems;
				master->grid[cell[n]].boid[cell_elems] = boid;
				master->grid[cell[n]].num_elems++;
			}
			n++;
		}
		i++;
	}
	//free(cell);
}

Master *init()
{
	Master *master;
	int i = 0;

	SDL_Init(SDL_INIT_EVERYTHING);
	Uint32 render_flags = SDL_RENDERER_SOFTWARE;

	master = (Master *)malloc(sizeof(Master));
	master->window = SDL_CreateWindow("Boids 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0);
	master->renderer = SDL_CreateRenderer(master->window, -1, render_flags);

	master->grid = malloc(sizeof(List) * 50);
	master->boids = malloc(sizeof(Boid *) * 10);

	while (i < 50)
	{
		master->grid[i].boid = malloc(sizeof(Boid *)  * 11);
		master->grid[i].num_elems = 0;
		i++;
	}
	init_boids(master);
	return master;
}

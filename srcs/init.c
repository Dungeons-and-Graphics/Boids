#include "b2d.h"

void init_boids(Master *master)
{
	int i = 0, n,  origin_cell, rad_cell[8];
	Boid *boid;

	while (i < 10)
	{
		boid = malloc(sizeof(Boid));
		master->boids[i] = boid;
		boid->position.x = rand() % WIN_W;
		boid->position.y = rand() % WIN_H;

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

Master *init()
{
	Master master;
	int i = 0;
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error %s\n", SDL_GetError());
	Uint32 render_flags = SDL_RENDERER_SOFTWARE;
	master.window = SDL_CreateWindow("Boids 2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, 0);
	master.renderer = SDL_CreateRenderer(master.window, -1, render_flags);
	master.Grid = malloc(sizeof(Node *) * 50); /* replace 50 by no boids / 2 */
	master.boids = malloc(sizeof(Boid *) * 10);
	while (i < 50)
	{
		master.Grid[i]->boid = NULL;
		master.Grid[i]->head = master.Grid[i];
		master.Grid[i]->next = NULL;
		master.Grid[i]->tail = master.Grid[i];
		i++;
	}
	init_boids(&master);
	return &master;
}


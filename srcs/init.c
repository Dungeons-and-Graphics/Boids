#include "b2d.h"

void init_boids(Master *master)
{
	int i = 0, n, *cell, cell_elems;
	Boid *boid;

	while (i < BOIDNO)
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
		master->boids[i] = boid;
		i++;
	}
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
	master->boids = malloc(sizeof(Boid *) * BOIDNO);

	init_boids(master);

	return master;
}

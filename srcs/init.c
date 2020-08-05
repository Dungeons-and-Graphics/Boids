#include "b2d.h"

void init_boids(Master *master)
{
	int i = 0, n, origin_cell, *surrounding, cell_elems, cur_cell;
	Boid *boid;

	surrounding = malloc(sizeof(int) * 8);
	while (i < 10)
	{
		boid = malloc(sizeof(Boid));
		boid->position.x = rand() % WIN_W;
		boid->position.y = rand() % WIN_H;
		boid->direction = rand() % 360;
		if (rand() % 2 == 1)
			boid->direction *= -1;

		master->boids[i] = boid;

		//origin_cell = get_cell(*boid, 0 , 0);
		/* master->grid[origin_cell].boid[master->grid[origin_cell].num_elems] = boid;
		master->grid[origin_cell].num_elems++;

		get_all_cells(*boid, surrounding);

		n = 0;
		while (n < 8)
		{
			if (surrounding[n] != origin_cell && surrounding[n] >= 0  && surrounding[n] < 50)
			{
				cur_cell = surrounding[n];
				cell_elems = master->grid[0].num_elems;
				master->grid[cur_cell].boid[cell_elems] = boid;
			//	printf("End %d %d\n", rad_cell[n], n);
				master->grid[cur_cell].num_elems++;
			}
			n++;
		} */
		i++;
	}
	//free(surrounding);
}

Master *init()
{
	Master *master;
	int i = 0;

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error %s\n", SDL_GetError());
	Uint32 render_flags = SDL_RENDERER_SOFTWARE;

	if (!(master = (Master *)malloc(sizeof(Master))))
		printf("mlloc failed\n");
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

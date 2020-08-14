#include "b2d.h"

void render(Master *master)
{
	SDL_Rect rect;
	int  i = 0;

	rect.h = WIN_H / 100;
	rect.w = WIN_W / 100;
	SDL_SetRenderDrawColor(master->renderer, 0, 255, 0, 255);
	while (i < 10)
	{
		rect.x = (int)master->boids[i]->position.x;
		rect.y = (int)master->boids[i]->position.y;
		SDL_RenderDrawRect(master->renderer, &rect);
		i++;
	}
	SDL_SetRenderDrawColor(master->renderer, 0, 0, 0, 255);
}

void apply_transforms(Boid *boid, Master *master)
{
	double dir_x, dir_y, far, close, mid, total = 0, t_div = 0;

	if (boid->vars.close > 0)
	{
		close = boid->vars.close;

		close /= boid->vars.div_close;
		while (close > 360)
			close -= 360;
		total += close;
		t_div++;
	}
	/* if (t_div > 0)
		boid->direction = close; */

	printf("close %f, dir%f\n", close, boid->direction);
	dir_x = boid->position.x + cos(to_rad(boid->direction));
	dir_y = boid->position.y + sin(to_rad(boid->direction));
	{
		int debugx, debugy;

		debugx = boid->position.x + 20 * cos(to_rad(boid->direction));
		debugy = boid->position.y + 20 * sin(to_rad(boid->direction));
		SDL_SetRenderDrawColor(master->renderer, 0, 0, 255, 255);
		SDL_RenderDrawLine(master->renderer, boid->position.x, boid->position.y, debugx, debugy);
	}

	boid->vars.close = 0;
	boid->vars.div_close = 0;

	if (dir_x >= (WIN_W - 10))
	{
		boid->position.x = 0;
		//boid->direction += 180;
	}
	else if (dir_x <= 0)
	{
		boid->position.x = WIN_W - 10;
		//boid->direction -= 180;
	}
	else
		boid->position.x = dir_x;
	if (dir_y >= (WIN_H - 10))
	{
		boid->position.y = 0;
		//boid->direction -= 180;
	}
	else if (dir_y <= 0)
	{
		boid->position.y = WIN_H - 10;
	//	boid->direction += 180;
	}
	else
		boid->position.y = dir_y;
}

void update(Master *master, int m_x, int m_y)
{
	(void)m_x;
	(void)m_y;
	int i = 0, count, elems, dist, x, y;
	static int timer;
	List *cell;
	Boid *boid, *target;

	while (i < 50)
	{
		cell =  &master->grid[i];
		elems = cell->num_elems  - 1;
		while (elems >= 0)
		{
			boid = cell->boid[elems];
			count = 0;
			while (count < elems)
			{
				target = cell->boid[count];
				x = target->position.x - boid->position.x;
				y = target->position.y - boid->position.y;
				dist = (x * x) + (y * y);
				if  (CLOSE_R * CLOSE_R >= dist)
				{
					move_away(boid, target);
				}
				count++;
			}
			elems--;
		}
		i++;
	}
}

void update_simple(Master *master)
{
	int i, n, distance;
	static int timer;
	i = 0;

	if (timer == 0)
	{
		master->boids[0]->direction = 0;
		master->boids[0]->position.x = 450;
		master->boids[0]->position.y = 250;

		master->boids[1]->direction = 180;
		master->boids[1]->position.x = 550;
		master->boids[1]->position.y = 250;
	}

	while (i < 2)
	{
		n = 1;
		while (n > i)
		{
			distance = get_distance(*master->boids[i], *master->boids[n]);
			if (distance <= (CLOSE_R * CLOSE_R))
			{
				move_away(master->boids[i], master->boids[n]);
				//printf("Dist %d, Old %f, new %d\n\n",distance, master->boids[i]->direction,master->boids[i]->vars.close);
			}
			/*else  if (distance <= AWAY_R * AWAY_R)
				move_closer(master->boids[i], master->boids[n]);
			else if (distance <= FOLLOW_R * FOLLOW_R)
				follow(master->boids[i], master->boids[n]); */
			n--;
		}
		/* if (timer >= 100)
		{
			master->boids[i]->direction = (rand() % 360);
			timer = 0;
			//printf("Boid dir %d\n", master->boids[i]->vars.newdir);
		} */
		apply_transforms(master->boids[i], master);
		i++;
	}
	timer++;
	render(master);
}

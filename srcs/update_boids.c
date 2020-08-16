#include "b2d.h"

void render(Master *master)
{
	SDL_Rect rect;
	int  i = 0;

	rect.h = WIN_H / 100;
	rect.w = WIN_W / 100;
	SDL_SetRenderDrawColor(master->renderer, 0, 255, 0, 255);
	while (i < BOIDNO)
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
		total += close;
		t_div++;
	}
	if (boid->vars.mid > 0)
	{
		mid = boid->vars.mid;

		mid /= boid->vars.div_mid;
		total += mid;
		t_div++;
	}
	if (boid->vars.far > 0)
	{
		far = boid->vars.far;
		far /= boid->vars.div_far;
		total += far;
		t_div++;
	}
	if (t_div > 0)
		boid->direction = (total + boid->direction)/(t_div + 1);

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
	boid->vars.mid = 0;
	boid->vars.div_mid = 0;
	boid->vars.far = 0;
	boid->vars.div_far = 0;

	if (dir_x >= (WIN_W - 10))
		boid->position.x = 0;
	else if (dir_x <= 0)
		boid->position.x = WIN_W - 10;
	else
		boid->position.x = dir_x;
	if (dir_y >= (WIN_H - 10))
		boid->position.y = 0;
	else if (dir_y <= 0)
		boid->position.y = WIN_H - 10;
	else
		boid->position.y = dir_y;
}

void update_simple(Master *master)
{
	int i, n, distance;
	static int timer;
	i = 0;

	while (i < BOIDNO)
	{
		n = BOIDNO - 1;
		while (n > i)
		{
			distance = get_distance(master->boids[i], master->boids[n]);
			if (distance <= (CLOSE_R * CLOSE_R))
				move_away(master->boids[i], master->boids[n]);
			else if (distance <= AWAY_R * AWAY_R)
				move_closer(master->boids[i], master->boids[n]);
			else if (distance <= FOLLOW_R * FOLLOW_R)
				follow(master->boids[i], master->boids[n]);
			n--;
		}
		if (timer >= 100)
		{
			master->boids[i]->direction = (rand() % 360);
			timer = 0;
		}
		apply_transforms(master->boids[i], master);
		i++;
	}
	timer++;
	render(master);
}

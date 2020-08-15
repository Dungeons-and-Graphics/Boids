#ifndef B2D_STRUCTS_H
# define B2D_STRUCTS_H
# include "b2d.h"

struct s_list;

typedef struct s_list Node;

typedef struct s_vector2
{
	double x, y;
}				Vector2;

typedef struct s_vars
{
	double div_close, div_mid, div_far;
	double close, mid, far;
	double newdir;
}				Influence;

typedef struct	s_boids
{
	Influence vars;
	Vector2 position;
	double	direction;
}				Boid;

typedef struct s_list
{
	Boid **boid;
	int num_elems;
}				List;

typedef struct s_master
{
	List *grid;
	Boid **boids;

	SDL_Renderer *renderer;
	SDL_Window *window;
}				Master;

#endif

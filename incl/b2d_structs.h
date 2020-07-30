#ifndef B2D_STRUCTS_H
# define B2D_STRUCTS_H
# include "b2d.h"

struct s_list;

typedef struct s_list Node;

typedef struct s_vector2
{
	int x, y;
}				Vector2;

typedef struct	s_boids
{
	Vector2 position;
	double	direction;
}				Boid;

typedef struct s_list
{
	Boid *boid;
	Node *next;
	Node *head;
	Node *tail;
}				Node;

typedef struct s_master
{
	int cell_no;
	Node **Grid;

	SDL_Renderer *renderer;
	SDL_Window *window;
}				Master;

#endif

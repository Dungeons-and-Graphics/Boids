#ifndef B2D_H
# define B2D_H
# include <SDL2/SDL.h>
# include <stdlib.h>
# include "b2d_structs.h"

# define WIN_W 1000
# define WIN_H 500
# define AWAY_R 80
# define CLOSE_R 20
# define FOLLOW_R 60
# define BOIDNO 50

/*   File : init.c   */
Master	*init();

/*   File : utils.c   */
void	move_away(Boid *boid, Boid *target);
void	move_closer(Boid *boid, Boid *target);
void	follow(Boid *boid, Boid *target);
int		get_distance(Boid *a, Boid *b);
double	to_deg(double angle);
double	to_rad(double angle);

/*   File : update_boids.c */
void update(Master *master, int m_x, int m_y);
void update_simple(Master *master);

#endif

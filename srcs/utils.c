#include "b2d.h"

double to_rad(double angle)
{
	double result;

	result = angle * M_PI;
	result /= 180;

	return result;
}

double to_deg(double angle)
{
	double result;

	result = angle * 180;
	result /= M_PI;

	return result;
}

int convert_angle(int result)
{
	if (result >= 0)
		return result;
	result *= - 1;

	return (180 + result);
}

int get_distance(Boid *a, Boid *b)
{
	int x, y;
	double dist;

	x = a->position.x - b->position.x;
	y = a->position.y - b->position.y;
	dist = (x * x) + (y * y);
	return abs((int)dist);
}


void move_away(Boid *boid, Boid *target)
{
	int newdir, x, y ,i = 0, n;

	x = target->position.x - boid->position.x;
	y = target->position.y - boid->position.y;

	newdir = convert_angle(to_deg(atan2(y, x)));
	target->vars.div_close++;
	target->direction = newdir;
	target->vars.close += newdir;

	newdir += 180;
	if (newdir > 360)
		newdir -= 360;
	boid->vars.div_close++;
	boid->direction = newdir;
	boid->vars.close += newdir;
}

void move_closer(Boid *boid, Boid *target)
{
	int newdir, x, y ,i = 0, n;

	x = target->position.x - boid->position.x;
	y = target->position.y - boid->position.y;


	newdir = convert_angle(to_deg(atan2(y, x)));
	target->vars.div_mid++;
	target->vars.mid += newdir;

	newdir += 180;
	if (newdir > 360)
		newdir -= 360;
	boid->vars.div_mid++;
	boid->vars.mid += newdir;
}

void follow(Boid *boid, Boid *target)
{
	boid->vars.div_far++;
	boid->vars.far += target->direction;

	target->vars.div_far++;
	target->vars.far += boid->direction;
}

/*
void move_closer(Boid *boid, Boid target)
{

}

void follow(Boid *boid, Boid target)
{

}
 */

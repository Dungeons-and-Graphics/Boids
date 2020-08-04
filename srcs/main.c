#include "b2d.h"

int main()
{
	Master *master;
	int mouse_x, mouse_y;


	master = init();

	while (1)
	{
        SDL_Event event;
        while (SDL_PollEvent(&event))
		{
        	switch (event.type)
			{
				case SDL_QUIT:
					exit(0);
				case SDL_MOUSEMOTION:
					SDL_GetMouseState(&mouse_x, &mouse_y);
			}
		}
		update(master, mouse_x, mouse_y);
	}
}


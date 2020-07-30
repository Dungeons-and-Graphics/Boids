NAME= Boid2D
FLAGS= -Wall -Wextra -Werror

FILES= main init utils update_boids
INCL = -I incl/
SLIB = -L ~/.brew/lib  -l SDL2 -l sdl2_image

SRCS= $(addprefix srcs/, $(addsuffix .c, $(FILES)))
OBJS= $(addprefix objs/, $(addsuffix .o, $(FILES)))

all: $(NAME)

objs/%.o: srcs/%.c
	@/bin/mkdir -p objects
	gcc $(FLAGS) -c $(INCL) $< -o $@

$(NAME): $(OBJS)
	gcc $(FLAGS) $(INCL) $(SLIB) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

push: clean
	git add .
	git commit -m "$(MSG)"
	git push repo master

re: fclean all

.PHONY: $(NAME) clean fclean push re


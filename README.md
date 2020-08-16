# Boids
Flocking simulation.

 - [x] Rule 1: Move away

  - [x] Rule2 : Move closer

  - [x] Rule3 : Follow


----------------------------

## TODO

  - [ ] Follow mouse

  - [ ] Avoid Obstacles

  - [ ] TUrn rules on and off

  - [x] Refactor

  - [ ] Fix wall bounce

## NOTES

At the moments, each boid is checking the position and orientation of every other boid in the simulation, altough simple this method is highly unneficent and I intend to replace it some day
in (hopefully) the close future.

On collision with a wall the boid will be teleported to the other side of the screen. That is because if they bounce off the wall, they simply become stuck and they all end up forming a nice line alongside it. I probably won't fix this though

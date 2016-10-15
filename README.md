# GameOfLife
This is a shcool project, the goal is to provide a view of the evolution of a given initial generation.

## what is it ?
let's ask wikipedia:

> The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970.
>
> It's a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input.
> One interacts with the Game of Life by creating an initial configuration and observing how it evolves, or, for advanced
> "players", by creating patterns with particular properties.

## What are the rules of the evolution ?

wikipedia again:

>   * Any live cell with fewer than two live neighbours dies, as if caused by under-population.
>   * Any live cell with two or three live neighbours lives on to the next generation.
>   * Any live cell with more than three live neighbours dies, as if by over-population.
>   * Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.


In my program, a live cell is represented by this image: ![alt text] (media/alive.png "cell alive")

and a dead one by: ![alt text] (media/dead.png "cell dead")

# How can I create an exectuable file ?
## If you use Linux:

1. You have to clone or download the repo.
2. Open a terminal and run 
    * `cd path/to/GameOfLife/`
    * `make`
3. That's it ! Now you can run 
    * `./prog.out`

## Else: try linux :p

# What should I do know ?
The programm is asking you:

   * the number of generation you want,
   * if you want to disable the border (if you disable them every cell will have eight neighbor),
   * and a file to open. Some example are in the firstGeneration folder but feel free to create your own !!
  
know enjoy ! :D

# What libraries did I use ?
I use the __SDL2__ (Simple Direct-media Layer) with __SDL image 2.0__. They are used to do all the displaying.

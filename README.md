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
    -> it didn't work ? See the last point to install the libs.
3. That's it ! Now you can run one of these:
    * `./prog.out` firstGeneration/heart.txt is my favorite :p
    * `./prog.out --createMode <name of your invention>` to create your own

## Else: try linux :p

# What should I do now ?
The programm is asking you:

   * if you want to disable the border (if you disable them every cell will have eight neighbor),
   * and a file to open. 
   Some example are in the firstGeneration folder but feel free to create your own with the create Mode !!
   You can find your creation in the myCreation folder. 
  
now enjoy ! :D

# What libraries did I use ?
I use the __SDL2__ (Simple Direct-media Layer) with __SDL image 2.0__. They are used to do all the displaying.

## Install the SDL2 and SDL image with or without super user rights:

To simplify we will say that those who have super user rights and want to install it globally teamA and the other teamB. 
For both methods, we are going to compile it from source, you can do it on linux, mac and windows (command are given for linux so you may have to find the equivalent on windows):

   * first you have to download the source from [here](http://libsdl.org/download-2.0.php) for the SDL2 (choose SDL2-2.0.4.tar.gz or .zip) and [here](https://www.libsdl.org/projects/SDL_image) for SDL Image 2.0 (choose  SDL2_image-2.0.1.tar.gz or .zip).
   * then unarchive them.
   * open a terminal and run (if you are in teamA, skip 1 and 2):
   
      1-  `cd` this command take you into youre home
      
      2-  `mkdir SDL` this one create the directory where we will install the SDL
      
      3-  `cd path/to/the/download/source1` where path to the download is the path to go in the folder where you unarchive the source, and source1 one of the two result.
      
      4A- run `./configure` for teamA
      
      4B- or `./configure --prefix=$HOME/SDL` for teamB
      
      5-  `make`
      
      6A- `sudo make install` for teamA (obviously because of the sudo :p)
      
      6B- `make install` for teamB
      
      7-  now go to step three and do it again for the other source.




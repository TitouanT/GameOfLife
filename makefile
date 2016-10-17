# Titouan Teyssier, 10/14/2016
#  titouan.teyssier@gmail.com

#if you followed my tuto to install the sdl in your home,
#uncomment the lines 7 and 8.

#LIB = -L $HOME/SDL/lib
#INCLUDE = -I $HOME/SDL/include

all: prog.out

prog.out: main.o core.o display.o createMode.o
	gcc -o $@ $^ ${LIB} -lSDL2-2.0 -lSDL2_image

main.o: main.c main.h core.h display.h structure.h
	gcc -c $<

createMode.o: createMode.c createMode.h
	gcc -c $<

core.o: core.c core.h
	gcc -c $<

display.o: display.c display.h
	gcc -c $< ${INCLUDE}

display.h: structure.h

core.h: structure.h

clean:
	rm *.o

mrproper:
	rm *.o *.out

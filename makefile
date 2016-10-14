LIB = -L./lib
INCLUDE = -I./include

all: prog.out

prog.out: main.o core.o display.o
	gcc -o $@ $^ ${LIB} -lSDL2-2.0 -lSDL2_image

main.o: main.c core.h display.h structure.h
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

all: clean main
	

data.o: data.h
	gcc -c data.c

main.o: data.h
	gcc -c main.c

main: main.o data.o
	gcc -o main main.o data.o -lfreeglut -lopengl32 -lglu32

clean:
	rm *.o




all: main.o lib.o node.o
	gcc -o main main.o lib.o node.o
	make clean

main.o:
	gcc -c main.c lib.h node.h

lib.o:
	gcc -c lib.c lib.h

node.o:
	gcc -c node.c node.h

run:
	./main

clean:
	rm *.o
	rm *.gch

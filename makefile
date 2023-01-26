all:
	gcc -g -o main.o main.c list.c

test:
	gcc -o test.o test.c


test2:
	gcc -o test2.o test2.c
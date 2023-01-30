all:
	gcc -g -o main.o main.c list.c

clean:
	rm -f ./main.o
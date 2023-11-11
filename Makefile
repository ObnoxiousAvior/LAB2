all: main.o func.o search.o
	gcc main.o func.o search.o -o LAB2
func.o:	func.c
	gcc -c func.c
search.o: search.c
	gcc -c search.c
main.o: main.c
	gcc -c main.c
clear:
	rm *.o

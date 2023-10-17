all: selectionSort.exe 

selectionSort.exe: selectionSort.c vector.o
	gcc selectionSort.c vector.o -o selectionSort.exe

vector.o: vector.h vector.c
	gcc -c vector.c -o vector.o

clean:
	del *.exe *.o
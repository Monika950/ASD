all: a.exe a1.exe

a.exe: QuickSort.c vector.o
	gcc QuickSort.c vector.o -o a.exe

a1.exe: QuickLometo.c vector.o 
	gcc QuickLometo.c vector.o -o a1.exe
	
vector.o: vector.h vector.c
	gcc -c vector.c -o vector.o

clean:
	del *.exe *.o
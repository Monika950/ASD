all: main.exe 

main.exe: main.c skiplist.o
	gcc main.c skiplist.o -o a.exe

skiplist.o: skiplist.h skiplist.c
	gcc -c skiplist.c -o skiplist.o

clean:
	del *.exe *.o
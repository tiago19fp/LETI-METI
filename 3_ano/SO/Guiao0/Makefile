
final: main.o fill.o
	gcc main.o fill.o -o final

main.o:
	gcc -c main.c

fill.o: fill.c header.h
	gcc -c fill.c

clean:
	rm *.o final

all:
	gcc -c *.c
	gcc -o bin *.o -lm
	rm *.o

debug:
	gcc -c -ggdb *.c
	gcc -o bin *.o -lm -ggdb

clean:
	rm -f bin *.o

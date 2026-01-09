C_FILES=*.c ../util/grids.c
LD_OPTS=-lm -I./../util/

all:
	gcc -c ${C_FILES}
	gcc -o solution11 *.o ${LD_OPTS}  
	rm *.o

debug:
	gcc -c -ggdb ${C_FILES}
	gcc -o solution11 *.o ${LD_OPTS} -ggdb

clean:
	rm -f solution11 *.o

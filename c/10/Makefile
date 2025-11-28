C_FILES=*.c ../util/primes.c
LD_OPTS=-lm -I./../util

all:
	gcc -c ${C_FILES}
	gcc -o solution10 *.o ${LD_OPTS}  
	rm *.o

debug:
	gcc -c -ggdb ${C_FILES}
	gcc -o solution10 *.o ${LD_OPTS} -ggdb

clean:
	rm -f solution10 *.o

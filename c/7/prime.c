#include <stdio.h>

#include "../util/primes.h"

int main()
{
	int cur = 3;
	int index = 2;

	while( index < 10001 ){
		cur+=2;
		if( is_prime(cur) ){
			index++;
		}
	}

	printf("%d\n", cur);

	return 0;
}

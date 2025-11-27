#include <stdio.h>
#include <math.h>
#include "../../util/primes.h"

int main()
{
	long int num = 600851475143;

	long int max_possible = ceil(sqrt(num));

	if (max_possible % 2 == 0) {
		max_possible--;
	}

	for (int i = max_possible; i > 1; i-=2) {
		if (num % i == 0 && is_prime(i)) {
			printf("%d\n", i);
			return 0;
		}
	}

	return 1;
}

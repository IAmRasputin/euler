#include <stdio.h>
#include "../util/primes.h"

int main() {
	long acc = 0;
	int cur = 2;

	while (cur < 2000000) {
		if (is_prime(cur)) {
			acc += cur;
		}

		cur++;
	}

	printf("%ld\n", acc);
}

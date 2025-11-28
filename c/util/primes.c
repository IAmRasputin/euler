#include "primes.h"
#include <math.h>

int is_prime(int num) {
	if (num <= 1) {
		return 0;
	}

	if (num == 2 || num == 3) {
		return 1;
	}
	
	double limit = sqrt(num);

	int to_check = 2;
	if (num % to_check == 0) {
		return 0;
	}
	to_check++;

	while (to_check <= limit) {
		if (num % to_check == 0) {
			return 0;
		}

		to_check += 2;
	}

	return 1;
}

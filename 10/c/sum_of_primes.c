#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Unsigned long long because why not?
int is_prime(const long long int num)
{
	int result = 1;

	if (num <= 1) {
		result = 0;
	} else if (num >= 3) {
		long long int index = 2;
		long double sqrt_of_num = sqrtl((long double) num);

		for (; index <= sqrt_of_num; index++) {
			if (num % index == 0) {
				result = 0;
				break;
			}
		}
	}

	return result;
}


int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Usage: ./bin [number]\n");
		exit ( EXIT_FAILURE );
	}

	long long int num = (long long int) atoll(argv[1]);
	long long int sum = 0;

	for (long long int i = 2; i < num; i++) {
		if (is_prime(i)) {
			sum += i;
		}
	}

	printf("The sum of primes below %llu is %llu.\n", num, sum);

	return 0;
}

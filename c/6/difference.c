#include <stdio.h>

int sum_of_squares(int max) {
	int acc = 0;

	for (int i = 1; i <= max; i++) {
		acc += (i * i);
	}

	return acc;
}

int square_of_sum(int max) {
	int acc = 0;

	for (int i = 1; i <= max; i++) {
		acc += i;
	}

	return acc * acc;
}

int main() {
	int result = square_of_sum(100) - sum_of_squares(100);

	printf("%d\n", result);

	return 0;
}

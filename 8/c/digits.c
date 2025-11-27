/*
 * Find the thirteen adjacent digits in the 1000-digit number that have the 
 * greatest product. What is the value of this product?
 *
 * Digits located in Problem8.txt
 */
#include <stdio.h>

int main() {
	FILE *numbers_file = fopen("digits.txt", "r");
	unsigned int index = 0, digits[1000];
	int read;

	if (!numbers_file) {
		return 1;
	}

	while ((read = fgetc(numbers_file)) != EOF) {
		if (read != '\n') {
			digits[index] = read - '0';
			index++;
		}
	}

	fclose(numbers_file);

	long max = 0;
	int i = 0;

	while (i+12 < 1000) {
		long product = digits[i];
		for (int x = i+1; x <= i+12; x++) {
			product *= digits[x];
		}

		if (max < product) {
			max = product;
		}

		i++;
	}

	printf("%ld\n", max);

	return 0;
}

/*
 * Find the thirteen adjacent digits in the 1000-digit number that have the 
 * greatest product. What is the value of this product?
 *
 * Digits located in Problem8.txt
 */
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv )
{
	// Create a buffer for 1000 digits, feed the contents of digits.txt 
	// into them.
	FILE *numbers_file = fopen("digits.txt", "r");
	int input; 
	unsigned int index = 0, digits[1000];
	unsigned long long max = 0;


	if (!numbers_file) {
		exit(EXIT_FAILURE);
	}

	while ((input = fgetc(numbers_file)) != EOF) {
		if (input != '\n' && index < 1000) {
			digits[index] = atoi((const char *) &input);
			index++;
		}
	}

	index = 0;
	while (index + 12 <= 1000) {
		unsigned long long cur = 1;

		for (int i = index; i <= (index + 12); i++) {
			cur *= digits[i];
		}

		if (cur > max) {
			max = cur;
		}

		index++;
	}

	fclose(numbers_file);

	printf("%llu\n", max);
}

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
	// Create a buffer for 1000 digits, feed the contents of Problem8.txt 
	// into them.
	FILE *numbers_file = fopen("digits.txt", "r");

	if (!numbers_file) {
		printf("Either the file's missing or it returned null for some\
			reason.  either way, it's not open.");
		exit(EXIT_FAILURE);
	}

	int index = 0, max = 0, digits[1000];
	char input;

	while ((input = fgetc(numbers_file)) != EOF) {
		printf("%d\n", atoi(&input));
		if (input != '\n' && index < 1000) {
			digits[index] = atoi(&input);
			index++;
		}
	}

	index = 0;
	while (index + 12 <= 1000) {
		unsigned long long int cur = 1;
		for (int i = index; i <= (index + 12); i++) {
			cur *= digits[i];
		}

		if (cur > max)
			max = cur;

		index++;
	}

	fclose(numbers_file);

	printf("%d\n", max);
}

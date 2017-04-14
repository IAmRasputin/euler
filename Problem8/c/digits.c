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
	FILE *numbers_file = fopen("Problem8.txt", "r");

	int index = 0, max = 0;
	char digits[1000], input;

	while ((input = fgetc(numbers_file)) != EOF) {
		if (input != '\n' && index <= 1000) {
			digits[index] = atoi(&input);
			index++;
		}
	}

	index = 0;
	while (index + 12 <= 1000) {
		unsigned long long int cur = 1;
		for (int i = index; (i + 12) <= 1000; i++) {
			cur *= digits[i];
		}

		printf("Product of ");
		
		for (int i = 0; i < 13; i++) {
			printf("%d ", digits[index + i]);
		}
		
		if (cur > max) {
			max = cur;
			printf(" *MAX*");
		}

		printf("\n");


		index++;
	}

	fclose(numbers_file);

	printf("%d\n", max);
}

#include <stdio.h>

int main()
{
	int sumSquares;
	int squareSums;
	int diff;
	int i;

	for( i = 1; i <= 100; i++ ){
		sumSquares += (i * i);
		squareSums += i;
	}

	diff = (squareSums * squareSums) - sumSquares;

	printf("%d\n", diff);

	return 0;
}

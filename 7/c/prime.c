#include <stdio.h>
#include <math.h>

int isPrime(int number)
{
	int i = 2;
	int result = 1;

	for (; i <= sqrt((double)number); i++){
		if ( number % i == 0 ){
			result = 0;
		}
	}

	return result;
}

int main()
{
	int cur = 2;
	int index = 1;

	while( index < 10001 ){
		cur++;
		if( isPrime( cur ) ){
			index++;
		}
	}

	printf("%d\n", cur);

	return 0;
}

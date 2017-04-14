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
	long int num = 600851475143;	

	int i = 3;

	int cur = 0;

	for( ; i <= sqrt((double)num) ; i++ ){
		if (isPrime(i)){
			if (num % i == 0){
				cur = i;
			}
		}
	}

	printf("%d\n", cur);
	
	return 0;
}

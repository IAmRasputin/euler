#include <stdio.h>

int main()
{
	int sum = 0;

	int i;

	for (i = 1; i < 1000; i++){
		if (i % 3 == 0)
			sum += i;
		else if (i % 5 == 0)
			sum += i;
	}
	
	printf("%d\n", sum);
}

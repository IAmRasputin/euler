#include <stdio.h>

int main() {
	int h = 1, i = 2, j = 3, evens_sum = 2;

	while (j <= 4000000) {
		h = i;
		i = j;
		j = h + i;

		if (j % 2 == 0) {
			evens_sum += j;
		}
	}

	printf("%d\n", evens_sum);
}

#include <stdio.h>

int multiple_of_all(int num) {
	int candidates[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};
	
	for (int i = 0; i < 10; i++) {
		if (num % candidates[i] != 0) {
			return 0;
		}
	}

	return 1;
}

int main() {
	int num = 20;

	while (!multiple_of_all(num)) {
		num += 20;
	}

	printf("%d\n", num);

	return 0;
}

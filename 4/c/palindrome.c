#include <stdio.h>

int is_palindrome(long num) {
	char num_str[64];
	sprintf(num_str, "%ld", num);
	
	int end_ptr = 0;

	while (end_ptr < 64 && num_str[end_ptr] != '\0') {
		end_ptr++;
	}

	end_ptr--;

	int start_ptr = 0;

	while (start_ptr < end_ptr) {
		if (num_str[start_ptr] != num_str[end_ptr]) {
			return 0;
		}

		start_ptr++;
		end_ptr--;
	}

	return 1;
}

int main() {
	long max = 0;

	for (int x = 100; x <= 999; x++) {
		for (int y = 100; y <= 999; y++) {
			long cur = x * y;

			if (is_palindrome(cur) && max < cur) {
				max = cur;
			}
		}
	}

	printf("%ld\n", max);
}
					

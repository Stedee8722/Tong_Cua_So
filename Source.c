#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main() {
	int n;
	long long a;
	scanf_s("%d", &n);
	scanf_s("%lld", &a);
	int nums_of_zeros = 0;
	int nums_of_nines = 0;
	int num_shifted = 0;
	int debt = 0;
	long long addition = 0;
	int first_char = 0;
	bool found = false;

	// walking through number's char from the last
	for (int i = 1; i <= n; i++) {
		int char_of_a = a % 10;
		a = a / 10;
		if (!found) {
			if (char_of_a != 0) {
				if (i == n) {
					printf_s("Khong tim duoc");
					return;
				}
				num_shifted = char_of_a - 1;
				nums_of_zeros = i;
				found = true;
			}
		}
		else {
			if (char_of_a == 9) {
				if (i == n) {
					printf_s("Khong tim duoc");
					return;
				}
				debt += 9;
			}
			else {
				nums_of_nines = i - nums_of_zeros - 1;
				a = a * 10 + char_of_a + 1;
				break;
			}
		}
	}
	// adding the rest of the num of char back as 0s
	a = a * pow(10, nums_of_nines + nums_of_zeros);

	// calculating the new additions to make it smallest
	first_char = debt % 9;
	if (first_char + num_shifted > 9) {
		addition = abs(num_shifted - first_char);
		for (int i = 1; i <= debt / 9; i++)
			addition =+ addition * 10 + 9;
	}
	else {
		addition = num_shifted + first_char;
		for (int i = 1; i <= debt / 9; i++)
			addition =+ addition * 10 + 9;
	}

	// you know what this is lmao
	printf_s("%lld", a + addition);

}
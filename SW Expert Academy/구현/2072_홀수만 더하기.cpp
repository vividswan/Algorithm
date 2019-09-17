#include <iostream>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int sum = 0;
		for (int i = 1; i <= 10; i++) {
			int num;
			scanf("%d", &num);
			if (num % 2) sum += num;
		}
		printf("#%d %d\n", i, sum);
	}
	return 0;
}
#include <iostream>
using namespace std;
int main(void) {
	int num;
	scanf("%d", &num);
	int i;
	for (i = 1; 1; i++) {
		if ((i - 1) * i / 2 < num && num <= i * (i + 1) / 2) break;
	}
	int j = num - (i - 1) * i / 2;
	if (!(i % 2)) {
		printf("%d/%d", j, (i - j + 1));
		return 0;
	}
	else {
		printf("%d/%d", (i - j + 1), j);
		return 0;
	}
}
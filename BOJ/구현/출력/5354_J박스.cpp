#include <iostream>
using namespace std;
void printFunction(int val) {
	for (int i = 1; i <= val; i++) printf("#");
	printf("\n");
	for (int i = 2; i <= val - 1; i++) {
		for (int j = 1; j <= val; j++) {
			if (j == 1 || j == val) {
				printf("#");
				continue;
			}
			printf("J");
		}
		printf("\n");
	}
	if (val != 1) {
		for (int i = 1; i <= val; i++) printf("#");
		printf("\n");
	}
	printf("\n");
}
int main(void) {
	int testCase;
	scanf("%d", &testCase);
	while (testCase--) {
		int val;
		scanf("%d", &val);
		printFunction(val);
	}
	return 0;
}
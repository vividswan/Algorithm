#include<stdio.h>
int c = 0;
int main(void) {
	int task, go5, go3, result;
	c == 0;
	scanf("%d", &task);
	for (go3 = 0; 1700 >= go3; go3++) {
		for (go5 = 0; 1000 >= go5; go5++) {
			result = 5 * go5 + 3 * go3;
			if (task == result) {
				printf("%d", go3 + go5);
				c++;
				task = -10;
				break;
			}
			else continue;
		}
	}
	if (c == 0) printf("-1");
	return 0;
}
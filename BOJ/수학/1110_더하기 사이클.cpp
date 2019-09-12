#include <stdio.h>
int main(void) {
	int score, first, roof, result, re;
	re = 0;
	scanf("%d", &score);
	first = score;
	for (roof = 1; roof; roof++) {
		result = (score / 10 + score % 10) % 10 + (score % 10) * 10;
		if (first == result) {
			re = roof;
			break;
		}
		else {
			score = result;
			continue;
		}
	}
	printf("%d", re);
	return 0;
}
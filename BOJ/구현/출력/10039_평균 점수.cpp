#include<stdio.h>
int main(void) {
	int grade[6];
	int roof;
	for (roof = 1; 5 >= roof; roof++) {
		scanf("%d", &grade[roof]);
		if (grade[roof] < 40) grade[roof] = 40;
	}
	printf("%d", (grade[1] + grade[2] + grade[3] + grade[4] + grade[5]) / 5);
}
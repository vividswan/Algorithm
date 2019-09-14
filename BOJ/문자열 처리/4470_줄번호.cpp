#include<stdio.h>
int t;
int main(void) {
	scanf("%d ", &t);
	int cnt = 1;
	for (int i = 1; i <= t; i++) {
		int task;
		char con[55];
		gets(con);
		printf("%d. %s\n", cnt, con);
		cnt += 1;
	}
	return 0;
}
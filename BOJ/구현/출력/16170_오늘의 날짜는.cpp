#include <stdio.h>
#include <time.h>
int main(void) {
	time_t now_t;
	time(&now_t);
	struct tm* now;
	now = localtime(&now_t);
	printf("%d\n%d\n%d\n", now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
	return 0;
}
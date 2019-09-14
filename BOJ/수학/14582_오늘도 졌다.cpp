#include <iostream>
using namespace std;
int gem[10], sta[10];
int sum_gem, sum_sta, swc;
int main(void) {
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &gem[i]);
	}
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &sta[i]);
	}
	for (int i = 1; i <= 9; i++) {
		sum_gem += gem[i];
		if (sum_gem > sum_sta) {
			swc++;
			break;
		}
		sum_sta += sta[i];
	}
	if (swc) printf("Yes");
	else printf("No");
}
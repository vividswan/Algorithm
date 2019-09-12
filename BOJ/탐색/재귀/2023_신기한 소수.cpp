#include <iostream>
#include <cmath>
using namespace std;
int n;
int confi(int num);
void dfs(int now, int depth);
int go[] = { 2,3,5,7 };
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		dfs(go[i], 1);
	}
	return 0;
}
int confi(int num) {
	if (num == 1) return 0;
	else {
		for (int i = 2; i <= sqrt(num); i++) {
			if (num % i == 0) return 0;
		}
	}
	return 1;
}
void dfs(int now, int depth) {
	if (depth == n) {
		printf("%d\n", now);
	}
	for (int i = 1; i <= 9; i += 2) {
		if (confi(10 * now + i)) {
			dfs(10 * now + i, depth + 1);
		}
	}
}
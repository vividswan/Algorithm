#include <iostream>
using namespace std;
int vis[1000];
int res = 9 * 9 * 9;
int main(void) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		int firstNum = num / 100;
		int secondNum = (num / 10) % 10;
		int thirdNum = num % 10;
		int strike, ball;
		scanf("%d%d", &strike, &ball);
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				for (int l = 1; l <= 9; l++) {
					int value = 100 * j + 10 * k + l;
					if (vis[value]) continue;
					if (j == k || j == l || k == l) {
						vis[value] = 1;
						res--;
						continue;
					}
					int nowStrike = 0;
					int nowBall = 0;
					int isStrike[1000] = { 0, };
					if (j == firstNum) {
						nowStrike++;
						isStrike[j]++;
					}
					if (k == secondNum) {
						nowStrike++;
						isStrike[k]++;
					}
					if (l == thirdNum) {
						nowStrike++;
						isStrike[l]++;
					}
					if (!isStrike[j]) {
						if (j == secondNum || j == thirdNum) nowBall++;
					}
					if (!isStrike[k]) {
						if (k == firstNum || k == thirdNum) nowBall++;
					}
					if (!isStrike[l]) {
						if (l == firstNum || l == secondNum) nowBall++;
					}
					if (strike == nowStrike && ball == nowBall) continue;
					else {
						vis[value]++;
						res--;
					}
				}
			}
		}
	}
	/*
	for (int j = 1; j <= 9; j++) {
		for (int k = 1; k <= 9; k++) {
			for (int l = 1; l <= 9; l++) {
				int value = 100 * j + 10 * k + l;
				if (!vis[value]) printf("%d\n", value);
			}
		}
	}
	*/
	printf("%d\n", res);
	return 0;
}
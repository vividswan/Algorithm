#include <iostream>
using namespace std;
int D, K;
pair<int, int> chk[31];
int main(void) {
	scanf("%d%d", &D, &K);
	chk[1] = { 1,0 };
	chk[2] = { 0,1 };
	for (int i = 3; i <= D; i++) {
		chk[i].first = chk[i - 1].first + chk[i - 2].first;
		chk[i].second = chk[i - 1].second + chk[i - 2].second;
	}
	for (int i = 0; i <= 100000; i++) {
		for (int j = 0; j <= 100000; j++) {
			if (K == chk[D].first * i + chk[D].second * j) {
				printf("%d\n%d\n", i, j);
				return 0;
			}
		}
	}
}
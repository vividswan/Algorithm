#include <iostream>
using namespace std;
pair<int, int> pibo[42];
int main(void) {
	pibo[0] = { 1,0 };
	pibo[1] = { 0,1 };
	int t;
	scanf("%d", &t);
	for (int i = 2; i <= 40; i++) {
		pibo[i].first = pibo[i - 1].first + pibo[i - 2].first;
		pibo[i].second = pibo[i - 1].second + pibo[i - 2].second;
	}
	while (t--) {
		int num;
		scanf("%d", &num);
		printf("%d %d\n", pibo[num].first, pibo[num].second);
	}
	return 0;
}

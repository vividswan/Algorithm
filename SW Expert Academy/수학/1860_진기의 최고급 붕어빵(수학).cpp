#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int T,total;
int main(void) {
	scanf("%d", &T);
	total = T;
	while (T--) {
		int N, M, K;
		int visit[11112];
		memset(visit, 0, sizeof(visit));
		scanf("%d%d%d", &N, &M, &K);
		int maxTime = 0;
		for (int i = 1; i <= N; i++) {
			int order;
			scanf("%d", &order);
			maxTime = max(maxTime, order);
			visit[order]++;
		}
		int nowTime = 0;
		int value = 0;
		int impossibleSwc = 0;
		for (int i = 0; i <= maxTime; i++) {
			if (i % M == 0 && i!=0) value += K;
			int nowMake = visit[i];
			value -= nowMake;
			if (value < 0) {
				impossibleSwc++;
				break;
			}
		}
		if (impossibleSwc) printf("#%d Impossible\n",total-T);
		else printf("#%d Possible\n", total - T);
	}
	return 0;
}
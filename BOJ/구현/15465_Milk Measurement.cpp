#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int maxx = 7;
int arr[3];
int cnt;
int tot[3], now[3];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
int main(void) {
	for (int i = 0; i < 3; i++) {
		arr[i] = 7;
		tot[i] = 1;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		char c[100];
		scanf("%d", &a);
		scanf(" %s", &c);
		scanf("%d", &b);
		int d;
		if (c[0] == 'M') d = 0;
		else if (c[0] == 'E') d = 1;
		else d = 2;
		pq.push({ a,{d,b} });
	}
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		arr[a] += b;
		int now_max = 0;
		for (int i = 0; i < 3; i++) {
			now_max = max(now_max, arr[i]);
		}
		for (int i = 0; i < 3; i++) {
			if (now_max == arr[i]) now[i] = 1;
			else now[i] = 0;
		}
		int now_swc = 0;
		for (int i = 0; i < 3; i++) {
			if (tot[i] == now[i]) now_swc++;
		}
		if (now_swc == 3) continue;
		else {
			cnt++;
			for (int i = 0; i < 3; i++) {
				tot[i] = now[i];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
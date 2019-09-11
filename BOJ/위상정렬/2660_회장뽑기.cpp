#include <iostream>
#include <algorithm>
#include <queue>
#define INF 12345678
using namespace std;
int arr[51][51], n, res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) arr[i][j] = 1;
			else arr[i][j] = INF;
		}
	}
	while (1) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == -1 && b == -1) break;
		else {
			arr[a][b] = 1;
			arr[b][a] = 1;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	res = INF;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cnt = max(cnt, arr[i][j]);
		}
		res = min(res, cnt);
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			cnt = max(cnt, arr[i][j]);
		}
		if (res == cnt) q.push(i);
	}
	printf("%d %d\n", res, q.size());
	while (!q.empty()) {
		printf("%d ", q.front());
		q.pop();
	}
}
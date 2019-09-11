#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 99876543210
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, p, q, meet[101];
		scanf("%d%d%d", &n, &p, &q);
		vector<vector<pair<int, int>>> adj;
		adj.resize(p + 1);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &meet[i]);
		}
		long long arr[101][101] = { 0, };
		for (int i = 1; i <= p; i++) {
			for (int j = 1; j <= p; j++) {
				if (i == j) continue;
				arr[i][j] = INF;
			}
		}
		for (int i = 1; i <= q; i++) {
			int a, b;
			long long c;
			scanf("%d%d%lld", &a, &b, &c);
			arr[a][b] = min(arr[a][b], c);
			arr[b][a] = min(arr[b][a], c);
		}
		for (int k = 1; k <= p; k++) {
			for (int i = 1; i <= p; i++) {
				for (int j = 1; j <= p; j++) {
					if (arr[i][j] > arr[i][k] + arr[k][j]) {
						arr[i][j] = arr[i][k] + arr[k][j];
					}
				}
			}
		}
		long long res = INF;
		int now = 0;
		for (int k = 1; k <= p; k++) {
			long long swc = 0;
			int no_res = 0;
			for (int i = 1; i <= n; i++) {
				if (arr[meet[i]][k] >= INF) {
					no_res++;
					break;
				}
				swc += arr[meet[i]][k] * arr[meet[i]][k];
			}
			if (no_res) continue;
			res = min(res, swc);
			if (res == swc) {
				now = k;
			}
		}
		printf("%d %lld\n", now, res);
	}
}
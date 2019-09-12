#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;
int n, m, q;
long long arr[501][501];
long long dist[501][501];
long long dog[501];
long long dog_map[501][501];
vector<pair<long long, int>> w;
int main(void) {
	scanf("%d%d%d", &n, &m, &q);
	w.resize(n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &dog[i]);
		w[i - 1] = { dog[i],i };
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else {
				arr[i][j] = INF;
				dist[i][j] = INF;
			}
		}
	}
	sort(w.begin(), w.end());
	for (int i = 1; i <= m; i++) {
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		arr[a][b] = c;
		arr[b][a] = c;
		dist[a][b] = c + max(dog[a], dog[b]);
		dist[b][a] = c + max(dog[a], dog[b]);
		dog_map[a][b] = max(dog[a], dog[b]);
		dog_map[b][a] = max(dog[a], dog[b]);
	}
	for (int k = 1; k <= n; k++) {
		int go = w[k - 1].second;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][go] >= INF) continue;
				if (arr[go][j] >= INF) continue;
				if (dist[i][j] > arr[i][go] + arr[go][j] + max(dog_map[i][go], dog_map[go][j])) {
					dist[i][j] = arr[i][go] + arr[go][j] + max(dog_map[i][go], dog_map[go][j]);
					arr[i][j] = arr[i][go] + arr[go][j];
					dog_map[i][j] = max(dog_map[i][go], dog_map[go][j]);
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (dist[a][b] >= INF) printf("%d\n", -1);
		else printf("%lld\n", dist[a][b]);
	}
	return 0;
}
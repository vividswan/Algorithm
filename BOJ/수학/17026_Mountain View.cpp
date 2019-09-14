#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int vis[100001];
int n;
vector<pair<int, int>> v;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(), greater<>());
	memset(vis, 1, sizeof(vis));
	for (int i = 0; i < v.size() - 1; i++) {
		if (!vis[i]) continue;
		for (int j = i + 1; j < v.size(); j++) {
			if (!vis[j]) continue;
			if (v[j].second < v[i].second) {
				if (v[j].first <= v[j].second - v[i].second + v[i].first) vis[j] = 0;
			}
			else {
				if (v[j].first <= v[i].first + v[i].second - v[j].second) vis[j] = 0;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) {
			res++;
		}
	}
	printf("%d\n", res);
}
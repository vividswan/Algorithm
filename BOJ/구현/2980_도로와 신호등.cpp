#include <iostream>
#include <vector>
using namespace std;
vector <pair<int, int>> adj[1001];
int n, l, sum, vis[1001];
int main(void) {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		vis[a] = 1;
	}
	for (int i = 0; i <= l; i++) {
		sum++;
		if (!vis[i]) continue;
		if (sum % (adj[i][0].first + adj[i][0].second) <= adj[i][0].first) {
			sum += adj[i][0].first - (sum % (adj[i][0].first + adj[i][0].second));
		}
	}
	printf("%d\n", sum);
}
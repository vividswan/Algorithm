#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
int vis[10000], arr[10000];
void cal(int i);
int a, b, res;
int main(void) {
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 1; i <= sqrt(9999); i++) {
		if (arr[i]) continue;
		else {
			int k = 2;
			while (1) {
				if (i * k > 9999) break;
				arr[i * k] = 1;
				k++;
			}
		}
	}
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d%d", &a, &b);
		memset(vis, 0, sizeof(vis));
		cal(a);
		if (!res) printf("Impossible\n");
		res = 0;
	}
	return 0;
}
void cal(int i) {
	queue<pair<int, int>> q;
	q.push({ i, 0 });
	vis[i] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int roof = now.second;
		int x = now.first;
		if (x == b) {
			printf("%d\n", roof);
			res++;
		}
		int a = x / 1000;
		for (int i = 1; i < 10 - a; i++) {
			int tes = x + 1000 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		for (int i = a - 1; i >= 1; i--) {
			int tes = x - 1000 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		a = (x / 100) % 10;
		for (int i = 1; i < 10 - a; i++) {
			int tes = x + 100 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		for (int i = a; i >= 1; i--) {
			int tes = x - 100 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		a = (x / 10) % 10;
		for (int i = 1; i < 10 - a; i++) {
			int tes = x + 10 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		for (int i = a; i >= 1; i--) {
			int tes = x - 10 * i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		a = x % 10;
		for (int i = 1; i < 10 - a; i++) {
			int tes = x + i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
		for (int i = a; i >= 1; i--) {
			int tes = x - i;
			if (!arr[tes]) {
				if (vis[tes]) {
					continue;
				}
				else {
					vis[tes] = 1;
					q.push({ tes, roof + 1 });
				}
			}
		}
	}
}
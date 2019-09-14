#include <iostream>
#include <deque>
#include <vector>
#include <cstring>
using namespace std;
vector<deque<int>> geer;
void go(int a, int b);
int vis[5];
int main(void) {
	geer.resize(5);
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < 8; j++) {
			int a;
			scanf("%1d", &a);
			geer[i].push_back(a);
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int num, dir;
		scanf("%d%d", &num, &dir);
		go(num, dir);
		memset(vis, 0, sizeof(vis));
	}
	int res = 0;
	for (int i = 1; i <= 4; i++) {
		if (geer[i][0]) {
			if (i == 1) res += 1;
			else if (i == 2) res += 2;
			else if (i == 3) res += 4;
			else res += 8;
		}
	}
	printf("%d\n", res);
}
void go(int a1, int b) {
	if (vis[a1]) return;
	vis[a1] = 1;
	if (a1 - 1 >= 1) {
		if (!vis[a1 - 1]) {
			if (geer[a1][6] != geer[a1 - 1][2]) {
				go(a1 - 1, -1 * b);
			}
		}
	}
	if (a1 + 1 <= 4) {
		if (!vis[a1 + 1]) {
			if (geer[a1][2] != geer[a1 + 1][6]) {
				go(a1 + 1, -1 * b);
			}
		}
	}
	if (b == 1) {
		int a = geer[a1][7];
		geer[a1].pop_back();
		geer[a1].push_front(a);
	}
	if (b == -1) {
		int a = geer[a1][0];
		geer[a1].pop_front();
		geer[a1].push_back(a);
	}
}
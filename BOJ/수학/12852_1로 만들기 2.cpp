#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int check[1000001], vis[1000001], pre[1000001], num, sch, value[1000001];
void bfs(int x);
int main(void) {
	cin >> num;
	vis[num] = 1;
	q.push(num);
	pre[num] = 1;
	bfs(num);
	printf("%d\n", check[1]);
	int k = 1;
	value[check[1] + 1] = 1;
	for (int i = check[1]; i > 0; i--) {
		value[i] = pre[k];
		k = pre[k];
	}
	for (int i = 1; i <= check[1] + 1; i++) {
		printf("%d ", value[i]);
	}
	return 0;
}
void bfs(int x) {
	while (!q.empty() && sch == 0) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				if (x % 3 == 0) {
					int nx = x / 3;
					if (vis[nx] == 0) {
						vis[nx] = 1;
						check[nx] = check[x] + 1;
						pre[nx] = x;
						if (nx == 1) {
							sch = 1;
							break;
						}
						q.push(nx);
					}
				}
			}
			if (i == 1) {
				if (x % 2 == 0) {
					int nx = x / 2;
					if (vis[nx] == 0) {
						vis[nx] = 1;
						check[nx] = check[x] + 1;
						pre[nx] = x;
						if (nx == 1) {
							sch = 1;
							break;
						}
						q.push(nx);
					}
				}
			}
			if (i == 2) {
				if (x - 1 >= 1) {
					int nx = x - 1;
					if (vis[nx] == 0) {
						vis[nx] = 1;
						check[nx] = check[x] + 1;
						pre[nx] = x;
						if (nx == 1) {
							sch = 1;
							break;
						}
						q.push(nx);
					}
				}
			}
		}
	}
}
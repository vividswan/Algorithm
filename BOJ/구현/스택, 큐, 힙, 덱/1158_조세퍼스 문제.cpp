#include <iostream>
#include <queue>
using namespace std;
int arr[5001], n, m;
queue<int> q;
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int res = 1;
	while (!q.empty()) {
		for (int i = 1; i <= m; i++) {
			if (i == m) {
				arr[res] = q.front();
				q.pop();
				res++;
			}
			else {
				int now = q.front();
				q.pop();
				q.push(now);
			}
		}
	}
	printf("<");
	for (int i = 1; i <= n - 1; i++) {
		printf("%d, ", arr[i]);
	}
	printf("%d>", arr[n]);
}
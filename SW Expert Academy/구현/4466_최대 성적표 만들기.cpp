#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n, k;
		scanf("%d%d", &n, &k);
		priority_queue<int, vector<int>> pq;
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			pq.push(a);
		}
		int sum = 0;
		for (int i = 1; i <= k; i++) {
			sum += pq.top();
			pq.pop();
		}
		printf("#%d %d\n", i, sum);
	}
	return 0;
}
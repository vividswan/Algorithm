#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, now_num;
priority_queue<int, vector<int>> pq;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		pq.push(a);
	}
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		if (now >= now_num) {
			now_num++;
		}
	}
	printf("%d\n", now_num);
}
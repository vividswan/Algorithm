#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int sum;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int idx, val;
		scanf("%d%d", &idx, &val);
		pq.push({ idx,val });
	}
	sum = pq.top().first + pq.top().second;
	pq.pop();
	for (int i = 1; i <= n - 1; i++) {
		if (sum < pq.top().first) sum = pq.top().first + pq.top().second;
		else sum += pq.top().second;
		pq.pop();
	}
	printf("%d\n", sum);
	return 0;
}
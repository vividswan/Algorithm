#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
	int n;
	scanf("%d", &n);
	priority_queue<int, vector<int>, greater<>>pq;
	while (n--) {
		int value;
		scanf("%d", &value);
		pq.push(value);
	}
	int sum = 0;
	if (pq.top() != 1) {
		printf("%d\n", 1);
		return 0;
	}
	else {
		sum = 1;
		pq.pop();
	}
	while (!pq.empty()) {
		if (pq.top() > sum + 1) {
			break;
		}
		sum += pq.top();
		pq.pop();
	}
	printf("%d\n", sum+1);
	return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<>> top_q;
priority_queue<int, vector<int>> down;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		if (down.empty()) down.push(val);
		else {
			if (down.top() >= val) down.push(val);
			else top_q.push(val);
		}
		if (i % 2) {
			if (down.size() < top_q.size()) {
				down.push(top_q.top());
				top_q.pop();
			}
		}
		else if (i % 2 == 0) {
			if (down.size() < top_q.size()) {
				down.push(top_q.top());
				top_q.pop();
			}
			else if (down.size() > top_q.size()) {
				top_q.push(down.top());
				down.pop();
			}
		}
		printf("%d\n", down.top());
	}
	return 0;
}
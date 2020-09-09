#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(void) {
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt = 1;
	while (q.size() > 1) {
		if (cnt == K) {
			cnt = 1;
			q.pop();
		}
		else {
			int now = q.front();
			q.pop();
			q.push(now);
			cnt++;
		}
	}
	cout << q.front() << '\n';
	return 0;
}
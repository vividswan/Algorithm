#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 0; i < N; i++) q.push(i + 1);
	int cnt = 0;
	int last;
	while (!q.empty())
	{
		cnt++;
		int now = q.front();
		q.pop();
		if (cnt == K) {
			cnt = 0;
			last = now;
		}
		else q.push(now);
	}
	cout << last << '\n';
	return 0;
}
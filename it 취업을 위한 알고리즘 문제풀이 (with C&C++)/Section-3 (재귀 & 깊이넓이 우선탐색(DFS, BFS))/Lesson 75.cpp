#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int maxDay = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		int val, day;
		cin >> val >> day;
		maxDay = max(day, maxDay);
		v.push_back({ -day,val });
	}
	sort(v.begin(), v.end());
	int result = 0;
	priority_queue<int, vector<int>> pq;
	int idx = 0;
	for (int i = maxDay; i > 0; i--) {
		while (true) {
			if (idx == v.size()) break;
			if (-1 * v[idx].first == i) {
				pq.push(v[idx].second);
				idx++;
			}
			else break;
		}
		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << '\n';
	return 0;
}
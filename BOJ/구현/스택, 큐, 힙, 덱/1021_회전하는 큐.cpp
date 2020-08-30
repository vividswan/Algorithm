#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	deque<int> d;
	for (int i = 1; i <= N; i++) d.push_back(i);
	int result = 0;
	for (int i = 0; i < M; i++) {
		int now;
		cin >> now;
		int idx = 0;
		for (int i = 0; i < d.size(); i++) {
			if (now == d[i]) {
				idx = i + 1;
				break;
			}
		}
		if (idx-1 < d.size() - idx+1) {
			result += idx - 1;
			for (int i = 1; i < idx; i++) {
				int val = d.front();
				d.push_back(val);
				d.pop_front();
			}
			d.pop_front();
		}
		else {
			result += d.size() - idx+1;
			for (int i = 1; i <= d.size() - idx; i++) {
				int val = d.back();
				d.push_front(val);
				d.pop_back();
			}
			d.pop_back();
		}
	}
	cout << result << '\n';
	return 0;
}
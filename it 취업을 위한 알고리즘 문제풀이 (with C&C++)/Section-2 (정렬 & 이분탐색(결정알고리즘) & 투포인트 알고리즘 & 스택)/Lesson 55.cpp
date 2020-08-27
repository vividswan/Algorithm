#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int work = 1;
	stack<int> s;
	queue<char> q;
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		while (!s.empty()) {
			if (s.top() == work) {
				q.push('O');
				s.pop();
				work++;
			}
			else break;
		}
		if (now == work) {
			work++;
			q.push('P');
			q.push('O');
		}
		else {
			s.push(now);
			q.push('P');
		}
	}
	while (!s.empty()) {
		if (s.top() == work) {
			q.push('O');
			s.pop();
			work++;
		}
		else break;
	}
	if (work - 1 == N) {
		while (!q.empty()) {
			cout << q.front();
			q.pop();
		}
		cout << '\n';
	}
	else cout << "impossible\n";
	return 0;
}
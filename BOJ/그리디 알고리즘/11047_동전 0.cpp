#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	int result = 0;
	int N, K;
	stack<int> s;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		s.push(value);
	}
	while (!s.empty()) {
		int now = s.top();
		s.pop();
		if (now > K) continue;
		result += K / now;
		K = K % now;
	}
	cout << result << '\n';
	return 0;
}
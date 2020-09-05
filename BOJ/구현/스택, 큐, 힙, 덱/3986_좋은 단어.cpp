#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int result = 0;
	for (int i = 0; i < N; i++) {
		char str[100001];
		cin >> str;
		stack<char> s;
		for (int i = 0; str[i] != '\0'; i++) {
			if (s.empty()) {
				s.push(str[i]);
			}
			else if (s.top()==str[i]) {
				s.pop();
			}
			else {
				s.push(str[i]);
			}
		}
		if (s.empty()) result++;
	}
	cout << result << '\n';
	return 0;
}
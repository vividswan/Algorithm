#include <iostream>
#include <stack>
using namespace std;
int sum();
stack<char> s;
int main(void) {
	int result = 0;
	char str[9];
	cin >> str;
	int swc = -1;
	for (int i = 1; str[i] != '\0'; i++) {
		if (str[i] == 'H') {
			result += sum()*12;
		}
		else {
			s.push(str[i]);
		}
	}
	result += sum();
	cout << result << '\n';
	return 0;
}
int sum() {
	if (s.empty()) {
		return 1;
	}
	int result = 0;
	int digit = 1;
	while (!s.empty()) {
		char now = s.top();
		s.pop();
		result += (now-'0') * digit;
		digit *= 10;
	}
	return result;
}
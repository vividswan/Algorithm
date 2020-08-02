#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	char str[31];
	stack<char> s;
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') s.push('(');
		else {
			if (s.size() == 0) {
				cout << "NO\n";
				return 0;
			}
			s.pop();
		}
	}
	if (s.size()) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}
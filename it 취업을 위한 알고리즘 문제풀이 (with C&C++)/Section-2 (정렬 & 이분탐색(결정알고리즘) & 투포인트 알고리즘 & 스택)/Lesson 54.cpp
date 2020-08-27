#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	stack<char> s;
	char str[31];
	cin >> str;
	bool swc = false;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') s.push('(');
		else {
			if (s.empty()) {
				swc = true;
				break;
			}
			else s.pop();
		}
	}
	if (!swc && s.empty()) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
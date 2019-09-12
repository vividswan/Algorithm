#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
char str[100001];
char ans[600001];
stack<char> f;
stack<char> b;
int n;
int main(void) {
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len; i++) f.push(str[i]);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		if (a == 'L') {
			if (f.empty()) continue;
			b.push(f.top());
			f.pop();
		}
		if (a == 'D') {
			if (b.empty()) continue;
			f.push(b.top());
			b.pop();
		}
		if (a == 'B') {
			if (f.empty()) continue;
			f.pop();
		}
		else if (a == 'P') {
			char b;
			cin >> b;
			f.push(b);
		}
	}
	while (!f.empty()) {
		b.push(f.top());
		f.pop();
	}
	while (!b.empty()) {
		printf("%c", b.top());
		b.pop();
	}
	return 0;
}
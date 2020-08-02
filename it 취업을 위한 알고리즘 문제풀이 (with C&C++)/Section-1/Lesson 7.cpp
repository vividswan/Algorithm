#include <iostream>
#include <queue>
using namespace std;
int main(void) {
	queue<char> q;
	char str[101];
	gets_s(str);
	for (int i = 0; i < str[i] != '\0'; i++) {
		if (str[i] == ' ') continue;
		if ('a' <= str[i] && str[i] <= 'z') q.push(str[i]);
		else {
			char now = str[i] - 'A' + 'a';
			q.push(now);
		}
	}
	while (!q.empty()) {
		cout << q.front();
		q.pop();
	}
	cout << '\n';
	return 0;
}
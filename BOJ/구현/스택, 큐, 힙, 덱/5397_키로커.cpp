#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
int main(void) {
	int roof;
	cin >> roof;
	getchar();
	for (int i = 1; i <= roof; i++) {
		string str;
		cin >> str;
		stack<char> s;
		stack<char> q;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '<') {
				if (s.empty()) continue;
				else {
					char now = s.top();
					s.pop();
					q.push(now);
				}
			}
			else if (str[j] == '>') {
				if (q.empty()) continue;
				else {
					char now = q.top();
					q.pop();
					s.push(now);
				}
			}
			else if (str[j] == '-') {
				if (s.empty()) continue;
				else s.pop();
			}
			else s.push(str[j]);
		}
		while (!q.empty()) {
			char now = q.top();
			s.push(now);
			q.pop();
		}
		string go;
		while (!s.empty())
		{
			go += s.top();
			s.pop();
		}
		reverse(go.begin(), go.end());
		cout << go << "\n";
	}
	return 0;
}
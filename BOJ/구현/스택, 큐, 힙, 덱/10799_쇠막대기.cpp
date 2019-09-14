#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack <char> s;
char str[100001];
int main(void) {
	cin.getline(str, 100001);
	int len = strlen(str);
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') s.push(str[i]);
		else {
			if (!s.empty()) {
				if (str[i - 1] == '(') {
					s.pop();
					cnt += s.size();
				}
				else {
					s.pop();
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
}
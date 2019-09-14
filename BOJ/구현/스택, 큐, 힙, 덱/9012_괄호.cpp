#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		stack<char> s;
		char str[51];
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++) {
			s.push(str[i]);
		}
		int cnt = 0;
		int swc = 0;
		while (!s.empty()) {
			int now = s.top();
			s.pop();
			if (now == ')') cnt++;
			else cnt--;
			if (cnt < 0) {
				swc++;
				break;
			}
		}
		if (!cnt && !swc) printf("YES\n");
		else printf("NO\n");
	}
}
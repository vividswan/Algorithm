#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> q;
stack<int> s;
int result;
int main(void) {
	while (true) {
		char bowl;
		scanf("%c", &bowl);
		if (bowl == '\n') break;
		q.push(bowl);
	}
	while (!q.empty()) {
		char now = q.front();
		q.pop();
		if (s.empty()) {
			s.push(now);
			result += 10;
		}
		else {
			if (now == s.top()) result += 5;
			else result += 10;
			s.push(now);
		}
	}
	printf("%d\n", result);
	return 0;
}
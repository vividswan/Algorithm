#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue<int> q2;
priority_queue<int, vector<int>, greater<int>> q1;
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		int num;
		scanf("%d", &num);
		if (num > 0) q1.push(num);
		else if (num < 0) q2.push(num);
		else if (num == 0) {
			if (q1.empty() == 1 && q2.empty() == 1) {
				printf("0\n");
			}
			else if (q1.empty()) {
				printf("%d\n", q2.top());
				q2.pop();
			}
			else if (q2.empty()) {
				printf("%d\n", q1.top());
				q1.pop();
			}
			else {
				if (q1.top() == -q2.top()) {
					printf("%d\n", q2.top());
					q2.pop();
				}
				else if (q1.top() < -q2.top()) {
					printf("%d\n", q1.top());
					q1.pop();
				}
				else if (q1.top() > -q2.top()) {
					printf("%d\n", q2.top());
					q2.pop();
				}
			}
		}
	}
}
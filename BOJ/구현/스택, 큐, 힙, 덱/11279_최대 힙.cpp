#include <iostream>
#include <queue>
#include <functional>
using namespace std;
priority_queue <int> q;
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		int num;
		scanf("%d", &num);
		if (num > 0) q.push(num);
		else if (num == 0) {
			if (!q.empty()) {
				int l = q.top();
				printf("%d\n", l);
				q.pop();
			}
			else printf("0\n");
		}
	}
}
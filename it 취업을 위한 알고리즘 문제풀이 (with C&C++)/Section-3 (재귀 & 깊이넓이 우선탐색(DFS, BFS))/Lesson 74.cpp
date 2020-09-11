#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>,greater<>> pq;
int main(void) {
	while (true) {
		int num;
		cin >> num;
		if (num == -1) break;
		else if (num == 0) {
			if (pq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue <int>q;
int main(void) {
	int nm;
	cin >> nm;
	for (int i = 1; i <= nm; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
}
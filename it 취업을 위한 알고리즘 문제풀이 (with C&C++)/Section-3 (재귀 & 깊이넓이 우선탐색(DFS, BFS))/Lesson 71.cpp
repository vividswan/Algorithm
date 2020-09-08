#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> map;
int main(void) {
	int now, fin;
	cin >> now >> fin;
	map.resize(10000 + 1);
	for (int i = 1; i <= 10000; i++) map[i] = -1;
	map[now] = 0;
	queue<int> q;
	q.push(now);
	while (map[fin] == -1) {
		int now = q.front();
		q.pop();
		if (now >= 1) {
			if (map[now - 1] == -1) {
				map[now - 1] = map[now] + 1;
				q.push(now - 1);
			}
		}
		if (now <= 10000 -1) {
			if (map[now + 1] == -1) {
				map[now + 1] = map[now] + 1;
				q.push(now + 1);
			}
		}
		if (now + 5 <= 10000) {
			if (map[now + 5] == -1) {
				map[now + 5] = map[now] + 1;
				q.push(now + 5);
			}
		}
	}
	cout << map[fin] << '\n';
	return 0;
}
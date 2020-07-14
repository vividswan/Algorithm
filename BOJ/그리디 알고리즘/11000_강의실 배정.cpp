#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
priority_queue<int, vector<int>, greater<>> room;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int startTime, endTime;
		cin >> startTime >> endTime;
		pq.push({ startTime,endTime });
	}
	while (!pq.empty()) {
		int nowStartTime = pq.top().first;
		int nowEndTime = pq.top().second;
		pq.pop();
		if (room.empty()) {
			room.push(nowEndTime);
		}
		else if (room.top() > nowStartTime) {
			room.push(nowEndTime);
		}
		else {
			room.pop();
			room.push(nowEndTime);
		}
	}
	cout << room.size() << "\n";
}
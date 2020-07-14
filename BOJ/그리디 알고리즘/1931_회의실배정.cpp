#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, result, beforeStartTime, beforeEndTime;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int startTime, endTime;
		cin >> startTime >> endTime;
		pq.push({ endTime,startTime });
	}
	while (!pq.empty()) {
		int nowEndTime = pq.top().first;
		int nowStartTime = pq.top().second;
		pq.pop();
		if (beforeEndTime > nowStartTime) continue;
		if (nowEndTime == nowStartTime) {
			result++;
			beforeStartTime = nowStartTime;
			beforeEndTime = nowEndTime;
			continue;
		}
		result++;
		beforeStartTime = nowStartTime;
		beforeEndTime = nowEndTime;
	}
	cout << result << '\n';
}
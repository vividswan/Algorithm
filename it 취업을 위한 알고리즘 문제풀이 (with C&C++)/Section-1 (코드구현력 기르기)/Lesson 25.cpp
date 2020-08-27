#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int, vector<int>> pq;
int main(void) {
	int N;
	int cnt = 1;
	int numbering = 1;
	cin >> N;
	int arr[101];
	int number[101];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		pq.push(arr[i]);
	}
	int value = pq.top();
	pq.pop();
	number[value] = 1;
	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		if (value == now) {
			cnt++;
			continue;
		}
		else {
			numbering += cnt;
			cnt = 1;
			value = now;
			number[value] = numbering;
		}
	}
	for (int i = 0; i < N; i++) cout << number[arr[i]] << ' ';
	return 0;
}
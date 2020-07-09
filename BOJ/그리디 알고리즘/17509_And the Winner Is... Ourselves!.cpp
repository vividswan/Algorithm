#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(void) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
	for (int i = 0; i < 11; i++) {
		int D, V;
		cin >> D >> V;
		pq.push({ D,V });
	}
	int total = 0;
	int Dsum = 0;
	while (!pq.empty()) {
		int nowD = pq.top().first;
		int nowV = pq.top().second;
		pq.pop();
		Dsum += nowD;
		total += Dsum + 20 * nowV;
	}
	cout << total << '\n';
	return 0;
}
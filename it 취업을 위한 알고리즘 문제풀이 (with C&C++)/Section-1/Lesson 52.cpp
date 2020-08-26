#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<long long> arr(N + 1);
	int idx = 2;
	int ptrTwo, ptrThree, ptrFive;
	ptrTwo = ptrThree = ptrFive = 1;
	arr[1] = 1;
	while (idx <= N) {
		long long ptrTwoValue = arr[ptrTwo] * 2;
		long long ptrThreeValue = arr[ptrThree] * 3;
		long long ptrFiveValue = arr[ptrFive] * 5;
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
		pq.push({ ptrTwoValue,2 });
		pq.push({ ptrFiveValue,5 });
		pq.push({ ptrThreeValue,3 });
		long long nowMin = pq.top().first;
		arr[idx] = pq.top().first;
		if (pq.top().second == 2) ptrTwo++;
		else if (pq.top().second == 3) ptrThree++;
		else ptrFive++;
		pq.pop();
		while (!pq.empty()) {
			if (nowMin == pq.top().first) {
				if (pq.top().second == 2) ptrTwo++;
				else if (pq.top().second == 3) ptrThree++;
				else ptrFive++;
				pq.pop();
			}
			else break;
		}

		idx++;
	}
	cout << arr[N] << '\n';
	return 0;
}
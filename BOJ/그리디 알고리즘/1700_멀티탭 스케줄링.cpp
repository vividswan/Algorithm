#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
pair<int,int> arr[101];
int usedNum[101];
bool chk[101];
int val[101];
bool visNum[101];
int arrValue[101];
int main(void) {
	int cnt = 0;
	int N, K, result=0;
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		cin >> val[i];
	}
	for (int i = K - 1; i >= 0; i--) {
		int now = val[i];
		if (visNum[now] == false) {
			visNum[now] = true;
			arr[i].first = now;
			arr[i].second = 201;
		}
		else {
			arr[i].first = now;
			arr[i].second = usedNum[now];
		}
		usedNum[now] = i;
	}
	memset(arrValue, -1, sizeof(arrValue));
	for (int i = 0; i < K; i++) {
		if (chk[arr[i].first]) {
			arrValue[arr[i].first] = arr[i].second;
			continue;
		}
		if (cnt < N) {
			chk[arr[i].first] = true;
			arrValue[arr[i].first] = arr[i].second;
			cnt++;
		}
		else {
			int maxNum;
			int maxVal = -1;
			for (int i = 1; i <= K; i++) {
				if (chk[i] == false) continue;
				if (maxVal < arrValue[i]) {
					maxNum = i;
					maxVal = arrValue[i];
				}
			}
			chk[maxNum] = false;
			chk[arr[i].first] = true;
			arrValue[arr[i].first] = arr[i].second;
			result++;
		}
	}
	cout << result << '\n';
	return 0;
}
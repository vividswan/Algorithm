#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, value[100002], area;
int printArea(int funcLeft, int funcRight);
void recursion(int le, int ri);
int main(void) {
	memset(value, -1, sizeof(value));
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
	recursion(1, N);
	cout << area << '\n';
	return 0;
}
void recursion(int le, int ri) {
	if (le == ri) {
		area = max(area, value[le]);
		return;
	}
	area = max(area, printArea(le, ri));
	int mid = (le+ri)/2;
	if ((ri - le) == 1) {
		area = max(area, value[ri]);
		return;
	}
	recursion(le, mid);
	recursion(mid, ri);
}
int printArea(int funcLeft, int funcRight) {
	int returnArea = 0;
	int cnt = 1;
	int mid = (funcRight + funcLeft) / 2;
	int le = mid;
	int ri = mid;
	int nowHeight = value[mid];
	bool endLe = false;
	bool endRi = false;
	while (true) {
		if (le <= funcLeft && ri >= funcRight) break;
		if (le == funcLeft) endLe = true;
		if (ri >= funcRight) endRi = true;
		cnt++;
		int nowArea;
		if (endLe) {
			ri++;
			nowHeight = min(value[ri], nowHeight);
		}
		else if (endRi) {
			le--;
			nowHeight = min(value[le], nowHeight);
		}
		else if ((value[le - 1] >= value[ri + 1]) && !endLe) {
			le--;
			nowHeight = min(value[le], nowHeight);
		}
		else {
			ri++;
			nowHeight = min(value[ri], nowHeight);
		}
		nowArea = cnt * nowHeight;
		returnArea = max(returnArea, nowArea);
	}
	return returnArea;
}
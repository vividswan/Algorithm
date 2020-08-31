#include<iostream>
#include<deque>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	deque<pair<int, int>> d;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		d.push_back({ i + 1,num });
	}
	while (!d.empty()) {
		int now = d.front().first;
		int value = d.front().second;
		d.pop_front();
		cout << now << ' ';
		if (d.empty()) break;
		if (value > 0) {
			while (value!=1) {
				d.push_back(d.front());
				d.pop_front();
				value--;
			}
		}
		else {
			while (value++) {
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
	cout << '\n';
	return 0;
}
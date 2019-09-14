#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int main(void) {
	int n;
	long long n_atk;
	vector<vector<pair<int, pair<long long, long long>>>> room;
	cin >> n >> n_atk;
	room.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		room[i].push_back({ a,{b,c} });
	}
	long long left = 1;
	long long right = LLONG_MAX - 1000000 - 1;
	long long mid;
	long long res;
	while (left <= right) {
		int swc = 0;
		long long now_atk = n_atk;
		mid = (left + right) / 2;
		long long now_hp = mid;
		for (int i = 1; i <= n; i++) {
			if (room[i][0].first == 2) {
				now_atk += room[i][0].second.first;
				if (mid < now_hp + room[i][0].second.second) now_hp = mid;
				else now_hp += room[i][0].second.second;
			}
			else {
				long long cnt;
				if (!(room[i][0].second.second % now_atk)) cnt = (room[i][0].second.second / now_atk) - 1;
				else cnt = (room[i][0].second.second / now_atk);
				if (now_hp <= room[i][0].second.first * cnt) {
					swc++;
					break;
				}
				else now_hp -= room[i][0].second.first * cnt;
			}
		}
		if (swc) left = mid + 1;
		else right = mid - 1;
	}
	printf("%lld\n", left);
}
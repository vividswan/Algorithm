#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e;
int result;
vector<bool> chk;
vector <vector<pair<int, int>>> map;
priority_queue<pair<int,int>,vector<pair<int, int>>,greater<>> pq;
int main(void) {
	cin >> v >> e;
	chk.resize(v + 1);
	map.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		map[st].push_back({ val,ed });
		map[ed].push_back({ val,st });
	}
	chk[1] = true;
	for (int i = 0; i < map[1].size(); i++) pq.push({ map[1][i].first,map[1][i].second });
	while (!pq.empty()) {
		int next = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		if (chk[next]) continue;
		chk[next] = true;
		result += val;
		for (int i = 0; i < map[next].size(); i++) {
			pq.push({ map[next][i].first,map[next][i].second });
		}
	}
	cout << result << '\n';
	return 0;
}
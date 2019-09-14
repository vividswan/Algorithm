#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
string dx[] = { "*","+","-","/" };
set<long long> s;
long long st, ed;
string bfs(long long now, string res);
int main(void) {
	scanf("%lld %lld", &st, &ed);
	if (st == ed) {
		printf("%d\n", 0);
		return 0;
	}
	string ed = bfs(st, "");
	if (ed == "a") printf("-1\n");
	else cout << ed << "\n";
}
string bfs(long long now, string res) {
	queue<pair<long long, string>> q;
	q.push({ now,res });
	s.insert(now);
	while (!q.empty()) {
		long long x = q.front().first;
		string go_res = q.front().second;
		if (x == ed) return go_res;
		q.pop();
		long long nx;
		for (int i = 0; i < 4; i++) {
			if (i == 0) nx = x * x;
			else if (i == 1) nx = 2 * x;
			else if (i == 2) nx = 0;
			else nx = 1;
			if (nx < 1) continue;
			if (s.find(nx) != s.end()) continue;
			s.insert(nx);
			q.push({ nx,go_res + dx[i] });
		}
	}
	return "a";
}